/*
//  ucd/gcb.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 18. 13:02
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_GCB_H
#define _UCD_GCB_H

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/properties.h> // enum class Gcb

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Gcb> gcb_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_GCB_H */
