OBJ = src/utils.o src/codepoint.o src/character.o src/naming_rule.o src/gc.o src/name.o src/ccc.o src/hangul.o src/ucd/gc.o src/ucd/name.o src/ucd/ccc.o src/normalize.o \
	src/normalization_props.o src/ucd/normalization_props.o \
	src/dt.o src/ucd/dt.o \
	src/properties.o \
	src/ucd/block.o \
	src/emoji.o src/emoji/data.o \
	src/ucd/core.o \
	src/ucd/gcb.o \
	src/dm.o src/ucd/dm.o
default: $(OBJ)
	mkdir -p lib
	g++ -std=c++11 -shared -o lib/libseshat.so $^ -Iinclude
static: $(OBJ)
	mkdir -p lib
	ar rcs lib/libseshat.a $^
src/ucd/%.o: src/ucd/%.cpp
	g++ -std=c++11 -Wall -c -fPIC -Iinclude -o $@ $<
src/%.o: src/%.cpp
	g++ -std=c++11 -Wall -c -fPIC -Iinclude -o $@ $<

clean:
	rm src/*.o
	rm src/ucd/*.o
	rm -r lib
