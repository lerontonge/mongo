/**
 *    Copyright (C) 2025-present MongoDB, Inc.
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

#include "mongo/db/exec/agg/group_base_stage.h"

namespace mongo {
namespace exec {
namespace agg {

class StreamingGroupStage final : public mongo::exec::agg::GroupBaseStage {

public:
    StreamingGroupStage(StringData stageName,
                        const boost::intrusive_ptr<ExpressionContext>& pExpCtx,
                        const std::shared_ptr<GroupProcessor>& groupProcessor,
                        const std::vector<size_t>& monotonicExpressionIndexes);

private:
    GetNextResult doGetNext() final;

    GetNextResult getNextDocument();

    GetNextResult readyNextBatch();
    /**
     * Readies next batch after all children are initialized. See readyNextBatch() for
     * more details.
     */
    GetNextResult readyNextBatchInner(GetNextResult input);

    template <typename IdValueGetter>
    bool checkForBatchEndAndUpdateLastIdValues(const IdValueGetter& idValueGetter);

    bool isBatchFinished(const Value& id);

    std::vector<Value> _lastMonotonicIdFieldValues;

    boost::optional<Document> _firstDocumentOfNextBatch;

    bool _sourceDepleted;

    std::vector<size_t> _monotonicExpressionIndexes;
};

}  // namespace agg
}  // namespace exec
}  // namespace mongo
