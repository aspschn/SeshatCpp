/*
//  ucd/gc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 11:46
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_GC_H
#define _UCD_GC_H

#include <seshat/unicode/properties.h> // enum class Gc

#include <cstdint>

namespace seshat {
namespace unicode {
namespace ucd {

Gc gc(uint32_t cp);

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_GC_H */
