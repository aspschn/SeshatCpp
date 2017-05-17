#include "normalization.h"

#include <seshat/codepoint.h>
#include <seshat/unicode/normalize.h>

#include <array>
#include <iostream>
#include <cstdlib>

using seshat::CodePoint;
using seshat::CodePointSequence;
using S = CodePointSequence;

CodePointSequence str_to_seq(const char *str)
{
    CodePointSequence seq;
    char *end;
    for (uint32_t i = std::strtoul(str, &end, 16); str != end; i = std::strtoul(str, &end, 16)) {
        seq.append(CodePoint(i));
        str = end;
    }
    return seq;
}

int main()
{
    // Test reordering
    std::cout << "Test reordering" << std::endl;
    CodePointSequence s = { 0x0044, 0x0307, 0x0323 };
    for (auto cp: s) {
        std::cout << cp.to_string() << " ";
    }
    std::cout << std::endl;
    seshat::unicode::canonical_ordering(s);
    for (auto cp: s) {
        std::cout << cp.to_string() << " ";
    }
    std::cout << std::endl;
    // Test nfd
    std::cout << "Test nfd" << std::endl;
    CodePointSequence org = { 0x0044, 0x0307, 0x0323 };
    for (auto cp: org) {
        std::cout << cp.to_string() << " ";
    }
    std::cout << std::endl;
    auto decomposed = seshat::unicode::nfd(org);
    for (auto cp: decomposed) {
        std::cout << cp.to_string() << " ";
    }
    std::cout << std::endl;
    // Test str_to_seq
    std::cout << "Test str_to_seq()" << std::endl;
    const char *test_str = "0044 0303";
    auto test_seq = str_to_seq(test_str);
    std::cout << "length(2): " << test_seq.length() << std::endl;
    std::cout << "\n----------------------------" << std::endl;

    // Main test
    for (const char **seqs: test_table) {
        CodePointSequence org = str_to_seq(seqs[0]);
        CodePointSequence seshat_nfd = seshat::unicode::nfd(org);
        CodePointSequence right = str_to_seq(seqs[2]);
        for (auto cp: org) {
            std::cout << cp.to_string() << " ";
        }
        if (str_to_seq(seqs[2]) != seshat_nfd) {
            std::cout << ": not => ";
            for (auto cp: seshat_nfd) {
                std::cout << cp.to_string() << " ";
            }
            std::cout << ", but should ";
            for (auto cp: right) {
                std::cout << cp.to_string() << " ";
            }
        }
        std::cout << std::endl;
    }

    return 0;
}
