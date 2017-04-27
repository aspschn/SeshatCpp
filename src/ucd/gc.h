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

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/gc.h> // enum class Gc

#include <cstdint>
#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Gc> gc_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_GC_H */
