/*
//  icu/properties.h
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 23. 19:26
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode property functions that using ICU API to get properties.
*/
#ifndef _SESHAT_ICU_PROPERTIES_H
#define _SESHAT_ICU_PROPERTIES_H

#include <seshat/unicode/properties.h>

namespace seshat {
namespace unicode {
namespace icu {

Block block(uint32_t cp);
uint8_t ccc(uint32_t cp);
Dt dt(uint32_t cp);
Gc gc(uint32_t cp);
Gcb gcb(uint32_t cp);
bool grapheme_extend(uint32_t cp);
bool default_ignorable_code_point(uint32_t cp);
bool variation_selector(uint32_t cp);
bool odi(uint32_t cp) = delete;
bool ogr_ext(uint32_t cp) = delete;
bool prepended_concatenation_mark(uint32_t cp) = delete;
bool white_space(uint32_t cp);

} // namespace icu
} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_ICU_PROPERTIES_H */
