/*
//  name.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 26. 12:21
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/name.h>

#include "ucd/name.h"
#include <seshat/unicodedata/naming_rule.h>

#include <algorithm>

namespace seshat {
namespace unicode {

const std::string name(uint32_t cp)
{
    std::string unicode_name;

    // Find which area the code point belongs to
    uint32_t code = cp;
    auto range = std::find_if(range_table.begin(), range_table.end(),
        [code](const std::pair<CodePointRange, UnicodeArea>& p)->bool {
            return (p.first.first <= code && code <= p.first.second);
        }
    );

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
}

} // namespace unicode
} // namespace seshat
