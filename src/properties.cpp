/*
//  properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:07
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/properties.h>

#include "ucd/script.h"

namespace seshat {
namespace unicode {

Script script(uint32_t cp)
{
    auto found = ucd::script_table.find(CodePointRange(cp, cp));

    if (found != ucd::script_table.end()) {
        return found->second;
    }
    return Script::Zzzz;
}

} // namespace unicode
} // namespace seshat
