/*
//  segmentation.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 05. 19. 18:24
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/unicode/segmentation.h>

#ifndef SESHAT_ICU_BACKEND
#include <seshat/unicode/emoji.h>
#include <seshat/unicode/properties.h>
#else
#include <unicode/ubrk.h>
#include <unicode/uloc.h> // ULOC_US
#include <unicode/ustring.h> // u_strFromUTF32()
#endif // SESHAT_ICU_BACKEND

namespace seshat {
namespace unicode {

namespace cldr {
    Gcb::Gcb(uint32_t cp)
        : _cp(cp)
    {}

    bool Gcb::cr() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::CR);
    }

    bool Gcb::lf() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::LF);
    }

    bool Gcb::control() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::CN);
    }

    bool Gcb::extend() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::EX);
    }

    bool Gcb::zwj() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::ZWJ);
    }

    bool Gcb::regional_indicator() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::RI);
    }

    bool Gcb::prepend() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::PP);
    }

    bool Gcb::spacing_mark() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::SM);
    }

    bool Gcb::l() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::L);
    }

    bool Gcb::v() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::V);
    }

    bool Gcb::t() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::T);
    }

    bool Gcb::lv() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::LV);
    }

    bool Gcb::lvt() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::LVT);
    }

    bool Gcb::e_base() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::EB);
        // Below code makes bug.
        // Why these lines added? Where are these from?
        /*
        if (unicode::gcb(_cp) == unicode::Gcb::EB) {
            // U+1F3C2, U+1F3C7, U+1F3CC, U+1F46A-U+1F46D, U+1F46F, U+1F574,
            // U+1F6CC
            if (_cp == 0x1F3C2 || _cp == 0x1F3C7 || _cp == 0x1F3CC ||
                    (0x1F46A <= _cp && _cp <= 0x1F46D) || _cp == 0x1F46F ||
                    _cp == 0x1F574 || _cp == 0x1F6CC)
                return true;
        }
        return false;
        */
    }

    bool Gcb::e_modifier() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::EM);
    }

    bool Gcb::extended_pict() const
    {
        auto cp = _cp;
        if ((0x1F774 <= cp && cp <= 0x1F77F) ||
                (0x2700 <= cp && cp <= 0x2701) ||
                (0x2703 <= cp && cp <= 0x2704) ||
                cp == 0x270E ||
                (0x2710 <= cp && cp <= 0x2711) ||
                (0x2765 <= cp && cp <= 0x2767) ||
                (0x1F030 <= cp && cp <= 0x1F093) ||
                (0x1F094 <= cp && cp <= 0x1F09F) ||
                (0x1F10D <= cp && cp <= 0x1F10F) ||
                cp == 0x1F12F ||
                (0x1F16C <= cp && cp <= 0x1F16F) ||
                (0x1F1AD <= cp && cp <= 0x1F1E5) ||
                (0x1F203 <= cp && cp <= 0x1F20F) ||
                (0x1F23C <= cp && cp <= 0x1F23F) ||
                (0x1F249 <= cp && cp <= 0x1F24F) ||
                (0x1F252 <= cp && cp <= 0x1F2FF) ||
                (0x1F7D5 <= cp && cp <= 0x1F7FF) ||
                (0x1F000 <= cp && cp <= 0x1F003) ||
                (0x1F005 <= cp && cp <= 0x1F02B) ||
                (0x1F02C <= cp && cp <= 0x1F02F) ||
                (0x1F322 <= cp && cp <= 0x1F323) ||
                (0x1F394 <= cp && cp <= 0x1F395) ||
                cp == 0x1F398 ||
                (0x1F39C <= cp && cp <= 0x1F39D) ||
                (0x1F3F1 <= cp && cp <= 0x1F3F2) ||
                cp == 0x1F3F6 ||
                cp == 0x1F4FE ||
                (0x1F53E <= cp && cp <= 0x1F548) ||
                cp == 0x1F54F ||
                (0x1F568 <= cp && cp <= 0x1F56E) ||
                (0x1F571 <= cp && cp <= 0x1F572) ||
                (0x1F57B <= cp && cp <= 0x1F586) ||
                (0x1F588 <= cp && cp <= 0x1F589) ||
                (0x1F58E <= cp && cp <= 0x1F58F) ||
                (0x1F591 <= cp && cp <= 0x1F594) ||
                (0x1F597 <= cp && cp <= 0x1F5A3) ||
                (0x1F5A6 <= cp && cp <= 0x1F5A7) ||
                (0x1F5A9 <= cp && cp <= 0x1F5B0) ||
                (0x1F5B3 <= cp && cp <= 0x1F5BB) ||
                (0x1F5BD <= cp && cp <= 0x1F5C1) ||
                (0x1F5C5 <= cp && cp <= 0x1F5D0) ||
                (0x1F5D4 <= cp && cp <= 0x1F5DB) ||
                (0x1F5DF <= cp && cp <= 0x1F5E0) ||
                cp == 0x1F5E2 ||
                (0x1F5E4 <= cp && cp <= 0x1F5E7) ||
                (0x1F5E9 <= cp && cp <= 0x1F5EE) ||
                (0x1F5F0 <= cp && cp <= 0x1F5F2) ||
                (0x1F5F4 <= cp && cp <= 0x1F5F9) ||
                cp == 0x2605 ||
                (0x2607 <= cp && cp <= 0x260D) ||
                (0x260F <= cp && cp <= 0x2610) ||
                cp == 0x2612 ||
                (0x2616 <= cp && cp <= 0x2617) ||
                (0x2619 <= cp && cp <= 0x261C) ||
                (0x261E <= cp && cp <= 0x261F) ||
                cp == 0x2621 ||
                (0x2624 <= cp && cp <= 0x2625) ||
                (0x2627 <= cp && cp <= 0x2629) ||
                (0x262B <= cp && cp <= 0x262D) ||
                (0x2630 <= cp && cp <= 0x2637) ||
                (0x263B <= cp && cp <= 0x2647) ||
                (0x2654 <= cp && cp <= 0x265F) ||
                (0x2661 <= cp && cp <= 0x2662) ||
                cp == 0x2664 ||
                cp == 0x2667 ||
                (0x2669 <= cp && cp <= 0x267A) ||
                (0x267C <= cp && cp <= 0x267E) ||
                (0x2680 <= cp && cp <= 0x2691) ||
                cp == 0x2695 ||
                cp == 0x2698 ||
                cp == 0x269A ||
                (0x269D <= cp && cp <= 0x269F) ||
                (0x26A2 <= cp && cp <= 0x26A9) ||
                (0x26AC <= cp && cp <= 0x26AF) ||
                (0x26B2 <= cp && cp <= 0x26BC) ||
                (0x26BF <= cp && cp <= 0x26C3) ||
                (0x26C6 <= cp && cp <= 0x26C7) ||
                (0x26C9 <= cp && cp <= 0x26CD) ||
                cp == 0x26D0 ||
                cp == 0x26D2 ||
                (0x26D5 <= cp && cp <= 0x26E8) ||
                (0x26EB <= cp && cp <= 0x26EF) ||
                cp == 0x26F6 ||
                (0x26FB <= cp && cp <= 0x26FC) ||
                (0x26FE <= cp && cp <= 0x26FF) ||
                cp == 0x2388 ||
                (0x1FA00 <= cp && cp <= 0x1FFFD) ||
                (0x1F0A0 <= cp && cp <= 0x1F0AE) ||
                (0x1F0B1 <= cp && cp <= 0x1F0BF) ||
                (0x1F0C1 <= cp && cp <= 0x1F0CF) ||
                (0x1F0D1 <= cp && cp <= 0x1F0F5) ||
                (0x1F0AF <= cp && cp <= 0x1F0B0) ||
                cp == 0x1F0C0 ||
                cp == 0x1F0D0 ||
                (0x1F0F6 <= cp && cp <= 0x1F0FF) ||
                (0x1F80C <= cp && cp <= 0x1F80F) ||
                (0x1F848 <= cp && cp <= 0x1F84F) ||
                (0x1F85A <= cp && cp <= 0x1F85F) ||
                (0x1F888 <= cp && cp <= 0x1F88F) ||
                (0x1F8AE <= cp && cp <= 0x1F8FF) ||
                (0x1F900 <= cp && cp <= 0x1F90F) ||
                cp == 0x1F91F ||
                (0x1F928 <= cp && cp <= 0x1F92F) ||
                (0x1F931 <= cp && cp <= 0x1F932) ||
                cp == 0x1F93F ||
                (0x1F94C <= cp && cp <= 0x1F94F) ||
                (0x1F95F <= cp && cp <= 0x1F97F) ||
                (0x1F992 <= cp && cp <= 0x1F9BF) ||
                (0x1F9C1 <= cp && cp <= 0x1F9FF) ||
                (0x1F6C6 <= cp && cp <= 0x1F6CA) ||
                (0x1F6E6 <= cp && cp <= 0x1F6E8) ||
                cp == 0x1F6EA ||
                (0x1F6F1 <= cp && cp <= 0x1F6F2) ||
                (0x1F6D3 <= cp && cp <= 0x1F6DF) ||
                (0x1F6ED <= cp && cp <= 0x1F6EF) ||
                (0x1F6F7 <= cp && cp <= 0x1F6FF)
        )
            return true;
        return false;
    }

    bool Gcb::e_base_gaz() const
    {
        return (unicode::gcb(_cp) == unicode::Gcb::EBG);
    }

    bool Gcb::emoji_nrk() const
    {
        if (emoji::emoji(_cp) == true) {
            if (unicode::gcb(_cp) != unicode::Gcb::RI &&
                    _cp != static_cast<uint32_t>('*') &&
                    _cp != static_cast<uint32_t>('#') &&
                    !(0x30 <= _cp && _cp <= 0x39) &&
                    _cp != 0x00A9 && // ©
                    _cp != 0x00AE && // ®
                    _cp != 0x2122 && // ™
                    _cp != 0x3030 && // 〰
                    _cp != 0x303D // 〽
            )
                return true;
        }
        return false;
    }
} // namespace cldr

