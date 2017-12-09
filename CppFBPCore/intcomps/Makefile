
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../Headers
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

Network.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
Network.o: ../Headers/cppfbp.h ../Headers/fbp.h
