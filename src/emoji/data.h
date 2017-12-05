/*
//  emoji/data.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 16. 19:32
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _EMOJI_DATA_H
#define _EMOJI_DATA_H

#include <seshat/utils.h>

#include <set>

namespace seshat {
namespace unicode {
namespace emoji {

extern const std::set<CodePointRange> emoji_table;
extern const std::set<CodePointRange> emoji_presentation_table;
extern const std::set<CodePointRange> emoji_modifier_table;
extern const std::set<CodePointRange> emoji_modifier_base_table;
extern const std::set<CodePointRange> emoji_component_table;

} // namespace emoji
} // namespace unicode
} // namespace seshat

#endif /* _EMOJI_DATA_H */
