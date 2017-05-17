//  This file generated automatically using 'ucd-tool.py'.
//  You can find the author and the copyright in file 'tools/ucd-tool.py'.
//
// Properties from PropList.txt
//
// Tables for ...
// Other_Grapheme_Extend (OGr_Ext)
// Other_Default_Ignorable_Code_Point (ODI)
// Prepended_Concatenation_Mark (PCM)
#include "core.h"

namespace seshat {
namespace unicode {
namespace ucd {



const std::set<CodePointRange> wspace_table = {
    { CodePointRange(0x0009, 0x000D) },
    { CodePointRange(0x0020, 0x0020) },
    { CodePointRange(0x0085, 0x0085) },
    { CodePointRange(0x00A0, 0x00A0) },
    { CodePointRange(0x1680, 0x1680) },
    { CodePointRange(0x2000, 0x200A) },
    { CodePointRange(0x2028, 0x2028) },
    { CodePointRange(0x2029, 0x2029) },
    { CodePointRange(0x202F, 0x202F) },
    { CodePointRange(0x205F, 0x205F) },
    { CodePointRange(0x3000, 0x3000) }
};

const std::set<CodePointRange> ogr_ext_table = {
    { CodePointRange(0x09BE, 0x09BE) },
    { CodePointRange(0x09D7, 0x09D7) },
    { CodePointRange(0x0B3E, 0x0B3E) },
    { CodePointRange(0x0B57, 0x0B57) },
    { CodePointRange(0x0BBE, 0x0BBE) },
    { CodePointRange(0x0BD7, 0x0BD7) },
    { CodePointRange(0x0CC2, 0x0CC2) },
    { CodePointRange(0x0CD5, 0x0CD6) },
    { CodePointRange(0x0D3E, 0x0D3E) },
    { CodePointRange(0x0D57, 0x0D57) },
    { CodePointRange(0x0DCF, 0x0DCF) },
    { CodePointRange(0x0DDF, 0x0DDF) },
    { CodePointRange(0x200C, 0x200C) },
    { CodePointRange(0x302E, 0x302F) },
    { CodePointRange(0xFF9E, 0xFF9F) },
    { CodePointRange(0x1133E, 0x1133E) },
    { CodePointRange(0x11357, 0x11357) },
    { CodePointRange(0x114B0, 0x114B0) },
    { CodePointRange(0x114BD, 0x114BD) },
    { CodePointRange(0x115AF, 0x115AF) },
    { CodePointRange(0x1D165, 0x1D165) },
    { CodePointRange(0x1D16E, 0x1D172) },
    { CodePointRange(0xE0020, 0xE007F) }
};

const std::set<CodePointRange> odi_table = {
    { CodePointRange(0x034F, 0x034F) },
    { CodePointRange(0x115F, 0x1160) },
    { CodePointRange(0x17B4, 0x17B5) },
    { CodePointRange(0x2065, 0x2065) },
    { CodePointRange(0x3164, 0x3164) },
    { CodePointRange(0xFFA0, 0xFFA0) },
    { CodePointRange(0xFFF0, 0xFFF8) },
    { CodePointRange(0xE0000, 0xE0000) },
    { CodePointRange(0xE0002, 0xE001F) },
    { CodePointRange(0xE0080, 0xE00FF) },
    { CodePointRange(0xE01F0, 0xE0FFF) }
};

const std::set<CodePointRange> pcm_table = {
    { CodePointRange(0x0600, 0x0605) },
    { CodePointRange(0x06DD, 0x06DD) },
    { CodePointRange(0x070F, 0x070F) },
    { CodePointRange(0x08E2, 0x08E2) },
    { CodePointRange(0x110BD, 0x110BD) }
};

} // namespace ucd
} // namespace unicode
} // namespace seshat
