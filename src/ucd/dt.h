/*
//  ucd/dt.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 04. 11:25
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_DT_H
#define _UCD_DT_H

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/dt.h> // enum class Dt

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Dt> dt_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_DT_H */
