/*
//  ucd/gc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 11:46
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_GC_H
#define _UCD_GC_H

#include <seshat/unicode/gc.h>

#include <cstdint>
#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<uint32_t, Gc> gc_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_GC_H */
