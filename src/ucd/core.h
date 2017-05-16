/*
//  ucd/core.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 15. 23:00
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_CORE_H
#define _UCD_CORE_H

#include <seshat/utils.h> // CodePointRange

#include <set>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::set<CodePointRange> ogr_ext_table;
extern const std::set<CodePointRange> odi_table;
extern const std::set<CodePointRange> pcm_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_CORE_H */
