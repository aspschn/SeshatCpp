/*
//  dm.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 10. 10:35
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/dm.h>

#include "ucd/dm.h"

namespace seshat {
namespace unicode {

const CodePointSequence dm(uint32_t cp)
{
    auto found = ucd::dm_table.find(cp);
    if (found != ucd::dm_table.end()) {
        return found->second;
    }
    return CodePointSequence();
}

} // namespace unicode
} // namespace seshat
