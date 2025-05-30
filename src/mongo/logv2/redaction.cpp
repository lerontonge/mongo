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


#include "mongo/logv2/redaction.h"

#include "mongo/base/error_codes.h"
#include "mongo/base/status.h"
#include "mongo/bson/bsonobj.h"
#include "mongo/bson/util/builder.h"
#include "mongo/bson/util/builder_fwd.h"
#include "mongo/logv2/log_util.h"
#include "mongo/util/assert_util.h"

#include <ostream>

#define MONGO_LOGV2_DEFAULT_COMPONENT ::mongo::logv2::LogComponent::kDefault


namespace mongo {

namespace {

constexpr auto kRedactionDefaultMask = "###"_sd;

}  // namespace

BSONObj redact(const BSONObj& objectToRedact) {
    if (!logv2::shouldRedactLogs()) {
        if (!logv2::shouldRedactBinDataEncrypt()) {
            return objectToRedact.redact(BSONObj::RedactLevel::sensitiveOnly);
        }
        return objectToRedact.redact(BSONObj::RedactLevel::encryptedAndSensitive);
    }

    return objectToRedact.redact(BSONObj::RedactLevel::all);
}

StringData redact(StringData stringToRedact) {
    if (!logv2::shouldRedactLogs()) {
        return stringToRedact;
    }

    // Return the default mask.
    return kRedactionDefaultMask;
}

std::string redact(const Status& statusToRedact) {
    if (!logv2::shouldRedactLogs()) {
        return statusToRedact.toString();
    }

    // Construct a status representation without the reason()
    StringBuilder sb;
    sb << statusToRedact.codeString();
    if (!statusToRedact.isOK())
        sb << ": " << kRedactionDefaultMask;
    return sb.str();
}

std::string redact(const DBException& exceptionToRedact) {
    if (!logv2::shouldRedactLogs()) {
        return exceptionToRedact.toString();
    }

    // Construct an exception representation with the what()
    std::stringstream ss;
    ss << exceptionToRedact.code() << " " << kRedactionDefaultMask;
    return ss.str();
}

}  // namespace mongo
