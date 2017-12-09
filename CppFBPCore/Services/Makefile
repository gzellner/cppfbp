
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../Headers
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

CppFBP.o: ../Headers/thxdef.h ../Headers/thxanch.h ../Headers/thzcbs.h
CppSub.o: ../Headers/thxdef.h ../Headers/thxanch.h ../Headers/thzcbs.h
thxbnet.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thxbnet.o: ../Headers/cppfbp.h ../Headers/fbp.h
thxgatrs.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thxgatrs.o: ../Headers/cppfbp.h ../Headers/fbp.h
thxscan.o: ../Headers/cppfbp.h ../Headers/thxanch.h ../Headers/fbp.h
thxscan.o: ../Headers/thzcbs.h ../Headers/thxdef.h
thz.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thz.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzclos.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzclos.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzcrep.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzcrep.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzdfpt.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzdfpt.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzdrop.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzdrop.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzelct.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzelct.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzgsize.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzgsize.o: ../Headers/cppfbp.h ../Headers/fbp.h
thziclos.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thziclos.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzpop.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzpop.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzpush.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzpush.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzrecv.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzrecv.o: ../Headers/cppfbp.h ../Headers/fbp.h
thzsend.o: ../Headers/thzcbs.h ../Headers/thxdef.h ../Headers/thxanch.h
thzsend.o: ../Headers/cppfbp.h ../Headers/fbp.h
