/*
//  unicode/gc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 25. 23:18
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  General_Category
*/
#ifndef _UNICODE_GC_H
#define _UNICODE_GC_H

#include <cstdint>

namespace seshat {
namespace unicode {

// Gc: General_Category enum
enum class Gc {
    // C - Other
    Cc, Cf, Cn, Co, Cs,
    // L - Letter
    // LC - Cased_Letter (Ll | Lt | Lu)
    Ll, Lm, Lo, Lt, Lu,
    // M - Mark
    Mc, Me, Mn,
    // N - Number
    Nd, Nl, No,
    // P - Punctuation
    Pc, Pd, Pe, Pf, Pi, Po, Ps,
    // S - Symbol
    Sc, Sk, Sm, So,
    // Z - Separator
    Zl, Zp, Zs,
};

Gc gc(uint32_t cp);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_GC_H */
