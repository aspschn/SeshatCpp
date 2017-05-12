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

#include <cstdlib>

namespace seshat {
namespace unicode {

static_assert(
    sizeof(decltype(std::strtoul(nullptr, nullptr, 0))) >= sizeof(uint32_t),
    "std::strtoul return type cannot cover range of uint32_t"
);
const CodePointSequence dm(uint32_t cp)
{
    CodePointSequence seq;
    auto found = ucd::dm_table.find(cp);
    if (found != ucd::dm_table.end()) {
        const char *str = found->second;
        char *end;
        auto i = std::strtoul(str, &end, 16);
        while (str != end) {
            seq.append(CodePoint(i));
            str = end;
            i = std::strtoul(str, &end, 16);
        }
        return seq;
    }
    // return CodePointSequence{ CodePoint(cp) };
    return CodePointSequence();
}

} // namespace unicode
} // namespace seshat