template <typename It>
It grapheme_bound(It first, It last)
{
#ifdef SESHAT_ICU_BACKEND
    std::vector<UChar> seq16; // ICU UTF-16 string
    int32_t seq16_len;
    UChar *p_seq16;
    UErrorCode e = U_ZERO_ERROR;

    if (first == last) // String length 0.
        return first;
    if ((first + 1) == last) // Last code point always breaks (GB2).
        return first;

    // Convert UTF-32(Seshat) to UTF-16(ICU).
    const auto seq = std::vector<uint32_t>(first, last);
    seq16.reserve(seq.size() * 2);
    p_seq16 = u_strFromUTF32(seq16.data(), seq16.capacity(), &seq16_len,
        reinterpret_cast<const UChar32*>(seq.data()), seq.size(),
        &e);

    // Iterate to next character.
    UBreakIterator *brk_iter = ubrk_open(UBRK_CHARACTER, ULOC_US,
        p_seq16, seq16_len, &e);
    int32_t pos = ubrk_next(brk_iter);
    ubrk_close(brk_iter);

    // Get offset of last code point of boundary.
    U16_SET_CP_START(p_seq16, 0, --pos); // Move `pos` to begin of code point.
    decltype(pos) offset = 0;
    while (pos > 0) {
        U16_BACK_1(p_seq16, 0, pos);
        ++offset;
    }

    return first + offset;
#else
    auto boundary = first;
    auto eot = last;

    for (auto it = first; it != eot; ++it) {
        auto cur = cldr::Gcb(*it);
        auto next = cldr::Gcb(*(it + 1));
        // GB1 - break at the sot
        // GB2 - break at the eot
        if ((it + 1) == eot)
            break;
        // GB3 - do not break between a CR and LF
        if (cur.cr() && next.lf()) {
            ++boundary;
            continue;
        }
        // GB4 - break before controls
        if (cur.control() || cur.cr() || cur.lf())
            break;
        // GB5 - break after controls
        // GB6 - do not break Hangul syllable sequences
        if (cur.l() &&
            (next.l() || next.v() || next.lv() || next.lvt()) ) {
            ++boundary;
            continue;
        }
        // GB7 - do not break Hangul syllable sequences
        if ( (cur.lv() || cur.v()) && (next.v() || next.t()) ) {
            ++boundary;
            continue;
        }
        // GB8 - do not break Hangul syllable sequences
        if ( (cur.lvt() || cur.t()) && next.t()) {
            ++boundary;
            continue;
        }
        // GB9 - do not break before Extend or ZWJ
        if (next.extend() || next.zwj()) {
            ++boundary;
            continue;
        }
        // GB9a - do not break before SpacingMark
        if (next.spacing_mark()) {
            ++boundary;
            continue;
        }
        // GB9b - do not break after Prepend
        if (cur.prepend()) {
            ++boundary;
            continue;
        }
        // GB10 - do not break within emoji modifier sequences
        if (next.e_modifier()) {
            if (cur.e_base() || cur.e_base_gaz()) {
                ++boundary;
                continue;
            }
            // Seek back until found EB or EBG
            if (cur.extend()) {
                for (auto back_it = it - 1; back_it != first - 1; --back_it) {
                    // Continue to seek if EX
                    if (cldr::Gcb(*back_it).extend())
                        continue;
                    // If EB or EBG found, the sequence is
                    // Emoji Modifier Sequence
                    if ( (cldr::Gcb(*back_it).e_base()) ||
                            (cldr::Gcb(*back_it).e_base_gaz()) ) {
                        ++boundary;
                        break;
                    } else {
                        break;
                    }
                }
                continue;
            }
        }
        // GB11 - do not break within emoji zwj sequences
        /*
        if (cur == ZWJ && (next == GAZ || next == EBG)) {
            ++boundary;
            continue;
        }
        */
        // CLDR segmentation rule
        // GraphemeClusterBreak.segmentRules.11
        // ($Extended_Pict | $EmojiNRK) $Extend* $ZWJ
        //  × ($Extended_Pict | $EmojiNRK)
        if (cur.zwj() && (next.extended_pict() || next.emoji_nrk()) ) {
            // Seek back until found Extended_Pict or EmojiNRK.
            for (auto back_it = it - 1; back_it != (first - 1); --back_it) {
                // Continue to seek if Extend
                if (cldr::Gcb(*back_it).extend())
                    continue;
                // If Extended_Pict or EmojiNRK found, the sequence is
                // Emoji ZWJ sequence.
                if (cldr::Gcb(*back_it).extended_pict() ||
                        cldr::Gcb(*back_it).emoji_nrk()) {
                    ++boundary;
                    break;
                } else {
                    break;
                }
            }
            continue;
        }
        // GB12 - do not break within emoji flag sequences
        // GB13 - do not break within emoji flag sequences
        /*
        if (cur == Regional_Indicator && next == Regional_Indicator) {
            ++boundary;
            break;
        }
        */
        // CLDR segmentation rule
        // GraphemeClusterBreak.segmentRules.12
        // ^$Prepend* $Regional_Indicator $Regional_Indicator
        //  ÷ $Regional_Indicator
        // GraphemeClusterBreak.segmentRules.13
        // ^$Prepend* $Regional_Indicator × $Regional_Indicator
        if (cur.regional_indicator() && next.regional_indicator()) {
            ++boundary;
            break;
        }
        // GB999 - otherwise, break everywhere
        break;
    }
    return boundary;
#endif // SESHAT_ICU_BACKEND
}

template
CodePointSequenceIter grapheme_bound<CodePointSequenceIter>(
    CodePointSequenceIter first, CodePointSequenceIter last);

template
CodePointSequenceConstIter grapheme_bound<CodePointSequenceConstIter>(
    CodePointSequenceConstIter first, CodePointSequenceConstIter last);

} // namespace unicode
} // namespace seshat
