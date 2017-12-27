
CPP=g++
CPPFLAGS=-Wall -g -std=c++11 -I../Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../Headers
SRCS=Network.cpp

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

Network.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
Network.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
Network.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
