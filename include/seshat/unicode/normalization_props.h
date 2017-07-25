//
//  unicode/normalization_props.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 14:59
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Property functions used in Normalization forms.
#ifndef _UNICODE_NORMALIZATION_PROPS_H
#define _UNICODE_NORMALIZATION_PROPS_H

#include <seshat/codepoint.h>

#include <cstdint>
#include <map>
#include <utility>

namespace seshat {
namespace unicode {

/// \brief  Quick check result values.
enum class QcValue {
    No,
    Yes,
    Maybe
};

/// \brief  Get the Unicode property Full_Composition_Exclusion (comp_ex).
bool comp_ex(uint32_t cp);

/// \brief  Get the Unicode character property NFD_QC.
QcValue nfd_qc(uint32_t cp);

/// \brief  Do NFD_QC for all code points in the sequence.
QcValue nfd_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFC_QC.
QcValue nfc_qc(uint32_t cp);

// QcValue nfc_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFKD_QC.
QcValue nfkd_qc(uint32_t cp);

/// \brief  Do NFKD_QC for all code points in the sequence.
QcValue nfkd_qc(const CodePointSequence& seq);

/// \brief  Get the Unicode character property NFKC_QC.
QcValue nfkc_qc(uint32_t cp);

// QcValue nfkc_qc(const CodePointSequence& seq);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NORMALIZATION_PROPS_H */
