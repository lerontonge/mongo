/**
 *    Copyright (C) 2021-present MongoDB, Inc.
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the Server Side Public License, version 1,
 *    as published by MongoDB, Inc.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    Server Side Public License for more details.
 *
 *    You should have received a copy of the Server Side Public License
 *    along with this program. If not, see
 *    <http://www.mongodb.com/licensing/server-side-public-license>.
 *
 *    As a special exception, the copyright holders give permission to link the
 *    code of portions of this program with the OpenSSL library under certain
 *    conditions as described in each individual source file and distribute
 *    linked combinations including the program with the OpenSSL library. You
 *    must comply with the Server Side Public License in all respects for
 *    all of the code used other than as permitted herein. If you modify file(s)
 *    with this exception, you may extend this exception to your version of the
 *    file(s), but you are not obligated to do so. If you do not wish to do so,
 *    delete this exception statement from your version. If you delete this
 *    exception statement from all source files in the program, then also delete
 *    it in the license file.
 */

#pragma once

#include <absl/numeric/int128.h>
#include <array>
#include <boost/move/utility_core.hpp>
#include <boost/optional/optional.hpp>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <vector>

namespace mongo {
/**
 * Concept for writing 64bit simple8b blocks via a callback.
 */
template <class F>
concept Simple8bBlockWriter =
    requires(F&& f) { std::invoke(std::forward<F>(f), std::declval<uint64_t>()); };

/**
 * Simple8bBuilder compresses a series of integers into chains of 64 bit Simple8b blocks.
 *
 * T may be uint64_t and uint128_t only.
 */
template <typename T, class Allocator = std::allocator<void>>
class Simple8bBuilder {
private:
    struct PendingValue;
    using PendingValueAllocator =
        typename std::allocator_traits<Allocator>::template rebind_alloc<PendingValue>;

public:
    // Callback to handle writing of finalized Simple-8b blocks. Machine Endian byte order, the
    // value need to be converted to Little Endian before persisting.
    explicit Simple8bBuilder(Allocator = {});
    ~Simple8bBuilder();

    Simple8bBuilder(const Simple8bBuilder&) = default;
    Simple8bBuilder(Simple8bBuilder&&) = default;

    Simple8bBuilder& operator=(const Simple8bBuilder&) = default;
    Simple8bBuilder& operator=(Simple8bBuilder&&) = default;

    /**
     * Appends a multiple missing value to Simple8b.  Should be called before any other values are
     * appended.  This is intended to be used to initialize a new builder with a large series of
     * skips.
     */
    template <class F>
    requires Simple8bBlockWriter<F>
    void prefillWithSkips(size_t numSkips, F&& writeFn);

    /**
     * Appends val to Simple8b. Returns true if the append was successful and false if the value was
     * outside the range of possible values we can store in Simple8b.
     *
     * A call to append may result in multiple Simple8b blocks being finalized.
     */
    template <class F>
    requires Simple8bBlockWriter<F>
    bool append(T val, F&& writeFn);

    /**
     * Appends a missing value to Simple8b.
     *
     * May result in a single Simple8b being finalized.
     */
    template <class F>
    requires Simple8bBlockWriter<F>
    void skip(F&& writeFn);

    /**
     * Flushes all buffered values into finalized Simple8b blocks.
     *
     * It is allowed to continue to append values after this call.
     */
    template <class F>
    requires Simple8bBlockWriter<F>
    void flush(F&& writeFn);

    /**
     * Iterator for reading pending values in Simple8bBuilder that has not yet been written to
     * Simple-8b blocks.
     *
     * Provides bidirectional iteration
     */
    class PendingIterator {
    public:
        friend class Simple8bBuilder;
        // typedefs expected in iterators
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = ptrdiff_t;
        using value_type = boost::optional<T>;
        using pointer = const boost::optional<T>*;
        using reference = const boost::optional<T>&;

        pointer operator->() const;
        reference operator*() const;

        PendingIterator& operator++();
        PendingIterator operator++(int);

        PendingIterator& operator--();
        PendingIterator operator--(int);

        bool operator==(const PendingIterator& rhs) const;
        bool operator!=(const PendingIterator& rhs) const;

