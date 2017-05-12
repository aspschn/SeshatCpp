/*
//  ucd/block.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 12. 13:41
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//
*/
#ifndef _UCD_BLOCK_H
#define _UCD_BLOCK_H

#include <seshat/utils.h> // CodePointRange
#include <seshat/unicode/properties.h> // enum class Block

#include <map>

namespace seshat {
namespace unicode {
namespace ucd {

extern const std::map<CodePointRange, Block> block_table;

} // namespace ucd
} // namespace unicode
} // namespace seshat

#endif /* _UCD_BLOCK_H */
