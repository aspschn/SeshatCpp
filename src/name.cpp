/*
//  name.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 12:21
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/name.h>

#ifndef SESHAT_ICU_BACKEND
#include "ucd/name.h"
#include <seshat/unicodedata/naming_rule.h>
#else
#include "icu/name.h"
#endif // SESHAT_ICU_BACKEND

#include <algorithm>

namespace seshat {
namespace unicode {

const std::string name(CodePoint cp)
{
#ifndef SESHAT_ICU_BACKEND
    std::string unicode_name;

    // Find which area the code point belongs to
    uint32_t code = cp;
    auto range = range_table.find(CodePointRange(code, code));

    auto name_pair = ucd::name_table.find(cp);
    if (range != range_table.end()) {
        UnicodeNamingRulePtr rule = naming_rule(range->second);
        if (name_pair != ucd::name_table.end()) {
            rule->set(name_pair->second, cp);
        } else {
            rule->set(nullptr, cp);
        }
        unicode_name = rule->name();
    } else {
        if (name_pair != ucd::name_table.end()) {
            unicode_name = name_pair->second;
        } else {
            throw NoName();
        }
    }

    return unicode_name;
#else
    std::string unicode_name = icu::name(cp);
    if (unicode_name.size() == 0)
        throw NoName();
    return unicode_name;
#endif // SESHAT_ICU_BACKEND
}

} // namespace unicode
} // namespace seshat
