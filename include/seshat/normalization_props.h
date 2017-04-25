/*
//  normalization_props.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 14:59
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _NORMALIZATION_PROPS_H
#define _NORMALIZATION_PROPS_H

#include <seshat/utils.h>

#include <cstdint>
#include <map>
#include <utility>

namespace seshat {

enum class QcValue {
    No,
    Yes,
    Maybe
};

// comp_ex_table - Full_Composition_Exclusion
extern const std::map<CodePointRange, bool> comp_ex_table;
extern const std::map<CodePointRange, QcValue> nfd_qc_table;
extern const std::map<CodePointRange, QcValue> nfc_qc_table;
extern const std::map<CodePointRange, QcValue> nfkd_qc_table;
extern const std::map<CodePointRange, QcValue> nfkc_qc_table;

bool comp_ex(uint32_t cp);
QcValue nfd_qc(uint32_t cp);
QcValue nfc_qc(uint32_t cp);
QcValue nfkd_qc(uint32_t cp);
QcValue nfkc_qc(uint32_t cp);

} // namespace seshat

#endif /* _NORMALIZATION_PROPS_H */
