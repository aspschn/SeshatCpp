/*
//  case_mapping.h
//
//  Author:     Sophia Lee
//  Created:    2017. 07. 27. 00:33
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _SESHAT_UCD_CASE_MAPPING_H
#define _SESHAT_UCD_CASE_MAPPING_H

#include <cstdint>
#include <unordered_map>
#include <unordered_set>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::unordered_map<uint32_t, uint32_t> slc_table;
extern const std::unordered_map<uint32_t, uint32_t> suc_table;
extern const std::unordered_map<uint32_t, uint32_t> stc_table;

// Special casing tables not contain mappings for conditional casing.
extern const std::unordered_map<uint32_t, const char*> sp_lower_table;
extern const std::unordered_map<uint32_t, const char*> sp_title_table;
extern const std::unordered_map<uint32_t, const char*> sp_upper_table;

// If the code point appears in below table, it has conditional special casing.
extern const std::unordered_set<uint32_t> conditional_table;
// If the code point has language sensitive conditional mapping, it also appears
// below table.
extern const std::unordered_set<uint32_t> lang_sensitive_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UCD_CASE_MAPPING_H */
