/*
//  ucd/rdm.h
//
//  Author:     Sophia Lee
//  Created:    2017. 07. 04. 19:57
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//  Reversed Decomposition_Mapping table.
//  Used for composition.
//  ! rdm is not a part of Unicode property.
*/
#ifndef _SESHAT_UCD_RDM_H
#define _SESHAT_UCD_RDM_H

#include <cstdint>
#include <string>
#include <unordered_map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::unordered_map<
    const char*,
    uint32_t,
    std::hash<std::string>,
    std::equal_to<std::string>
> rdm_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UCD_RDM_H */
