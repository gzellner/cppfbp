
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../Headers
SRCS=CppFBP.cpp CppSub.cpp thxbnet.cpp thxgatrs.cpp thxscan.cpp thz.cpp thzclos.cpp thzcrep.cpp thzdfpt.cpp thzdrop.cpp thzelct.cpp thzgsize.cpp thziclos.cpp thzpop.cpp thzpush.cpp thzrecv.cpp thzsend.cpp

OBJS=$(SRCS:.cpp=.o)

.PHONY: clean

all: $(OBJS)

.cpp.o:
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *~

