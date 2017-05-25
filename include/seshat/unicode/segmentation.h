 /*
//  unicode/segmentation.h
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 19. 18:03
//  Copyright (c) 2016 Sophia Lee. All rights reserved.
//
//  Unicode text segmentation functions such as Grapheme Cluster Boundary,
//  Word Boundary, Sentence Boundary.
*/
#ifndef _UNICODE_SEGMENTATION_H
#define _UNICODE_SEGMENTATION_H

#include <seshat/codepoint.h>

namespace seshat {
namespace unicode {

template <typename It>
It grapheme_bound(It first, It last);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_SEGMENTATION_H */
