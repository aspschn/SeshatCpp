/*
//  ucd/script.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:05
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_SCRIPT_H
#define _UCD_SCRIPT_H

#include <seshat/unicode/properties.h> // enum class Script

#include <cstdint>

namespace seshat {
namespace unicode {
namespace ucd {

Script script(uint32_t cp);

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_SCRIPT_H */
