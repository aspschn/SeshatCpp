#include <seshat/codepoint.h>
#include <seshat/unicode/segmentation.h>

#include <iostream>

using namespace seshat;

int count_graheme(const CodePointSequence& seq)
{
    unsigned int count = 0;
    std::cout << "breaks: ";
    for (auto pos = unicode::grapheme_bound(seq, 0); pos < seq.length();
        pos = unicode::grapheme_bound(seq, pos + 1)) {
        ++count;
        std::cout << pos << " ";
    }
    std::cout << std::endl;

    return count;
}

int main()
{
    CodePointSequence s0;
    CodePointSequence s1 = { 'a', 'b', 'c' };
    CodePointSequence s2 = { 0x1100, 0x1161, 0x11a8 };

    std::cout << "count: " << count_graheme(s0) << std::endl;
    std::cout << "count: " << count_graheme(s1) << std::endl;
    std::cout << "count: " << count_graheme(s2) << std::endl;
    return 0;
}
