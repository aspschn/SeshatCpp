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

CodePointSequence::size_type grapheme_bound(const CodePointSequence& seq,
    CodePointSequence::size_type pos=0);

} // namespace unicode
} // namespace seshat

#endif /* _UNICODE_SEGMENTATION_H */
