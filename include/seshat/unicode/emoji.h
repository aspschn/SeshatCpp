//
//  unicode/emoji.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 16. 19:20
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Functions for Emoji properties.
#ifndef _UNICODE_EMOJI_H
#define _UNICODE_EMOJI_H

#include <cstdint>

namespace seshat {
namespace unicode {
namespace emoji {

#define EMOJI_VERSION_MAJOR 5
#define EMOJI_VERSION_MINOR 0

/// \brief  Get the Emoji property value of the code point.
bool emoji(uint32_t cp);

/// \brief  Get the Emoji_Presentation property value of the code point.
bool emoji_presentation(uint32_t cp);

/// \brief  Get the Emoji_Modifier property value of the code point.
bool emoji_modifier(uint32_t cp);

/// \brief  Get the Emoji_Modifier_Base property value of the code point.
bool emoji_modifier_base(uint32_t cp);

/// \brief  Get the Emoji_Component property value of the code point.
bool emoji_component(uint32_t cp);

} // namespace emoji
} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_EMOJI_H */
