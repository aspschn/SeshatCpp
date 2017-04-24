/*
//  nchar.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 11:22
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#include "nchar.h"

namespace seshat {

const std::map<uint32_t, bool> nchar_table = {
    { 0xfdd0, true },
    { 0xfdd1, true },
    { 0xfdd2, true },
    { 0xfdd3, true },
    { 0xfdd4, true },
    { 0xfdd5, true },
    { 0xfdd6, true },
    { 0xfdd7, true },
    { 0xfdd8, true },
    { 0xfdd9, true },
    { 0xfdda, true },
    { 0xfddb, true },
    { 0xfddc, true },
    { 0xfddd, true },
    { 0xfdde, true },
    { 0xfddf, true },
    { 0xfde0, true },
    { 0xfde1, true },
    { 0xfde2, true },
    { 0xfde3, true },
    { 0xfde4, true },
    { 0xfde5, true },
    { 0xfde6, true },
    { 0xfde7, true },
    { 0xfde8, true },
    { 0xfde9, true },
    { 0xfdea, true },
    { 0xfdeb, true },
    { 0xfdec, true },
    { 0xfded, true },
    { 0xfdee, true },
    { 0xfdef, true },
    { 0xfffe, true },
    { 0xffff, true },
    { 0x1fffe, true },
    { 0x1ffff, true },
    { 0x2fffe, true },
    { 0x2ffff, true },
    { 0x3fffe, true },
    { 0x3ffff, true },
    { 0x4fffe, true },
    { 0x4ffff, true },
    { 0x5fffe, true },
    { 0x5ffff, true },
    { 0x6fffe, true },
    { 0x6ffff, true },
    { 0x7fffe, true },
    { 0x7ffff, true },
    { 0x8fffe, true },
    { 0x8ffff, true },
    { 0x9fffe, true },
    { 0x9ffff, true },
    { 0xafffe, true },
    { 0xaffff, true },
    { 0xbfffe, true },
    { 0xbffff, true },
    { 0xcfffe, true },
    { 0xcffff, true },
    { 0xdfffe, true },
    { 0xdffff, true },
    { 0xefffe, true },
    { 0xeffff, true },
    { 0xffffe, true },
    { 0xfffff, true },
    { 0x10fffe, true },
    { 0x10ffff, true }
};

bool noncharacter_code_point(uint32_t cp)
{
    bool ret = false;

    auto found = nchar_table.find(cp);
    if (found != nchar_table.end()) {
        ret = found->second;
    }

    return ret;
}

} // namespace seshat
