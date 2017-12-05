/*
//  ucd/normalization_props.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 04. 18:46
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_NORMALIZATION_PROPS_H
#define _UCD_NORMALIZATION_PROPS_H

#include <seshat/unicode/normalization_props.h> // QcValue

#include <seshat/utils.h> // CodePointRange

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

// comp_ex_table - Full_Composition_Exclusion
extern const std::map<CodePointRange, bool> comp_ex_table;
extern const std::map<CodePointRange, QcValue> nfd_qc_table;
extern const std::map<CodePointRange, QcValue> nfc_qc_table;
extern const std::map<CodePointRange, QcValue> nfkd_qc_table;
extern const std::map<CodePointRange, QcValue> nfkc_qc_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_NORMALIZATION_PROPS_H */
