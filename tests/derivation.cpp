// Test for derived properties.
//
#include <seshat/utils.h>
#include <seshat/unicode/properties.h>

#include <cassert>
#include <set>

using namespace seshat;
using seshat::CodePointRange;

/*
# ================================================

180B..180D    ; Variation_Selector # Mn   [3] MONGOLIAN FREE VARIATION SELECTOR ONE..MONGOLIAN FREE VARIATION SELECTOR THREE
FE00..FE0F    ; Variation_Selector # Mn  [16] VARIATION SELECTOR-1..VARIATION SELECTOR-16
E0100..E01EF  ; Variation_Selector # Mn [240] VARIATION SELECTOR-17..VARIATION SELECTOR-256

# Total code points: 259
*/
const std::set<CodePointRange> variation_selector_table = {
    { CodePointRange(0x180B, 0x180D) },
    { CodePointRange(0xFE00, 0xFE0F) },
    { CodePointRange(0xE0100, 0xE01EF) }
};
const int variation_selector_total = 259;

/*
# ================================================

# Derived Property: Default_Ignorable_Code_Point

# Total code points: 4173
*/
const std::set<CodePointRange> default_ignorable_code_point_table = {
    { CodePointRange(0x00AD, 0x00AD) }, { CodePointRange(0x034F, 0x034F) },
    { CodePointRange(0x061C, 0x061C) }, { CodePointRange(0x115F, 0x1160) },
    { CodePointRange(0x17B4, 0x17B5) }, { CodePointRange(0x180B, 0x180D) },
    { CodePointRange(0x180E, 0x180E) }, { CodePointRange(0x200B, 0x200F) },
    { CodePointRange(0x202A, 0x202E) }, { CodePointRange(0x2060, 0x2064) },
    { CodePointRange(0x2065, 0x2065) }, { CodePointRange(0x2066, 0x206F) },
    { CodePointRange(0x3164, 0x3164) }, { CodePointRange(0xFE00, 0xFE0F) },
    { CodePointRange(0xFEFF, 0xFEFF) }, { CodePointRange(0xFFA0, 0xFFA0) },
    { CodePointRange(0xFFF0, 0xFFF8) }, { CodePointRange(0x1BCA0, 0x1BCA3) },
    { CodePointRange(0x1D173, 0x1D17A) }, { CodePointRange(0xE0000, 0xE0000) },
    { CodePointRange(0xE0001, 0xE0001) }, { CodePointRange(0xE0002, 0xE001F) },
    { CodePointRange(0xE0020, 0xE007F) }, { CodePointRange(0xE0080, 0xE00FF) },
    { CodePointRange(0xE0100, 0xE01EF) }, { CodePointRange(0xE01F0, 0xE0FFF) }
};
const int default_ignorable_code_point_total = 4173;

/*
# Derived Property: Grapheme_Extend

# Total code points: 1828
 */
