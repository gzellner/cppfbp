
CPP=g++
CPPFLAGS=-Wall -g -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=InfQueue.cpp

OBJS=$(SRCS:.cpp=.o)

.PHONY: clean

all: $(OBJS)

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *~

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it.

InfQueue.o: ../../CppFBPCore/Headers/thxdef.h
InfQueue.o: ../../CppFBPCore/Headers/thxanch.h
