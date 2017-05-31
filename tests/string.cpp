/*
//  tests/string.cpp
//
//  Author:     <OWNER>
//  Created:    2017. 05. 26. 11:40
//  Copyright (c) 2016 <OWNER>. All rights reserved.
//
//
*/
#include <seshat/string.h>

#include <iostream>

int main()
{
    using seshat::CodePointSequence;
    using seshat::String;

    CodePointSequence seq = {
        'D', 0x0323
    };
    String s1 = String(seq);
    String s2 = String(CodePointSequence{ 'T', 'e', 's', 't' });
    String s3 = {
        'T', 'e', 's', 't'
    };

    std::cout << "s1.count(): " << s1.count() << std::endl;
    std::cout << "s2.count(): " << s2.count() << std::endl;
    std::cout << "s3.count(): " << s3.count() << std::endl;

    return 0;
}
