CXX=g++
CXXFLAGS=-std=c++17 -g -Wall -Werror -pedantic
LDFLAGS=-lstdc++fs

dest=bin/debug/

ifeq ($(release), true)
	CXXFLAGS=-std=c++17
	dest=bin/release/
endif

srco=src/
src=src/main.cpp src/appinit.cpp src/filereader.cpp
inc=inc/appinit.h inc/filereader.h
obj=$(src:.cpp=.o)

%: %.o
	$(LINK.cpp) -o $@ $^

osbr: $(obj)
	$(CXX) -o $(dest)$@ $^ $(LDFLAGS)

clean:
	$(RM) *~ $(srco)*.o

mrproper: clean
	$(RM) $(dest)osbr

depend:
	makedepend $(src)
