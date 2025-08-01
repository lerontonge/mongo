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

#include "mongo/crypto/fle_crypto.h"
#include "mongo/crypto/fle_crypto_types.h"
#include "mongo/crypto/fle_field_schema_gen.h"
#include "mongo/db/matcher/expression.h"
#include "mongo/db/pipeline/expression.h"
#include "mongo/db/query/fle/encrypted_predicate.h"
#include "mongo/db/query/fle/query_rewriter_interface.h"

#include <memory>
#include <utility>
#include <vector>

#include <boost/optional/optional.hpp>

namespace mongo::fle {
/**
 * Server-side rewrite used for classes that are derived from ExpressionEncTextSearch.
 */
class TextSearchPredicate : public EncryptedPredicate {
public:
    TextSearchPredicate(const QueryRewriterInterface* rewriter) : EncryptedPredicate(rewriter) {}

    /**
     * Encrypted text search predicates may exhibit poor performance when they generate an
     * aggregation expression tag disjunction, because the query optimization rewrite relies on a
     * residual filter which has an added cost that does not perform well at scale. For this reason,
     * we provide this method to allow for ExpressionEncTextSearch to generate a match style tag
     * disjunction instead.
     */
    std::unique_ptr<MatchExpression> rewriteToTagDisjunctionAsMatch(
        const ExpressionEncTextSearch& expr) const;

    bool hasValidPayload(const ExpressionEncTextSearch& expr) const;

protected:
    std::vector<PrfBlock> generateTags(BSONValue payload) const override;

    std::unique_ptr<Expression> rewriteToTagDisjunction(Expression* expr) const override;
    std::unique_ptr<MatchExpression> rewriteToTagDisjunction(MatchExpression* expr) const override;

    std::unique_ptr<Expression> rewriteToRuntimeComparison(Expression* expr) const override;
    std::unique_ptr<MatchExpression> rewriteToRuntimeComparison(
        MatchExpression* expr) const override;

private:
    EncryptedBinDataType encryptedBinDataType() const override {
        return EncryptedBinDataType::kFLE2FindTextPayload;
    }

    std::unique_ptr<MatchExpression> _rewriteToTagDisjunctionAsMatch(
        const ExpressionEncTextSearch& expr) const;
};

}  // namespace mongo::fle
