//
//  unicode/normalize.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 11:52
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Functions and algorithms for Unicode Normalization Forms.
#ifndef _UNICODE_NORMALIZE_H
#define _UNICODE_NORMALIZE_H

#include <seshat/codepoint.h>

#include <cstdint>

namespace seshat {
namespace unicode {

// Starters
/// \brief  Check code point if it is a Starter character.
bool starter(uint32_t cp);

// Canonical Ordering Algorithm
/// \brief  Check code points if Reorderable pair.
bool reorderable(uint32_t cp_1, uint32_t cp_2);

/// \brief  Canonical order the code point sequence.
void canonical_ordering(CodePointSequence& sequence);

// Canonical Composition Algorithm
/// \brief  Check code point is Full Composition Exclusion.
bool full_composition_exclusion(uint32_t cp);

/// \brief  Check code point is Primary composite.
bool primary_composite(uint32_t cp);

/// \brief  Check if two code points in sequence is Blocked.
/// \param  first
///         Former code point in sequence to check.
/// \param  last
///         Latter code point in sequence to check.
///
/// When \p last is equal to \p first or former than \p first, the behavior is
/// undefined.
bool blocked(CodePointSequenceConstIter first,
    CodePointSequenceConstIter last);

// Composition/Decomposition
CodePointSequence nfd(const CodePointSequence& sequence);
CodePointSequence nfc(const CodePointSequence& sequence);
CodePointSequence nfkd(const CodePointSequence& sequence);
CodePointSequence nfkc(const CodePointSequence& sequence);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_NORMALIZE_H */
