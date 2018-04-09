/*
//  ucd/gcb.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 18. 13:02
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_GCB_H
#define _UCD_GCB_H

#include <seshat/unicode/properties.h> // enum class Gcb

#include <cstdint>

namespace seshat {
namespace unicode {
namespace ucd {

Gcb gcb(uint32_t cp);

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_GCB_H */
