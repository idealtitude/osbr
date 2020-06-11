CXX=g++
CXXFLAGS=-std=c++17 -g -Wall -Werror -pedantic -lstdc++fs

ifeq ($(release), true)
	CXXFLAGS=-std=c++17 -lstdc++fs
endif

src=main.cpp biblefiles.cpp biblib.cpp
inc=biblefiles.h biblib.h
obj=$(src:.cpp=.o)

%: %.o
	$(LINK.cpp) -o $@ $^

bible: $(obj)
	$(CXX) -o $@ $^

clean:
	$(RM) *~ *.o

mrproper: clean
	$(RM) bible

depend:
	makedepend $(src)
