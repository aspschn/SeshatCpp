/*
//  tests/unicode_name.cpp
//
//  Author:     Sophia Lee
//  Created:    2017. 04. 10. 19:55
//  Copyright (c) 2017 Sophia Lee. All rights reserved.
//
//
*/
#include <seshat/codepoint.h>
#include <seshat/unicodedata.h>

#include <Python.h>

#include <cassert>
#include <cstdint>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <unistd.h>

std::string call_python(uint32_t code)
{
    PyObject *unicodedata;
    PyObject *dict;
    PyObject *unicodedata_name;
    // PyObject *__main__;
    PyObject *builtins;
    PyObject *func;
    PyObject *args;
    PyObject *arg;
    PyObject *res;
    int err;

    // __main__ = PyImport_ImportModule((char*)"__main__");
    builtins = PyImport_ImportModule((char*)"builtins");
    unicodedata = PyImport_ImportModule((char*)"unicodedata");

    // dict = PyModule_GetDict(__main__);
    // func = PyDict_GetItemString(dict, "chr");
    func = PyObject_GetAttrString(builtins, "chr");
    if (PyCallable_Check(func)) {
        // arg = PyLong_FromUnsignedLong(0xAC00);
        arg = PyLong_FromUnsignedLong(code);
        args = PyTuple_Pack(1, arg);
        res = PyObject_CallObject(func, args);
        PyErr_Print();
        // printf("%s\n", PyUnicode_AsUTF8(res));
    } else {
        printf("Not callable!\n");
    }

    dict = PyModule_GetDict(unicodedata);
    unicodedata_name = PyDict_GetItemString(dict, (char*)"name");

    std::string name;
    if (PyCallable_Check(unicodedata_name)) {
        arg = res;
        args = PyTuple_Pack(2, arg, PyLong_FromLong(16));
        res = PyObject_CallObject(unicodedata_name, args);
        // PyErr_Print();
        bool err = false;
        try {
            std::string a = PyUnicode_AsUTF8(res);
        } catch (...) {
            err = true;
        }
        if (err == false) {
            name = PyUnicode_AsUTF8(res);
        } else {
            name = "No";
        }
    } else {
    }
    return name;
}

/*
std::string shell(const char *cmd)
{
    char buffer[128];
    std::string res = "";
    FILE *pipe = popen(cmd, "r");
    while (!feof(pipe)) {
        if (fgets(buffer, 128, pipe) != NULL) {
            res += buffer;
        }
    }
    pclose(pipe);
    return res;
}

std::string python_inline(uint32_t code)
{
    char *cmd1 = "python3 -c $'import unicodedata\ntry:\n  print(unicodedata.name(chr(";
    char *cmd2 = ")), end=\"\")\nexcept:\n  print(\"No\", end=\"\")'";
    std::string cmd = std::string(cmd1) + std::to_string(code)
        + cmd2;

    return shell(cmd.c_str());
}
*/

void unicode_name_check()
{
    using seshat::CodePoint;

    uint32_t first_diff = 0;
    uint32_t count = 0;

    std::cout
        << " code point |      seshat      |        python unicodedata      \n"
        << "----------------------------------------------------------------"
        << std::endl;
    for (uint32_t i = 0; i < 0x110000; ++i) {
        CodePoint cp = CodePoint(i);
        std::string seshat_name;
        std::string py_uni_name;
        try {
            seshat_name = cp.name();
        } catch (const seshat::NoName& e) {
            seshat_name = "No";
        }
        // py_uni_name = python_inline(i);
        py_uni_name = call_python(i);
        if (seshat_name != py_uni_name) {
            // in Python 3.6.1, TANGUT IDEOGRAPH names are omitted
            if (0x17000 <= i && i <= 0x187EC) {
                continue;
            }
            if (first_diff == 0) {
                first_diff = i;
            }
            ++count;
            std::cout << cp.to_string() << " | "
                << seshat_name << " | " << py_uni_name << std::endl;
        }
    }
    std::cout << "first difference found: " << first_diff << std::endl;
    std::cout << "difference total: " << count << std::endl;
}

int main()
{
    Py_Initialize();

    //
    unicode_name_check();

    Py_Finalize();

    return 0;
}
