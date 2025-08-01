/**
 *    Copyright (C) 2018-present MongoDB, Inc.
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


#include "mongo/base/status.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/db/matcher/expression.h"
#include "mongo/db/matcher/extensions_callback.h"
#include "mongo/db/matcher/extensions_callback_noop.h"
#include "mongo/db/pipeline/expression_context.h"
#include "mongo/db/query/compiler/parsers/matcher/expression_parser.h"

#include <memory>
#include <string>

#include <boost/smart_ptr/intrusive_ptr.hpp>


namespace mongo {

class CollatorInterface;

/**
 * Matcher is a simple wrapper around a BSONObj and the MatchExpression created from it.
 */
class Matcher {
    Matcher(const Matcher&) = delete;
    Matcher& operator=(const Matcher&) = delete;

public:
    /**
     * 'collator' must outlive the returned Matcher and any MatchExpression cloned from it.
     */
    Matcher(const BSONObj& pattern,
            const boost::intrusive_ptr<ExpressionContext>& expCtx,
            const ExtensionsCallback& extensionsCallback = ExtensionsCallbackNoop(),
            MatchExpressionParser::AllowedFeatureSet allowedFeatures =
                MatchExpressionParser::kDefaultSpecialFeatures);

    const BSONObj* getQuery() const {
        return &_pattern;
    }

    std::string toString() const {
        return _pattern.toString();
    }

    MatchExpression* getMatchExpression() {
        return _expression.get();
    }

    const MatchExpression* getMatchExpression() const {
        return _expression.get();
    }

private:
    BSONObj _pattern;

    std::unique_ptr<MatchExpression> _expression;
};

}  // namespace mongo
