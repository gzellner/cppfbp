
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=dfs.cpp

OBJS=$(SRCS:.cpp=.o)

.PHONY: clean

all: $(OBJS)

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *~
