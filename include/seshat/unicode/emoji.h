/*
//  unicode/emoji.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 16. 19:20
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UNICODE_EMOJI_H
#define _UNICODE_EMOJI_H

#include <cstdint>

namespace seshat {
namespace unicode {
namespace emoji {

#define EMOJI_VERSION_MAJOR 4
#define EMOJI_VERSION_MINOR 0

bool emoji(uint32_t cp);
bool emoji_presentation(uint32_t cp);
bool emoji_modifier(uint32_t cp);
bool emoji_modifier_base(uint32_t cp);

} // namespace emoji
} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_EMOJI_H */
