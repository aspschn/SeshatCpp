/*
//  gcb/wb.h
//
//  Author:     Sophia Lee
//  Created:    2017. 12. 05. 19:53
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _SESHAT_UCD_GC_H
#define _SESHAT_UCD_GC_H

#include <seshat/unicode/properties.h> // enum class Wb

#include <cstdint>

namespace seshat {
namespace unicode {
namespace ucd {

Wb wb(uint32_t cp);

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UCD_GC_H */