const std::set<CodePointRange> grapheme_extend_table = {
    { CodePointRange(0x0300, 0x036F) }, { CodePointRange(0x0483, 0x0487) },
    { CodePointRange(0x0488, 0x0489) }, { CodePointRange(0x0591, 0x05BD) },
    { CodePointRange(0x05BF, 0x05BF) }, { CodePointRange(0x05C1, 0x05C2) },
    { CodePointRange(0x05C4, 0x05C5) }, { CodePointRange(0x05C7, 0x05C7) },
    { CodePointRange(0x0610, 0x061A) }, { CodePointRange(0x064B, 0x065F) },
    { CodePointRange(0x0670, 0x0670) }, { CodePointRange(0x06D6, 0x06DC) },
    { CodePointRange(0x06DF, 0x06E4) }, { CodePointRange(0x06E7, 0x06E8) },
    { CodePointRange(0x06EA, 0x06ED) }, { CodePointRange(0x0711, 0x0711) },
    { CodePointRange(0x0730, 0x074A) }, { CodePointRange(0x07A6, 0x07B0) },
    { CodePointRange(0x07EB, 0x07F3) }, { CodePointRange(0x0816, 0x0819) },
    { CodePointRange(0x081B, 0x0823) }, { CodePointRange(0x0825, 0x0827) },
    { CodePointRange(0x0829, 0x082D) }, { CodePointRange(0x0859, 0x085B) },
    { CodePointRange(0x08D4, 0x08E1) }, { CodePointRange(0x08E3, 0x0902) },
    { CodePointRange(0x093A, 0x093A) }, { CodePointRange(0x093C, 0x093C) },
    { CodePointRange(0x0941, 0x0948) }, { CodePointRange(0x094D, 0x094D) },
    { CodePointRange(0x0951, 0x0957) }, { CodePointRange(0x0962, 0x0963) },
    { CodePointRange(0x0981, 0x0981) }, { CodePointRange(0x09BC, 0x09BC) },
    { CodePointRange(0x09BE, 0x09BE) }, { CodePointRange(0x09C1, 0x09C4) },
    { CodePointRange(0x09CD, 0x09CD) }, { CodePointRange(0x09D7, 0x09D7) },
    { CodePointRange(0x09E2, 0x09E3) }, { CodePointRange(0x0A01, 0x0A02) },
    { CodePointRange(0x0A3C, 0x0A3C) }, { CodePointRange(0x0A41, 0x0A42) },
    { CodePointRange(0x0A47, 0x0A48) }, { CodePointRange(0x0A4B, 0x0A4D) },
    { CodePointRange(0x0A51, 0x0A51) }, { CodePointRange(0x0A70, 0x0A71) },
    { CodePointRange(0x0A75, 0x0A75) }, { CodePointRange(0x0A81, 0x0A82) },
    { CodePointRange(0x0ABC, 0x0ABC) }, { CodePointRange(0x0AC1, 0x0AC5) },
    { CodePointRange(0x0AC7, 0x0AC8) }, { CodePointRange(0x0ACD, 0x0ACD) },
    { CodePointRange(0x0AE2, 0x0AE3) }, { CodePointRange(0x0B01, 0x0B01) },
    { CodePointRange(0x0B3C, 0x0B3C) }, { CodePointRange(0x0B3E, 0x0B3E) },
    { CodePointRange(0x0B3F, 0x0B3F) }, { CodePointRange(0x0B41, 0x0B44) },
    { CodePointRange(0x0B4D, 0x0B4D) }, { CodePointRange(0x0B56, 0x0B56) },
    { CodePointRange(0x0B57, 0x0B57) }, { CodePointRange(0x0B62, 0x0B63) },
    { CodePointRange(0x0B82, 0x0B82) }, { CodePointRange(0x0BBE, 0x0BBE) },
    { CodePointRange(0x0BC0, 0x0BC0) }, { CodePointRange(0x0BCD, 0x0BCD) },
    { CodePointRange(0x0BD7, 0x0BD7) }, { CodePointRange(0x0C00, 0x0C00) },
    { CodePointRange(0x0C3E, 0x0C40) }, { CodePointRange(0x0C46, 0x0C48) },
    { CodePointRange(0x0C4A, 0x0C4D) }, { CodePointRange(0x0C55, 0x0C56) },
    { CodePointRange(0x0C62, 0x0C63) }, { CodePointRange(0x0C81, 0x0C81) },
    { CodePointRange(0x0CBC, 0x0CBC) }, { CodePointRange(0x0CBF, 0x0CBF) },
    { CodePointRange(0x0CC2, 0x0CC2) }, { CodePointRange(0x0CC6, 0x0CC6) },
    { CodePointRange(0x0CCC, 0x0CCD) }, { CodePointRange(0x0CD5, 0x0CD6) },
    { CodePointRange(0x0CE2, 0x0CE3) }, { CodePointRange(0x0D01, 0x0D01) },
    { CodePointRange(0x0D3E, 0x0D3E) }, { CodePointRange(0x0D41, 0x0D44) },
    { CodePointRange(0x0D4D, 0x0D4D) }, { CodePointRange(0x0D57, 0x0D57) },
    { CodePointRange(0x0D62, 0x0D63) }, { CodePointRange(0x0DCA, 0x0DCA) },
    { CodePointRange(0x0DCF, 0x0DCF) }, { CodePointRange(0x0DD2, 0x0DD4) },
    { CodePointRange(0x0DD6, 0x0DD6) }, { CodePointRange(0x0DDF, 0x0DDF) },
    { CodePointRange(0x0E31, 0x0E31) }, { CodePointRange(0x0E34, 0x0E3A) },
    { CodePointRange(0x0E47, 0x0E4E) }, { CodePointRange(0x0EB1, 0x0EB1) },
    { CodePointRange(0x0EB4, 0x0EB9) }, { CodePointRange(0x0EBB, 0x0EBC) },
    { CodePointRange(0x0EC8, 0x0ECD) }, { CodePointRange(0x0F18, 0x0F19) },
    { CodePointRange(0x0F35, 0x0F35) }, { CodePointRange(0x0F37, 0x0F37) },
    { CodePointRange(0x0F39, 0x0F39) }, { CodePointRange(0x0F71, 0x0F7E) },
    { CodePointRange(0x0F80, 0x0F84) }, { CodePointRange(0x0F86, 0x0F87) },
    { CodePointRange(0x0F8D, 0x0F97) }, { CodePointRange(0x0F99, 0x0FBC) },
    { CodePointRange(0x0FC6, 0x0FC6) }, { CodePointRange(0x102D, 0x1030) },
    { CodePointRange(0x1032, 0x1037) }, { CodePointRange(0x1039, 0x103A) },
    { CodePointRange(0x103D, 0x103E) }, { CodePointRange(0x1058, 0x1059) },
    { CodePointRange(0x105E, 0x1060) }, { CodePointRange(0x1071, 0x1074) },
    { CodePointRange(0x1082, 0x1082) }, { CodePointRange(0x1085, 0x1086) },
    { CodePointRange(0x108D, 0x108D) }, { CodePointRange(0x109D, 0x109D) },
    { CodePointRange(0x135D, 0x135F) }, { CodePointRange(0x1712, 0x1714) },
    { CodePointRange(0x1732, 0x1734) }, { CodePointRange(0x1752, 0x1753) },
    { CodePointRange(0x1772, 0x1773) }, { CodePointRange(0x17B4, 0x17B5) },
    { CodePointRange(0x17B7, 0x17BD) }, { CodePointRange(0x17C6, 0x17C6) },
    { CodePointRange(0x17C9, 0x17D3) }, { CodePointRange(0x17DD, 0x17DD) },
    { CodePointRange(0x180B, 0x180D) }, { CodePointRange(0x1885, 0x1886) },
    { CodePointRange(0x18A9, 0x18A9) }, { CodePointRange(0x1920, 0x1922) },
    { CodePointRange(0x1927, 0x1928) }, { CodePointRange(0x1932, 0x1932) },
    { CodePointRange(0x1939, 0x193B) }, { CodePointRange(0x1A17, 0x1A18) },
    { CodePointRange(0x1A1B, 0x1A1B) }, { CodePointRange(0x1A56, 0x1A56) },
    { CodePointRange(0x1A58, 0x1A5E) }, { CodePointRange(0x1A60, 0x1A60) },
    { CodePointRange(0x1A62, 0x1A62) }, { CodePointRange(0x1A65, 0x1A6C) },
    { CodePointRange(0x1A73, 0x1A7C) }, { CodePointRange(0x1A7F, 0x1A7F) },
    { CodePointRange(0x1AB0, 0x1ABD) }, { CodePointRange(0x1ABE, 0x1ABE) },
    { CodePointRange(0x1B00, 0x1B03) }, { CodePointRange(0x1B34, 0x1B34) },
    { CodePointRange(0x1B36, 0x1B3A) }, { CodePointRange(0x1B3C, 0x1B3C) },
    { CodePointRange(0x1B42, 0x1B42) }, { CodePointRange(0x1B6B, 0x1B73) },
    { CodePointRange(0x1B80, 0x1B81) }, { CodePointRange(0x1BA2, 0x1BA5) },
    { CodePointRange(0x1BA8, 0x1BA9) }, { CodePointRange(0x1BAB, 0x1BAD) },
    { CodePointRange(0x1BE6, 0x1BE6) }, { CodePointRange(0x1BE8, 0x1BE9) },
    { CodePointRange(0x1BED, 0x1BED) }, { CodePointRange(0x1BEF, 0x1BF1) },
    { CodePointRange(0x1C2C, 0x1C33) }, { CodePointRange(0x1C36, 0x1C37) },
    { CodePointRange(0x1CD0, 0x1CD2) }, { CodePointRange(0x1CD4, 0x1CE0) },
    { CodePointRange(0x1CE2, 0x1CE8) }, { CodePointRange(0x1CED, 0x1CED) },
    { CodePointRange(0x1CF4, 0x1CF4) }, { CodePointRange(0x1CF8, 0x1CF9) },
    { CodePointRange(0x1DC0, 0x1DF5) }, { CodePointRange(0x1DFB, 0x1DFF) },
    { CodePointRange(0x200C, 0x200C) }, { CodePointRange(0x20D0, 0x20DC) },
    { CodePointRange(0x20DD, 0x20E0) }, { CodePointRange(0x20E1, 0x20E1) },
    { CodePointRange(0x20E2, 0x20E4) }, { CodePointRange(0x20E5, 0x20F0) },
    { CodePointRange(0x2CEF, 0x2CF1) }, { CodePointRange(0x2D7F, 0x2D7F) },
    { CodePointRange(0x2DE0, 0x2DFF) }, { CodePointRange(0x302A, 0x302D) },
    { CodePointRange(0x302E, 0x302F) }, { CodePointRange(0x3099, 0x309A) },
    { CodePointRange(0xA66F, 0xA66F) }, { CodePointRange(0xA670, 0xA672) },
    { CodePointRange(0xA674, 0xA67D) }, { CodePointRange(0xA69E, 0xA69F) },
    { CodePointRange(0xA6F0, 0xA6F1) }, { CodePointRange(0xA802, 0xA802) },
    { CodePointRange(0xA806, 0xA806) }, { CodePointRange(0xA80B, 0xA80B) },
    { CodePointRange(0xA825, 0xA826) }, { CodePointRange(0xA8C4, 0xA8C5) },
    { CodePointRange(0xA8E0, 0xA8F1) }, { CodePointRange(0xA926, 0xA92D) },
    { CodePointRange(0xA947, 0xA951) }, { CodePointRange(0xA980, 0xA982) },
    { CodePointRange(0xA9B3, 0xA9B3) }, { CodePointRange(0xA9B6, 0xA9B9) },
    { CodePointRange(0xA9BC, 0xA9BC) }, { CodePointRange(0xA9E5, 0xA9E5) },
    { CodePointRange(0xAA29, 0xAA2E) }, { CodePointRange(0xAA31, 0xAA32) },
    { CodePointRange(0xAA35, 0xAA36) }, { CodePointRange(0xAA43, 0xAA43) },
    { CodePointRange(0xAA4C, 0xAA4C) }, { CodePointRange(0xAA7C, 0xAA7C) },
    { CodePointRange(0xAAB0, 0xAAB0) }, { CodePointRange(0xAAB2, 0xAAB4) },
    { CodePointRange(0xAAB7, 0xAAB8) }, { CodePointRange(0xAABE, 0xAABF) },
    { CodePointRange(0xAAC1, 0xAAC1) }, { CodePointRange(0xAAEC, 0xAAED) },
    { CodePointRange(0xAAF6, 0xAAF6) }, { CodePointRange(0xABE5, 0xABE5) },
    { CodePointRange(0xABE8, 0xABE8) }, { CodePointRange(0xABED, 0xABED) },
    { CodePointRange(0xFB1E, 0xFB1E) }, { CodePointRange(0xFE00, 0xFE0F) },
    { CodePointRange(0xFE20, 0xFE2F) }, { CodePointRange(0xFF9E, 0xFF9F) },
    { CodePointRange(0x101FD, 0x101FD) }, { CodePointRange(0x102E0, 0x102E0) },
    { CodePointRange(0x10376, 0x1037A) }, { CodePointRange(0x10A01, 0x10A03) },
    { CodePointRange(0x10A05, 0x10A06) }, { CodePointRange(0x10A0C, 0x10A0F) },
    { CodePointRange(0x10A38, 0x10A3A) }, { CodePointRange(0x10A3F, 0x10A3F) },
    { CodePointRange(0x10AE5, 0x10AE6) }, { CodePointRange(0x11001, 0x11001) },
    { CodePointRange(0x11038, 0x11046) }, { CodePointRange(0x1107F, 0x11081) },
    { CodePointRange(0x110B3, 0x110B6) }, { CodePointRange(0x110B9, 0x110BA) },
    { CodePointRange(0x11100, 0x11102) }, { CodePointRange(0x11127, 0x1112B) },
    { CodePointRange(0x1112D, 0x11134) }, { CodePointRange(0x11173, 0x11173) },
    { CodePointRange(0x11180, 0x11181) }, { CodePointRange(0x111B6, 0x111BE) },
    { CodePointRange(0x111CA, 0x111CC) }, { CodePointRange(0x1122F, 0x11231) },
    { CodePointRange(0x11234, 0x11234) }, { CodePointRange(0x11236, 0x11237) },
    { CodePointRange(0x1123E, 0x1123E) }, { CodePointRange(0x112DF, 0x112DF) },
    { CodePointRange(0x112E3, 0x112EA) }, { CodePointRange(0x11300, 0x11301) },
    { CodePointRange(0x1133C, 0x1133C) }, { CodePointRange(0x1133E, 0x1133E) },
    { CodePointRange(0x11340, 0x11340) }, { CodePointRange(0x11357, 0x11357) },
    { CodePointRange(0x11366, 0x1136C) }, { CodePointRange(0x11370, 0x11374) },
    { CodePointRange(0x11438, 0x1143F) }, { CodePointRange(0x11442, 0x11444) },
    { CodePointRange(0x11446, 0x11446) }, { CodePointRange(0x114B0, 0x114B0) },
    { CodePointRange(0x114B3, 0x114B8) }, { CodePointRange(0x114BA, 0x114BA) },
    { CodePointRange(0x114BD, 0x114BD) }, { CodePointRange(0x114BF, 0x114C0) },
    { CodePointRange(0x114C2, 0x114C3) }, { CodePointRange(0x115AF, 0x115AF) },
    { CodePointRange(0x115B2, 0x115B5) }, { CodePointRange(0x115BC, 0x115BD) },
    { CodePointRange(0x115BF, 0x115C0) }, { CodePointRange(0x115DC, 0x115DD) },
    { CodePointRange(0x11633, 0x1163A) }, { CodePointRange(0x1163D, 0x1163D) },
    { CodePointRange(0x1163F, 0x11640) }, { CodePointRange(0x116AB, 0x116AB) },
    { CodePointRange(0x116AD, 0x116AD) }, { CodePointRange(0x116B0, 0x116B5) },
    { CodePointRange(0x116B7, 0x116B7) }, { CodePointRange(0x1171D, 0x1171F) },
    { CodePointRange(0x11722, 0x11725) }, { CodePointRange(0x11727, 0x1172B) },
    { CodePointRange(0x11C30, 0x11C36) }, { CodePointRange(0x11C38, 0x11C3D) },
    { CodePointRange(0x11C3F, 0x11C3F) }, { CodePointRange(0x11C92, 0x11CA7) },
    { CodePointRange(0x11CAA, 0x11CB0) }, { CodePointRange(0x11CB2, 0x11CB3) },
    { CodePointRange(0x11CB5, 0x11CB6) }, { CodePointRange(0x16AF0, 0x16AF4) },
    { CodePointRange(0x16B30, 0x16B36) }, { CodePointRange(0x16F8F, 0x16F92) },
    { CodePointRange(0x1BC9D, 0x1BC9E) }, { CodePointRange(0x1D165, 0x1D165) },
    { CodePointRange(0x1D167, 0x1D169) }, { CodePointRange(0x1D16E, 0x1D172) },
    { CodePointRange(0x1D17B, 0x1D182) }, { CodePointRange(0x1D185, 0x1D18B) },
    { CodePointRange(0x1D1AA, 0x1D1AD) }, { CodePointRange(0x1D242, 0x1D244) },
    { CodePointRange(0x1DA00, 0x1DA36) }, { CodePointRange(0x1DA3B, 0x1DA6C) },
    { CodePointRange(0x1DA75, 0x1DA75) }, { CodePointRange(0x1DA84, 0x1DA84) },
    { CodePointRange(0x1DA9B, 0x1DA9F) }, { CodePointRange(0x1DAA1, 0x1DAAF) },
    { CodePointRange(0x1E000, 0x1E006) }, { CodePointRange(0x1E008, 0x1E018) },
    { CodePointRange(0x1E01B, 0x1E021) }, { CodePointRange(0x1E023, 0x1E024) },
    { CodePointRange(0x1E026, 0x1E02A) }, { CodePointRange(0x1E8D0, 0x1E8D6) },
    { CodePointRange(0x1E944, 0x1E94A) }, { CodePointRange(0xE0020, 0xE007F) },
    { CodePointRange(0xE0100, 0xE01EF) }
};
const int grapheme_extend_total = 1828;

int main()
{
    int variation_selector_count = 0;
    int default_ignorable_code_point_count = 0;
    int grapheme_extend_count = 0;

    for (uint32_t i = 0; i <= 0x10FFFF; ++i) {
        auto found = variation_selector_table.find(CodePointRange(i, i));
        bool result = unicode::variation_selector(i);
        if (result == true &&
            found != variation_selector_table.end()) {
            ++variation_selector_count;
        }
        found = default_ignorable_code_point_table.find(CodePointRange(i, i));
        result = unicode::default_ignorable_code_point(i);
        if (result == true &&
            found != default_ignorable_code_point_table.end()) {
            ++default_ignorable_code_point_count;
        }
        found = grapheme_extend_table.find(CodePointRange(i, i));
        result = unicode::grapheme_extend(i);
        if (result == true &&
            found != grapheme_extend_table.end()) {
            ++grapheme_extend_count;
        }
    }
    assert(variation_selector_count == variation_selector_total);
    assert(default_ignorable_code_point_count == default_ignorable_code_point_total);
    assert(grapheme_extend_count == grapheme_extend_total);

    return 0;
}
