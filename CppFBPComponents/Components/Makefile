
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=$(wildcard *.cpp)

OBJS=$(SRCS:.cpp=.o)

.PHONY: depend clean

all: $(OBJS)
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f *.o *~

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it.

SubIn.o: ../../CppFBPCore/Headers/compsvcs.h
SubIn.o: ../../CppFBPCore/Headers/thxanch.h ../../CppFBPCore/Headers/thzcbs.h
SubIn.o: ../../CppFBPCore/Headers/thxdef.h
ThCopyNL.o: ../../CppFBPCore/Headers/compsvcs.h
ThCopyNL.o: ../../CppFBPCore/Headers/thxanch.h
ThGenIps.o: ../../CppFBPCore/Headers/compsvcs.h
ThGenIps.o: ../../CppFBPCore/Headers/thxanch.h
ThConcatStr.o: ../../CppFBPCore/Headers/compsvcs.h
ThConcatStr.o: ../../CppFBPCore/Headers/thxanch.h
ThReplStr.o: ../../CppFBPCore/Headers/compsvcs.h
ThReplStr.o: ../../CppFBPCore/Headers/thxanch.h
ThSort.o: ../../CppFBPCore/Headers/compsvcs.h
ThSort.o: ../../CppFBPCore/Headers/thxanch.h
ThFileRd.o: ../../CppFBPCore/Headers/compsvcs.h
ThFileRd.o: ../../CppFBPCore/Headers/thxanch.h
ThCopy.o: ../../CppFBPCore/Headers/compsvcs.h
ThCopy.o: ../../CppFBPCore/Headers/thxanch.h
ThRevers.o: ../../CppFBPCore/Headers/compsvcs.h
ThRevers.o: ../../CppFBPCore/Headers/thxanch.h
ThDrop.o: ../../CppFBPCore/Headers/compsvcs.h
ThDrop.o: ../../CppFBPCore/Headers/thxanch.h
ThPsThru.o: ../../CppFBPCore/Headers/compsvcs.h
ThPsThru.o: ../../CppFBPCore/Headers/thxanch.h
ThFileWt.o: ../../CppFBPCore/Headers/compsvcs.h
ThFileWt.o: ../../CppFBPCore/Headers/thxanch.h
ThLua.o: ../../CppFBPCore/Headers/compsvcs.h
ThLua.o: ../../CppFBPCore/Headers/thxanch.h
SubOut.o: ../../CppFBPCore/Headers/compsvcs.h
SubOut.o: ../../CppFBPCore/Headers/thxanch.h
SubOut.o: ../../CppFBPCore/Headers/thzcbs.h ../../CppFBPCore/Headers/thxdef.h
