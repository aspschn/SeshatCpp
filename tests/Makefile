CXX_FILES = ../src/codepoint.cpp ../src/gc.cpp ../src/name.cpp ../src/utils.cpp ../src/naming_rule.cpp ../src/hangul.cpp

default:
	echo "codepoint, unicode unicode_name"
codepoint:
	g++ -std=c++11 -o codepoint codepoint.cpp ../lib/libseshat.a -I../include
unicode:
	g++ -std=c++11 -o unicode unicode.cpp ../lib/libseshat.a -I../include
unicode_name:
	g++ -std=c++11 -o unicode_name unicode_name.cpp $(CXX_FILES) -I../include -I/usr/include/python3.6m -lpython3.6m
normalization:
	g++ -std=c++11 -Wall -o normalization normalization.cpp ../lib/libseshat.a -I../include

clean:
	rm codepoint unicode unicode_name normalization
