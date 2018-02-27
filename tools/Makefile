OBJ = seshatinfo.o
default: $(OBJ)
	$(CXX) -std=c++11 $^ $(CXXFLAGS) -I../include -lseshat -L../lib -o seshatinfo

%.o: %.cpp
	$(CXX) -std=c++11 $(CXXFLAGS) -c -I../include -o $@ $< -DSESHAT_TZ_OFFSET=\"`date +%z`\"

clean:
	rm -f *.o
	rm -f seshatinfo
