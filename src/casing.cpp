/*
//  casing.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 12. 01. 20:41
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/casing.h>

#include <seshat/unicode/properties.h>
#include "ucd/case_mapping.h"

#include <cstdlib>

namespace seshat {
namespace unicode {

static_assert(
    sizeof(decltype(std::strtoul(nullptr, nullptr, 0))) >= sizeof(uint32_t),
    "std::strtoul return type cannot cover range of uint32_t"
);

static const CodePointSequence _str_to_seq(const char *str)
{
    CodePointSequence seq;
    char *end;
    auto i = std::strtoul(str, &end, 16);
    while (str != end) {
        seq.append(CodePoint(i));
        str = end;
        i = std::strtoul(str, &end, 16);
    }
    return seq;
}

const CodePointSequence uppercase_mapping(uint32_t cp)
{
    auto found = ucd::sp_upper_table.find(cp);
    if (found != ucd::sp_upper_table.end()) {
        const char *str = found->second;
        return _str_to_seq(str);
    } else {
        CodePointSequence seq;
        seq.append(simple_uppercase_mapping(cp));
        return seq;
    }
}

const CodePointSequence lowercase_mapping(uint32_t cp)
{
    auto found = ucd::sp_lower_table.find(cp);
    if (found != ucd::sp_lower_table.end()) {
        const char *str = found->second;
        return _str_to_seq(str);
    } else {
        CodePointSequence seq;
        seq.append(simple_lowercase_mapping(cp));
        return seq;
    }
}

const CodePointSequence titlecase_mapping(uint32_t cp)
{
    auto found = ucd::sp_title_table.find(cp);
    if (found != ucd::sp_title_table.end()) {
        const char *str = found->second;
        return _str_to_seq(str);
    } else {
        CodePointSequence seq;
        seq.append(simple_titlecase_mapping(cp));
        return seq;
    }
}

} // namespace unicode
} // namespace seshat