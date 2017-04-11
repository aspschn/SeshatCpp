default:
	echo "codepoint, unicode unicode_name"
codepoint:
	g++ -std=c++11 -o codepoint codepoint.cpp ../src/codepoint.cpp ../src/gc.cpp ../src/name.cpp -I../include
unicode:
	g++ -std=c++11 -o unicode unicode.cpp ../src/codepoint.cpp ../src/gc.cpp ../src/name.cpp -I../include
unicode_name:
	g++ -std=c++11 -o unicode_name unicode_name.cpp ../src/codepoint.cpp ../src/gc.cpp ../src/name.cpp -I../include -I/usr/include/python3.6m -lpython3.6m

clean:
	rm codepoint unicode unicode_name
