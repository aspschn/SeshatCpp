#include "normalization.h"

#include <seshat/codepoint.h>
#include <seshat/unicode/normalize.h>

#include <array>
#include <iostream>
#include <cstdlib>
#include <cassert>

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
    // Test nfc
    std::cout << "Test nfc" << std::endl;
    S nfc_org = { 0x0045, 0x0304, 0x0300 };
    for (auto cp: nfc_org)
        std::cout << cp.to_string() << " ";
    std::cout << std::endl;
    auto composed = seshat::unicode::nfc(nfc_org);
    for (auto cp: composed)
        std::cout << cp.to_string() << " ";
    std::cout << "(should be: 0x1E14)\n";
    std::cout << std::endl;
    // Test blocked
    std::cout << "Test blocked" << std::endl;
    S blocked_seq = { 0x0045, 0x0304, 0x0300 };
    auto blocked_beg = blocked_seq.begin();
    assert(*(blocked_beg + 2) == CodePoint(0x0300));
    std::cout << "blocked(true): "
        << seshat::unicode::blocked(blocked_beg, blocked_beg + 2) << std::endl;
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
        CodePointSequence seshat_nfc = seshat::unicode::nfc(org);
        CodePointSequence right_nfd = str_to_seq(seqs[2]);
        CodePointSequence right_nfc = str_to_seq(seqs[1]);
        for (auto cp: org)
            std::cout << cp.to_string() << " ";
        // Wrong NFD
        if (str_to_seq(seqs[2]) != seshat_nfd) {
            std::cout << ": wrong nfd => ";
            for (auto cp: seshat_nfd)
                std::cout << cp.to_string() << " ";
            std::cout << ", but should ";
            for (auto cp: right_nfd)
                std::cout << cp.to_string() << " ";
        }
        // Wrong NFC
        if (str_to_seq(seqs[1]) != seshat_nfc) {
            std::cout << ": wrong nfc => ";
            for (auto cp: seshat_nfc)
                std::cout << cp.to_string() << " ";
            std::cout << ", but should ";
            for (auto cp: right_nfc)
                std::cout << cp.to_string() << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
