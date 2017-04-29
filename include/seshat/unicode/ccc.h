/*
//  unicode/ccc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 25. 23:33
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Canonical_Combining_Class
*/
#ifndef _UNICODE_CCC_H
#define _UNICODE_CCC_H

#include <cstdint>

namespace seshat {
namespace unicode {

uint8_t ccc(uint32_t cp);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_CCC_H */
