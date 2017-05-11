/*
//  ucd/script.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:05
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_SCRIPT_H
#define _UCD_SCRIPT_H

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/properties.h> // enum class Script

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Script> script_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_SCRIPT_H */
