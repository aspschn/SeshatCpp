/*
//  ucd/name.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 12:48
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_NAME_H
#define _UCD_NAME_H

#include <cstdint>
#include <unordered_map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::unordered_map<uint32_t, const char*> name_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_NAME_H */
