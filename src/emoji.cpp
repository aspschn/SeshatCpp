/*
//  emoji.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 17. 12:01
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/emoji.h>

#include "emoji/data.h"

namespace seshat {
namespace unicode {
namespace emoji {

bool emoji(uint32_t cp)
{
    auto found = emoji_table.find(CodePointRange(cp, cp));
    return (found != emoji_table.end()) ? true : false;
}

bool emoji_presentation(uint32_t cp)
{
    auto found = emoji_presentation_table.find(CodePointRange(cp, cp));
    return (found != emoji_presentation_table.end()) ? true : false;
}

bool emoji_modifier(uint32_t cp)
{
    auto found = emoji_modifier_table.find(CodePointRange(cp, cp));
    return (found != emoji_modifier_table.end()) ? true : false;
}

bool emoji_modifier_base(uint32_t cp)
{
    auto found = emoji_modifier_base_table.find(CodePointRange(cp, cp));
    return (found != emoji_modifier_base_table.end()) ? true : false;
}

bool emoji_component(uint32_t cp)
{
    auto found = emoji_component_table.find(CodePointRange(cp, cp));
    return (found != emoji_component_table.end()) ? true : false;
}

} // namespace emoji
} // namespace unicode
} // namespace seshat
