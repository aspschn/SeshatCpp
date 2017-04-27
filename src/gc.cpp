/*
//  gc.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 11:58
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  General_Category
*/
#include <seshat/unicode/gc.h>

#include "ucd/gc.h"

#include <algorithm>

namespace seshat {
namespace unicode {

Gc gc(uint32_t cp)
{
    // Find the gc matching the range that code point belongs
    uint32_t code = cp;
    auto found = ucd::gc_table.find(CodeRange(code, code));
    /*
    auto gc_pair = std::find_if(ucd::gc_table.begin(), ucd::gc_table.end(),
        [code](const std::pair<CodePointRange, Gc>& p)->bool {
            return (p.first.first <= code && code <= p.first.second);
        }
    );
    */

    if (found != ucd::gc_table.end()) {
        return found->second;
    } else {
        return Gc::Cn;
    }
}

} // namespace unicode
} // namespace seshat
