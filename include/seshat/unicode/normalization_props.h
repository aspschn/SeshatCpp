/*
//  unicode/normalization_props.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 14:59
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UNICODE_NORMALIZATION_PROPS_H
#define _UNICODE_NORMALIZATION_PROPS_H

#include <seshat/codepoint.h>

#include <cstdint>
#include <map>
#include <utility>

namespace seshat {
namespace unicode {

enum class QcValue {
    No,
    Yes,
    Maybe
};

bool comp_ex(uint32_t cp);
QcValue nfd_qc(uint32_t cp);
QcValue nfd_qc(const CodePointSequence& seq);
QcValue nfc_qc(uint32_t cp);
// QcValue nfc_qc(const CodePointSequence& seq);
QcValue nfkd_qc(uint32_t cp);
QcValue nfkd_qc(const CodePointSequence& seq);
QcValue nfkc_qc(uint32_t cp);
// QcValue nfkc_qc(const CodePointSequence& seq);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NORMALIZATION_PROPS_H */
