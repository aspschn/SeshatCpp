/*
//  unicode/normalize.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 11:52
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UNICODE_NORMALIZE_H
#define _UNICODE_NORMALIZE_H

#include <seshat/codepoint.h>

#include <cstdint>

namespace seshat {
namespace unicode {

// Starters
bool starter(uint32_t cp);
// Canonical Ordering Algorithm
bool reorderable(uint32_t cp_1, uint32_t cp_2);
void canonical_ordering(CodePointSequence& sequence);
// Canonical Composition Algorithm
bool full_composition_exclusion(uint32_t cp);
bool primary_composite(uint32_t cp);
bool blocked(CodePointSequenceConstIter first,
    CodePointSequenceConstIter last);

// Composition/Decomposition
CodePointSequence nfd(const CodePointSequence& sequence);
CodePointSequence nfc(const CodePointSequence& sequence);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NORMALIZE_H */
