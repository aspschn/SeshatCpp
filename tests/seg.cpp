#include <seshat/codepoint.h>
#include <seshat/unicode/segmentation.h>

#include <iostream>

using namespace seshat;

int count_graheme(const CodePointSequence& seq)
{
    unsigned int count = 0;
    auto each_cp = seq.begin();
    for (auto it = unicode::grapheme_bound(seq.begin(), seq.end());
            it != seq.end();
            it = unicode::grapheme_bound(it + 1, seq.end())) {
        ++count;
        while (each_cp != it)
            std::cout << (*(each_cp++)).to_string() << " ";
        std::cout << (*(each_cp++)).to_string() << " | ";
    }
    std::cout << "\n";

    return count;
}

int main()
{
    CodePointSequence s0;
    CodePointSequence s1 = { 'a', 'b', 'c' };
    CodePointSequence s2 = { 0x1100, 0x1161, 0x11a8 };
    CodePointSequence s3 = {
        0x1F469, 0x200D, 0x2764, 0xFE0F, 0x200D, 0x1F48B, 0x200D, 0x1F469,
            // kiss: woman, woman
        0x1F469, 0x1F3FE, 0x200D, 0x1F3A4,
            // woman singer: medium-dark skin tone
        0x1F441, 0xFE0F, 0x200D, 0x1F5E8, 0xFE0F
            // eye in speech bubble
    };

    std::cout << "count(0): " << count_graheme(s0) << std::endl;
    std::cout << "count(3): " << count_graheme(s1) << std::endl;
    std::cout << "count(1): " << count_graheme(s2) << std::endl;
    std::cout << "count(3): " << count_graheme(s3) << std::endl;
    return 0;
}
