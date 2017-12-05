/*
//  properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:07
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/properties.h>

#ifndef SESHAT_ICU_BACKEND
#include "ucd/properties.h"
#else
#include "icu/properties.h"
#endif // SESHAT_ICU_BACKEND

namespace seshat {
namespace unicode {

namespace implementation {
#ifndef SESHAT_ICU_BACKEND
    using namespace seshat::unicode::ucd;
#else
    using namespace seshat::unicode::icu;
#endif // SESHAT_ICU_BACKEND
} // namespace implementation

Version age(CodePoint cp)
{
    return implementation::age(cp);
}

Gc gc(CodePoint cp)
{
    return implementation::gc(cp);
}

uint8_t ccc(CodePoint cp)
{
    return implementation::ccc(cp);
}

Dt dt(CodePoint cp)
{
    return implementation::dt(cp);
}

Block block(CodePoint cp)
{
    return implementation::block(cp);
}

Script script(CodePoint cp)
{
    return implementation::script(cp);
}

Gcb gcb(CodePoint cp)
{
    return implementation::gcb(cp);
}

Wb wb(CodePoint cp)
{
    return implementation::wb(cp);
}

bool lowercase(CodePoint cp)
{
    return implementation::lowercase(cp);
}

// Public property functions that not supported in ICU backend version.
#ifndef SESHAT_ICU_BACKEND
bool odi(CodePoint cp)
{
    return ucd::odi(cp);
}

bool ogr_ext(CodePoint cp)
{
    return ucd::ogr_ext(cp);
}

bool prepended_concatenation_mark(CodePoint cp)
{
    return ucd::prepended_concatenation_mark(cp);
}

bool other_lowercase(CodePoint cp)
{
    return ucd::other_lowercase(cp);
}

bool other_uppercase(CodePoint cp)
{
    return ucd::other_uppercase(cp);
}
#endif // SESHAT_ICU_BACKEND

bool grapheme_extend(CodePoint cp)
{
    return implementation::grapheme_extend(cp);
}

bool cased(CodePoint cp)
{
    return implementation::cased(cp);
}

bool default_ignorable_code_point(CodePoint cp)
{
    return implementation::default_ignorable_code_point(cp);
}

bool uppercase(CodePoint cp)
{
    return implementation::uppercase(cp);
}

bool variation_selector(CodePoint cp)
{
    return implementation::variation_selector(cp);
}

bool white_space(CodePoint cp)
{
    return implementation::white_space(cp);
}

CodePoint simple_lowercase_mapping(CodePoint cp)
{
    return implementation::simple_lowercase_mapping(cp);
}

CodePoint simple_titlecase_mapping(CodePoint cp)
{
    return implementation::simple_titlecase_mapping(cp);
}

CodePoint simple_uppercase_mapping(CodePoint cp)
{
    return implementation::simple_uppercase_mapping(cp);
}

} // namespace unicode
} // namespace seshat
