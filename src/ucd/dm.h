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

#include <seshat/codepoint.h>

#include <cstdint>
#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<uint32_t, CodePointSequence> dm_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_DM_H */
