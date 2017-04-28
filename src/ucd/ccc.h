/*
//  ucd/ccc.h
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 28. 10:07
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_CCC_H
#define _UCD_CCC_H

#include <seshat/utils.h> // CodePointRange

#include <cstdint>
#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, uint8_t> ccc_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_CCC_H */
