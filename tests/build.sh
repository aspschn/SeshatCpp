#!/bin/bash

g++ -std=c++11 -o codepoint codepoint.cpp ../src/codepoint.cpp ../src/gc.cpp -I../include
g++ -std=c++11 -o unicode unicode.cpp ../src/codepoint.cpp ../src/gc.cpp -I../include
