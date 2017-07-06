/*
//  ucd/dm.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 04. 16:46
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Decomposition_Mapping table.
*/
#ifndef _UCD_DM_H
#define _UCD_DM_H

#include <cstdint>
#include <unordered_map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::unordered_map<uint32_t, const char*> dm_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_DM_H */
