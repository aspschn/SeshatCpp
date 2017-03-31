/*
//  gc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 03. 31. 11:22
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _GC_H
#define _GC_H

#include <cstdint>
#include <map>

namespace seshat {

enum class Gc {
    C,
    Cc, Cf, Cn, Co, Cs,
    L,
    LC, Ll, Lm, Lo, Lt, Lu,
    M,
    Mc, Me, Mn,
    N,
    Nd, Nl, No,
    P, Pc, Pd, Pe, Pf, Pi, Po, Ps,
    S,
    Sc, Sk, Sm, So,
    Z,
    Zl, Zp, Zs,
};

extern const std::map<uint32_t, Gc> gc_table;

} // namespace seshat

#endif /* _GC_H */
