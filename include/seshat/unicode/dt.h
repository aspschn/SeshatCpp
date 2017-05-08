/*
//  unicode/dt.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 04. 11:30
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Decomposition_Type
*/
#ifndef _UNICODE_DT_H
#define _UNICODE_DT_H

#include <cstdint>

namespace seshat {
namespace unicode {

// Dt: Decomposition_Type (dt)
// Aliases from PropertyValueAliases.txt
enum class Dt {
    Can,    // Canonical
    Com,    // Compat
    Enc,    // Circle
    Fin,    // Final
    Font,   // Font
    Fra,    // Fraction
    Init,   // Initial
    Iso,    // Isolated
    Med,    // Medial
    Nar,    // Narrow
    Nb,     // Nobreak
    None,   // None
    Sml,    // Small
    Sqr,    // Square
    Sub,    // Sub
    Sup,    // Super
    Vert,   // Vertical
    Wide    // Wide
};

Dt dt(uint32_t cp);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_DT_H */
