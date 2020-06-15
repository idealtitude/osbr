CXX=g++
CXXFLAGS=-std=c++17 -g -Wall -Werror -pedantic
LDFLAGS=-lstdc++fs

ifeq ($(release), true)
	CXXFLAGS=-std=c++17 -lstdc++fs
endif

src=src/main.cpp src/biblefiles.cpp src/biblib.cpp src/biblemenu.cpp
inc=inc/biblefiles.h inc/biblib.h inc/biblemenu.h
obj=$(src:.cpp=.o)

%: %.o
	$(LINK.cpp) -o $@ $^

osbr: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

clean:
	$(RM) *~ *.o

mrproper: clean
	$(RM) osbr

depend:
	makedepend $(src)
