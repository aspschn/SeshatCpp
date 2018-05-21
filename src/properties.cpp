/*
//  properties.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 11. 17:07
//  Copyright (c) 2017-2018 Sophia Lee. All rights reserved.
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

bool ascii_hex_digit(CodePoint cp)
{
    return implementation::ascii_hex_digit(cp);
}

bool bidi_control(CodePoint cp)
{
    return implementation::bidi_control(cp);
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

bool dash(CodePoint cp)
{
    return implementation::dash(cp);
}

bool deprecated(CodePoint cp)
{
    return implementation::deprecated(cp);
}

bool default_ignorable_code_point(CodePoint cp)
{
    return implementation::default_ignorable_code_point(cp);
}

bool diacritic(CodePoint cp)
{
    return implementation::diacritic(cp);
}

bool extender(CodePoint cp)
{
    return implementation::extender(cp);
}

bool hex_digit(CodePoint cp)
{
    return implementation::hex_digit(cp);
}

bool hyphen(CodePoint cp)
{
    return implementation::hyphen(cp);
}

bool ideographic(CodePoint cp)
{
    return implementation::ideographic(cp);
}

bool ids_binary_operator(CodePoint cp)
{
    return implementation::ids_binary_operator(cp);
}

bool ids_trinary_operator(CodePoint cp)
{
    return implementation::ids_trinary_operator(cp);
}

bool join_control(CodePoint cp)
{
    return implementation::join_control(cp);
}

bool logical_order_exception(CodePoint cp)
{
    return implementation::logical_order_exception(cp);
}

bool nchar(CodePoint cp)
{
    return implementation::nchar(cp);
}

bool oalpha(CodePoint cp)
{
    return implementation::oalpha(cp);
}

bool oidc(CodePoint cp)
{
    return implementation::oidc(cp);
}

bool oids(CodePoint cp)
{
    return implementation::oids(cp);
}

bool other_math(CodePoint cp)
{
    return implementation::other_math(cp);
}

bool pattern_syntax(CodePoint cp)
{
    return implementation::pattern_syntax(cp);
}

bool pattern_white_space(CodePoint cp)
{
    return implementation::pattern_white_space(cp);
}

bool quotation_mark(CodePoint cp)
{
    return implementation::quotation_mark(cp);
}

bool regional_indicator(CodePoint cp)
{
    return implementation::regional_indicator(cp);
}

bool radical(CodePoint cp)
{
    return implementation::radical(cp);
}

bool soft_dotted(CodePoint cp)
{
    return implementation::soft_dotted(cp);
}

bool sentence_terminal(CodePoint cp)
{
    return implementation::sentence_terminal(cp);
}

bool terminal_punctuation(CodePoint cp)
{
    return implementation::terminal_punctuation(cp);
}

bool unified_ideograph(CodePoint cp)
{
    return implementation::unified_ideograph(cp);
}

bool variation_selector(CodePoint cp)
{
    return implementation::variation_selector(cp);
}

bool uppercase(CodePoint cp)
{
    return implementation::uppercase(cp);
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
