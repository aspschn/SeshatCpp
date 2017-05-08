/*
//  dt.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 05. 23:50
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/dt.h>

#include "ucd/dt.h"

namespace seshat {
namespace unicode {

Dt dt(uint32_t cp)
{
    auto found = ucd::dt_table.find(CodePointRange(cp, cp));

    if (found != ucd::dt_table.end()) {
        return found->second;
    }
    return Dt::None;
}

} // namespace unicode
} // namespace seshat
