
CPP=g++
CPPFLAGS=-Wall -g -std=c++11 -I../Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../Headers
SRCS=CppFBP.cpp CppSub.cpp thxbnet.cpp thxgatrs.cpp thxscan.cpp thz.cpp thzclos.cpp thzcrep.cpp thzdfpt.cpp thzdrop.cpp thzelct.cpp thzgsize.cpp thziclos.cpp thzpop.cpp thzpush.cpp thzrecv.cpp thzsend.cpp

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

CppFBP.o: ../Headers/thxdef.h ../Headers/thxanch.h ../Headers/cppfbp.h
CppFBP.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
CppFBP.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
CppSub.o: ../Headers/thxdef.h ../Headers/thxanch.h ../Headers/cppfbp.h
CppSub.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
CppSub.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thxbnet.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thxbnet.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thxbnet.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thxgatrs.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thxgatrs.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thxgatrs.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thxscan.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thxscan.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thxscan.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thz.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thz.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h ../Headers/port.h
thz.o: ../Headers/process.h ../Headers/network.h
thzclos.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzclos.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzclos.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzcrep.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzcrep.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzcrep.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzdfpt.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzdfpt.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzdfpt.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzdrop.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzdrop.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzdrop.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzelct.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzelct.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzelct.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzgsize.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzgsize.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzgsize.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thziclos.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thziclos.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thziclos.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzpop.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzpop.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzpop.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzpush.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzpush.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzpush.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzrecv.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzrecv.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzrecv.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
thzsend.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/thxdef.h
thzsend.o: ../Headers/cdl.h ../Headers/ip.h ../Headers/cnxt.h
thzsend.o: ../Headers/port.h ../Headers/process.h ../Headers/network.h
