/*
//  normalization_props.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 04. 18:50
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/normalization_props.h>

#include "ucd/normalization_props.h"

namespace seshat {
namespace unicode {

bool comp_ex(CodePoint cp)
{
    auto found = ucd::comp_ex_table.find(CodePointRange(cp, cp));
    if (found != ucd::comp_ex_table.end()) {
        return found->second;
    } else {
        return false;
    }
}

QcValue nfd_qc(CodePoint cp)
{
    auto found = ucd::nfd_qc_table.find(CodePointRange(cp, cp));
    if (found != ucd::nfd_qc_table.end()) {
        return found->second;
    } else {
        return QcValue::Yes;
    }
}

QcValue nfd_qc(const CodePointSequence& seq)
{
    for (auto cp: seq) {
        if (nfd_qc(cp.code()) == QcValue::No) {
            return QcValue::No;
        }
    }
    return QcValue::Yes;
}

QcValue nfc_qc(CodePoint cp)
{
    auto found = ucd::nfc_qc_table.find(CodePointRange(cp, cp));
    if (found != ucd::nfc_qc_table.end()) {
        return found->second;
    } else {
        return QcValue::Yes;
    }
}

QcValue nfkd_qc(CodePoint cp)
{
    auto found = ucd::nfkd_qc_table.find(CodePointRange(cp, cp));
    if (found != ucd::nfkd_qc_table.end()) {
        return found->second;
    } else {
        return QcValue::Yes;
    }
}

QcValue nfkd_qc(const CodePointSequence& seq)
{
    for (auto cp: seq) {
        if (nfkd_qc(cp.code()) == QcValue::No) {
            return QcValue::No;
        }
    }
    return QcValue::Yes;
}

QcValue nfkc_qc(CodePoint cp)
{
    auto found = ucd::nfkc_qc_table.find(CodePointRange(cp, cp));
    if (found != ucd::nfkc_qc_table.end()) {
        return found->second;
    } else {
        return QcValue::Yes;
    }
}

} // namespace unicode
} // namespace seshat
