/*
//  nchar.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 24. 11:17
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  NChar(Noncharacter_Code_Point) property.
//  You can find about noncharacters in '2.4 Code Points and Characters'.
*/
#ifndef _NCHAR_H
#define _NCHAR_H

#include <cstdint>
#include <map>

namespace seshat {

extern const std::map<uint32_t, bool> nchar_table;

bool noncharacter_code_point(uint32_t cp);

} // namespace seshat

#endif /* _NCHAR_H */
