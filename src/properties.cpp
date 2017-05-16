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

#include <seshat/unicode/gc.h>
#include "ucd/block.h"
#include "ucd/core.h"
#include "ucd/script.h"

namespace seshat {
namespace unicode {

/*
Script script(uint32_t cp)
{
    auto found = ucd::script_table.find(CodePointRange(cp, cp));

    if (found != ucd::script_table.end()) {
        return found->second;
    }
    return Script::Zzzz;
}
*/

Block block(uint32_t cp)
{
    auto found = ucd::block_table.find(CodePointRange(cp, cp));

    if (found != ucd::block_table.end()) {
        return found->second;
    }
    return Block::NB;
}

/*
Gcb gcb(uint32_t cp)
{
    if (cp == 0x000D)
        return Gcb::CR;
    if (cp == 0x000A)
        return Gcb::LF;
    // Gcb::CN (Control)
    //
    // General_Category = Line_Separator, or
    // General_Category = Paragraph_Separator, or
    // General_Category = Control, or
    // General_Category = Unassigned and Default_Ignorable_Code_Point, or
    // General_Category = Surrogate, or
    // General_Category = Format
    // and not U+000D CARRIAGE RETURN
    // and not U+000A LINE FEED
    // and not U+200C ZERO WIDTH NON-JOINER (ZWNJ)
    // and not U+200D ZERO WIDTH JOINER (ZWJ)
    if (gc(cp) == Gc::Zl ||
        gc(cp) == Gc::Zp ||
        gc(cp) == Gc::Cc ||
        (gc(cp) == Gc::Cn && di(cp) == true) ||
        gc(cp) == Gc::Cs ||
        (gc(cp) == Gc::Cf &&
            cp != 0x000D && cp != 0x000A && cp != 0x200C && cp != 0x200D))
        return Gcb::CN;
}
*/

bool odi(uint32_t cp)
{
    auto found = ucd::odi_table.find(CodePointRange(cp, cp));
    return (found != ucd::odi_table.end()) ? true : false;
}

bool ogr_ext(uint32_t cp)
{
    auto found = ucd::ogr_ext_table.find(CodePointRange(cp, cp));
    return (found != ucd::ogr_ext_table.end()) ? true : false;
}

bool prepended_concatenation_mark(uint32_t cp)
{
    auto found = ucd::pcm_table.find(CodePointRange(cp, cp));
    return (found != ucd::pcm_table.end()) ? true : false;
}

} // namespace unicode
} // namespace seshat
