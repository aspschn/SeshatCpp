//
//  unicode/dm.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 10. 10:15
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Decomposition mapping.
#ifndef _UNICODE_DM_H
#define _UNICODE_DM_H

#include <seshat/codepoint.h>
#include <seshat/utils.h>

#include <cstdint>

namespace seshat {
namespace unicode {

/// \brief  Get the Decomposition_Mapping property value of the code point.
///
/// If there is no mapping for the code point, it returns an empty sequence.
const CodePointSequence dm(uint32_t cp);

/// \brief  Search reversed decomposition mapping.
/// \return Matching code point of the sequence.\n
/// U+0000 will be returned if no matching.
///
/// Notes:\n
/// NULL character chosen since it does not appears from normalization forms.\n
/// This NOT meaning the composition mapping for given sequence is NULL.
uint32_t rdm(const CodePointSequence& seq);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_DM_H */
