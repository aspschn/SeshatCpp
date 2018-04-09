CXX_FILES = ../src/codepoint.cpp ../src/gc.cpp ../src/name.cpp ../src/utils.cpp ../src/naming_rule.cpp ../src/hangul.cpp
CXXFLAGS = -std=c++11 -I../include -Ithirdparty -Ithirdparty/catch
OBJ = main.o \
	codepoint.o \
	character.o \
	properties.o \
	utils.o
THIRDPARTY_DIR = thirdparty
THIRDPARTY_LIBS = $(THIRDPARTY_DIR)/tinyxml2/libtinyxml2.a
UCD_XML = ucd.nounihan.flat.xml

default: all

all: $(OBJ) $(THIRDPARTY_LIBS)
	$(CXX) $(CXXFLAGS) $(THIRDPARTY_LIBS) $^ -o seshat-test -L../lib -lseshat -Wl,-rpath=../lib

properties.o: $(UCD_XML)
	$(CXX) $(CXXFLAGS) -c properties.cpp

$(UCD_XML):
	wget https://www.unicode.org/Public/10.0.0/ucdxml/ucd.nounihan.flat.zip
	unzip ucd.nounihan.flat.zip

codepoint:
	g++ -std=c++11 -o codepoint codepoint.cpp ../lib/libseshat.a -I../include
character:
	g++ -std=c++11 -o character character.cpp ../lib/libseshat.a -I../include
string:
	g++ -std=c++11 -o string string.cpp ../lib/libseshat.a -I../include
unicode:
	g++ -std=c++11 -o unicode unicode.cpp ../lib/libseshat.a -I../include
unicode_name:
	g++ -std=c++11 -o unicode_name unicode_name.cpp $(CXX_FILES) -I../include -I/usr/include/python3.6m -lpython3.6m
normalization:
	g++ -std=c++11 -Wall -o normalization normalization.cpp ../lib/libseshat.a -I../include $(CXXFLAGS)
derivation:
	g++ -std=c++11 -Wall -o derivation derivation.cpp ../lib/libseshat.a -I../include
seg:
	g++ -std=c++11 -Wall -o seg seg.cpp ../lib/libseshat.a -I../include $(CXXFLAGS)
casing:
	g++ -std=c++11 -Wall -o casing casing.cpp ../lib/libseshat.a -I../include

$(THIRDPARTY_DIR)/tinyxml2/libtinyxml2.a:
	$(CXX) -c $(THIRDPARTY_DIR)/tinyxml2/tinyxml2.cpp -o $(THIRDPARTY_DIR)/tinyxml2/tinyxml2.o
	ar rcs $(THIRDPARTY_DIR)/tinyxml2/libtinyxml2.a $(THIRDPARTY_DIR)/tinyxml2/tinyxml2.o

cleanall: clean
	rm -f ucd.nounihan.flat.zip $(UCD_XML)

clean:
	rm -f codepoint unicode unicode_name normalization character derivation string seg *.o seshat-test
	rm -f $(THIRDPARTY_DIR)/tinyxml2/*.o
	rm -f $(THIRDPARTY_LIBS)
