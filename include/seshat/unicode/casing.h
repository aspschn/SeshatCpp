//
//  unicode/casing.h
//
//  Author:     Sophia Lee
//  Created:    2017. 12. 01. 20:27
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//

/// \file
/// \brief  Case algorithms and case mapping functions.
#ifndef _SESHAT_UNICODE_CASING_H
#define _SESHAT_UNICODE_CASING_H

#include <seshat/codepoint.h>

#include <cstdint>

namespace seshat {
namespace unicode {

/// \brief  Get the Uppercase_Mapping (uc) property value of the code point.
///
/// Returns full uppercase mapping for a single code point.
/// This function does not contain conditional casing.
const CodePointSequence uppercase_mapping(uint32_t cp);

/// \brief  Get the Lowercase_Mapping (lc) property value of the code point.
///
/// Returns full lowercase mapping for a single code point.
/// This function does not contain conditional casing.
const CodePointSequence lowercase_mapping(uint32_t cp);

/// \brief  Get the Titlecase_Mapping (tc) property value of the code point.
///
/// Returns full titlecase mapping for a single code point.
/// This function does not contain conditional casing.
const CodePointSequence titlecase_mapping(uint32_t cp);

} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UNICODE_CASING_H */
