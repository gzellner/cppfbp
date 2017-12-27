
CPP=g++
CPPFLAGS=-Wall -g -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=$(wildcard *.cpp)

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

SubIn.o: ../../CppFBPCore/Headers/compsvcs.h
SubIn.o: ../../CppFBPCore/Headers/thxanch.h ../../CppFBPCore/Headers/cppfbp.h
SubIn.o: ../../CppFBPCore/Headers/thxdef.h ../../CppFBPCore/Headers/cdl.h
SubIn.o: ../../CppFBPCore/Headers/ip.h ../../CppFBPCore/Headers/cnxt.h
SubIn.o: ../../CppFBPCore/Headers/port.h ../../CppFBPCore/Headers/process.h
SubIn.o: ../../CppFBPCore/Headers/network.h
ThCopyNL.o: ../../CppFBPCore/Headers/compsvcs.h
ThCopyNL.o: ../../CppFBPCore/Headers/thxanch.h
ThGenIps.o: ../../CppFBPCore/Headers/compsvcs.h
ThGenIps.o: ../../CppFBPCore/Headers/thxanch.h
ThReplStr.o: ../../CppFBPCore/Headers/compsvcs.h
ThReplStr.o: ../../CppFBPCore/Headers/thxanch.h
ThSort.o: ../../CppFBPCore/Headers/compsvcs.h
ThSort.o: ../../CppFBPCore/Headers/thxanch.h
ThConcatStr.o: ../../CppFBPCore/Headers/compsvcs.h
ThConcatStr.o: ../../CppFBPCore/Headers/thxanch.h
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
ThLua.o: ../../CppFBPLua/src/lua.h ../../CppFBPLua/src/luaconf.h
ThLua.o: ../../CppFBPLua/src/lualib.h ../../CppFBPLua/src/lua.h
ThLua.o: ../../CppFBPLua/src/lauxlib.h ../../CppFBPCore/Headers/compsvcs.h
ThLua.o: ../../CppFBPCore/Headers/thxanch.h
SubOut.o: ../../CppFBPCore/Headers/compsvcs.h
SubOut.o: ../../CppFBPCore/Headers/thxanch.h
SubOut.o: ../../CppFBPCore/Headers/cppfbp.h ../../CppFBPCore/Headers/thxdef.h
SubOut.o: ../../CppFBPCore/Headers/cdl.h ../../CppFBPCore/Headers/ip.h
SubOut.o: ../../CppFBPCore/Headers/cnxt.h ../../CppFBPCore/Headers/port.h
SubOut.o: ../../CppFBPCore/Headers/process.h
SubOut.o: ../../CppFBPCore/Headers/network.h
