/*
//  ccc.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 10:09
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/ccc.h>

#include "ucd/ccc.h"

namespace seshat {
namespace unicode {

uint8_t ccc(uint32_t cp)
{
    auto found = ucd::ccc_table.find(CodePointRange(cp, cp));

    if (found != ucd::ccc_table.end()) {
        return found->second;
    } else {
        return 0;
    }
}

} // namespace unicode
} // namespace seshat