    private:
        PendingIterator(
            typename std::vector<PendingValue, PendingValueAllocator>::const_iterator beginning,
            typename std::vector<PendingValue, PendingValueAllocator>::const_iterator it,
            reference rleValue,
            uint32_t rleCount);

        typename std::vector<PendingValue, PendingValueAllocator>::const_iterator _begin;
        typename std::vector<PendingValue, PendingValueAllocator>::const_iterator _it;

        const boost::optional<T>& _rleValue;
        uint32_t _rleCount;
    };

    /**
     * Forward iterators to read pending values
     */
    PendingIterator begin() const;
    PendingIterator end() const;

    /**
     * Reverse iterators to read pending values
     */
    std::reverse_iterator<PendingIterator> rbegin() const;
    std::reverse_iterator<PendingIterator> rend() const;

    /**
     * Checks to see if RLE is possible and/or ongoing
     */
    bool rlePossible() const;

    /**
     * Forcibly set last value so future append/skip calls may use this to construct RLE. This
     * should not be called in normal operation.
     */
    void setLastForRLE(boost::optional<T> val);

    /**
     * Reset RLE state on the last value, if needed. This should not be called in normal operation.
     */
    void resetLastForRLEIfNeeded();

    /**
     * Initialize RLE state from another builder
     */
    void initializeRLEFrom(const Simple8bBuilder<T, Allocator>& other);

    /**
     * Validates that the internal state of this Simple8bBuilder is identical to the provided one.
     * This guarantees that appending more data to either of them would produce the same binary.
     */
    bool isInternalStateIdentical(const Simple8bBuilder<T, Allocator>& other) const;

private:
    // Number of different type of selectors and their extensions available
    static constexpr uint8_t kNumOfSelectorTypes = 4;

    /**
     * This stores a value that has yet to be added to the buffer. It also stores the number of bits
     * required to store the value for each selector extension type. Furthermore, it stores the
     * number of trailing zeros that would be stored if this value was stored according to the
     * respective selector type. The arrays are indexed using the same selector indexes as defined
     * in the cpp file.
     */
    struct PendingValue {

        PendingValue() = default;
        PendingValue(boost::optional<T> val,
                     std::array<uint8_t, kNumOfSelectorTypes> bitCount,
                     std::array<uint8_t, kNumOfSelectorTypes> trailingZerosCount);

        bool isSkip() const {
            return !val.has_value();
        }

        T value() const {
            return val.value();
        }

        boost::optional<T> val = T{0};
        std::array<uint8_t, kNumOfSelectorTypes> bitCount = {0, 0, 0, 0};
        // This is not the total number of trailing zeros, but the trailing zeros that will be
        // stored given the selector chosen.
        std::array<uint8_t, kNumOfSelectorTypes> trailingZerosCount = {0, 0, 0, 0};
    };

    // The min number of meaningful bits each selector can store
    static constexpr std::array<uint8_t, 4> kMinDataBits = {1, 2, 4, 4};
    /**
     * Function objects to encode Simple8b blocks for the different extension types.
     *
     * See .cpp file for more information.
     */
    struct BaseSelectorEncodeFunctor;
    struct SevenSelectorEncodeFunctor;

    template <uint8_t ExtensionType>
    struct EightSelectorEncodeFunctor;

    struct EightSelectorSmallEncodeFunctor;
    struct EightSelectorLargeEncodeFunctor;

    /**
     * Helper function to calculate PendingValue from user input. Pending value contain number of
     * significant bits and trailing zeros required to store the value in the different selector
     * types. If the value is not possible to store in a Simple8b block boost::none will be
     * returned.
     */
    static boost::optional<PendingValue> _calculatePendingValue(T val);

    /**
     * Appends a value to the Simple8b chain of words.
     * Return true if successfully appended and false otherwise.
     *
     * 'tryRle' indicates if we are allowed to put this skip in RLE count or not. Should only be set
     * to true when terminating RLE and we are flushing excess values.
     */
    template <class F>
    bool _appendValue(T value, bool tryRle, F&& writeFn);

