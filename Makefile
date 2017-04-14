OBJ = src/utils.o src/codepoint.o src/character.o src/naming_rule.o src/gc.cpp src/name.cpp
default: $(OBJ)
	mkdir -p lib
	g++ -std=c++11 -shared -o lib/libseshat.so $^ -Iinclude
src/%.o: src/%.cpp
	g++ -std=c++11 -Wall -c -fPIC -Iinclude -o $@ $<

clean:
	rm src/*.o
	rm -r lib
