/*
//  dm.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 10. 10:35
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/dm.h>

#include "ucd/dm.h"
#include "ucd/rdm.h"

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

uint32_t rdm(const CodePointSequence& seq)
{
    if (seq.length() <= 0)
        return 0x0;

    int s_len = seq.length() - 1; // Spaces count.
    for (auto cp: seq)
        s_len += CP_MAX_DIGIT(cp);
    std::string buf(s_len, ' ');
    int cur = 0; // Cursor pointing buffer index.
    for (auto cp: seq) {
        // Write to the buffer each digit of the code point.
        for (int i = CP_MAX_DIGIT(cp); i > 0; --i)
            buf[cur++] = HEX_CHAR[AT_DIGIT_32(cp, i)];
        ++cur; // For space.
    }

    // Search from table.
    auto found = ucd::rdm_table.find(buf.c_str());
    if (found != ucd::rdm_table.end()) {
        return found->second;
    }
    return 0x0; // U+0000 (NUL) not appears from any of normalization form.
}

} // namespace unicode
} // namespace seshat
