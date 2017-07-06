/*
//  unicode/dm.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 10. 10:15
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UNICODE_DM_H
#define _UNICODE_DM_H

#include <seshat/codepoint.h>
#include <seshat/utils.h>

#include <cstdint>

namespace seshat {
namespace unicode {

const CodePointSequence dm(uint32_t cp);

// uint32_t rdm() - Search reversed decomposition mapping.
// Return value: Matching code point of the sequence.
//  U+0000 will be returned if no matching.
// Notes:
//  NULL character chosen since it does not appears from normalization forms.
//  This NOT meaning the composition mapping for given sequence is NULL.
uint32_t rdm(const CodePointSequence& seq);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_DM_H */