    /**
     * Appends a skip to _pendingValues and forms a new Simple8b word if there is no space.
     *
     * 'tryRle' indicates if we are allowed to put this value in RLE count or not. Should only be
     * set to true when terminating RLE and we are flushing excess values.
     */
    template <class F>
    void _appendSkip(bool tryRle, F&& writeFn);

    /**
     * When an RLE ends because of inconsecutive values, check if there are enough
     * consecutive values for a RLE value and/or any values to be appended to _pendingValues.
     */
    template <class F>
    void _handleRleTermination(F&& writeFn);

    /**
     * Based on _rleCount, create a RLE Simple8b word if possible.
     * If _rleCount is not large enough, do nothing.
     */
    template <class F>
    void _appendRleEncoding(F&& writeFn);

    /**
     * Tests if a value would fit inside the current simple8b word using any of the selectors
     * selector. Returns true if adding the value fits in the current simple8b word and false
     * otherwise.
     */
    bool _doesIntegerFitInCurrentWord(const PendingValue& value);

    /*
     * This is a helper method for testing if a given selector will allow an integer to fit in a
     * simple8b word. Takes in a value to be stored and an extensionType representing the selector
     * compression method to check. Returns true if the word fits and updates the global
     * _lastValidExtensionType with the extensionType passed. If false, updates
     * isSelectorPossible[extensionType] to false so we do not need to recheck that extension if we
     * find a valid type and more values are added into the current word.
     */
    bool _doesIntegerFitInCurrentWordWithGivenSelectorType(const PendingValue& value,
                                                           uint8_t extensionType);

    /**
     * Encodes the largest possible simple8b word from _pendingValues without unused buckets using
     * the selector compression method passed in extensionType. Assumes is always called right after
     * _doesIntegerFitInCurrentWord fails for the first time. It removes the integers used to form
     * the simple8b word from _pendingValues permanently and updates our global state with any
     * remaining integers in _pendingValues.
     */
    int64_t _encodeLargestPossibleWord(uint8_t extensionType);

    /**
     * Takes a vector of integers to be compressed into a 64 bit word via the selector type given.
     * The values will be stored from right to left in little endian order.
     * For now, we will assume that all ints in the vector are greater or equal to zero.
     * We will also assume that the selector and all values will fit into the 64 bit word.
     * Returns the encoded Simple8b word if the inputs are valid and errCode otherwise.
     */
    template <typename Func>
    uint64_t _encode(Func func, uint8_t selectorIdx, uint8_t extensionType);

    /**
     * Updates the simple8b current state with the passed parameters. The maximum is always taken
     * between the current state and the new value passed. This is used to keep track of the size of
     * the simple8b word that we will need to encode.
     */
    void _updateSimple8bCurrentState(const PendingValue& val);

    // If RLE is ongoing, the number of consecutive repeats fo lastValueInPrevWord.
    uint32_t _rleCount = 0;
    // If RLE is ongoing, the last value in the previous Simple8b word.
    boost::optional<T> _lastValueInPrevWord{0};

    // These variables hold the max amount of bits for each value in _pendingValues. They are
    // updated whenever values are added or removed from _pendingValues to always reflect the max
    // value in the pending queue.
    std::array<uint8_t, kNumOfSelectorTypes> _currMaxBitLen = kMinDataBits;
    std::array<uint8_t, kNumOfSelectorTypes> _currTrailingZerosCount = {0, 0, 0, 0};

    // This holds the last valid selector compression method that succeded for
    // doesIntegerFitInCurrentWord and is used to designate the compression type when we need to
    // write a simple8b word to buffer.
    uint8_t _lastValidExtensionType = 0;

    // Holds whether the selector compression method is possible. This is updated in
    // doesIntegerFitInCurrentWordWithSelector to avoid unnecessary calls when a selector is already
    // invalid for the current set of words in _pendingValues.
    std::array<bool, kNumOfSelectorTypes> isSelectorPossible = {true, true, true, true};

    // This holds values that have not be encoded to the simple8b buffer, but are waiting for a full
    // simple8b word to be filled before writing to buffer.
    std::vector<PendingValue, PendingValueAllocator> _pendingValues;
};

}  // namespace mongo

#include "mongo/bson/column/simple8b_builder.inl"
