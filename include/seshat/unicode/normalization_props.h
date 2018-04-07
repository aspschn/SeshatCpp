//
//  unicode/normalization_props.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 14:59
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Property functions used in Normalization forms.
#ifndef _UNICODE_NORMALIZATION_PROPS_H
#define _UNICODE_NORMALIZATION_PROPS_H

#include <seshat/codepoint.h>
#include <seshat/utils.h>

#include <cstdint>
#include <map>
#include <utility>

/// \enum   QcValue
/// \brief  Quick check result values.
SESHAT_UNICODE_PROPERTY_ENUM(QcValue, uint8_t) {
// enum class QcValue {
    No,
    Yes,
    Maybe
};
SESHAT_UNICODE_PROPERTY_ENUM_END

namespace seshat {
namespace unicode {

/// \brief  Get the Unicode property Full_Composition_Exclusion (comp_ex).
bool comp_ex(CodePoint cp);

/// \brief  Get the Unicode character property NFD_QC.
QcValue nfd_qc(CodePoint cp);

/// \brief  Do NFD_QC for all code points in the sequence.
QcValue nfd_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFC_QC.
QcValue nfc_qc(CodePoint cp);

// QcValue nfc_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFKD_QC.
QcValue nfkd_qc(CodePoint cp);

/// \brief  Do NFKD_QC for all code points in the sequence.
QcValue nfkd_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFKC_QC.
QcValue nfkc_qc(CodePoint cp);

// QcValue nfkc_qc(const CodePointSequence& seq);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NORMALIZATION_PROPS_H */
