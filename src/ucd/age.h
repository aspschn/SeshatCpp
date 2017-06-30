/*
//  ucd/age.h
//
//  Author:     Sophia Lee
//  Created:    2017. 06. 30. 17:57
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode Age property table.
*/
#ifndef _SESHAT_UCD_AGE_H
#define _SESHAT_UCD_AGE_H

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/version.h> // struct Version

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Version> age_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _SESHAT_UCD_AGE_H */
