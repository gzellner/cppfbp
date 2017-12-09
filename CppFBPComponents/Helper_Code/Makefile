
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=dfs.cpp

OBJS=$(SRCS:.cpp=.o)

.PHONY: depend clean

all: $(OBJS)

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *~

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it.

dfs.o: ../../CppFBPCore/Headers/thxanch.h
