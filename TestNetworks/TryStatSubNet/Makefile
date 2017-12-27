
CPP=g++
CPPFLAGS=-Wall -g -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system -lboost_thread -lboost_chrono
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=TryStatSubNet.cpp
PROG=trystat

OBJCPP=$(wildcard ../../CppFBPCore/Services/*.cpp) $(wildcard ../../CppFBPCore/intcomps/*.cpp) ../../CppFBPComponents/Components/SubIn.cpp ../../CppFBPComponents/Components/SubOut.cpp ../../CppFBPComponents/Components/ThFileRd.cpp ../../CppFBPComponents/Components/ThFileWt.cpp ../../CppFBPComponents/Components/ThCopyNL.cpp ../../TestSubnets/Subnets/InfQueue.cpp $(wildcard ../../CppFBPComponents/Helper_Code/*.cpp)

OBJ=$(OBJCPP:.cpp=.o)
OBJS=$(SRCS:.cpp=.o)

.PHONY: depend clean

all: $(PROG)

$(PROG): $(OBJ) $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(PROG) $(OBJS) $(OBJ) $(LIBS)

.cpp.o:
	$(MAKE) -C ../../CppFBPCore/Services
	$(MAKE) -C ../../CppFBPCore/intcomps
	$(MAKE) -C ../../CppFBPComponents/Components
	$(MAKE) -C ../../TestSubnets/Subnets
	$(MAKE) -C ../../CppFBPComponents/Helper_Code
	$(CPP) $(CPPFLAGS) -c $(SRCS) # $<



clean:
	rm -f *.o *~ $(PROG)
	$(MAKE) -C ../../CppFBPCore/Services clean
	$(MAKE) -C ../../CppFBPCore/intcomps clean
	$(MAKE) -C ../../CppFBPComponents/Components clean
	$(MAKE) -C ../../CppFBPComponents/Helper_Code clean

depend: $(OBJCPP) $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it.

../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzclos.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thziclos.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thxgatrs.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzpush.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzdrop.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thxscan.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzsend.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/thxdef.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/CppFBP.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzdfpt.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/thxdef.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/CppSub.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzcrep.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thz.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzgsize.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thxbnet.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzpop.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzrecv.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/Services/thzelct.o: ../../CppFBPCore/Headers/network.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/cppfbp.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/cdl.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/ip.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/cnxt.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/port.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/process.h
../../CppFBPCore/intcomps/Network.o: ../../CppFBPCore/Headers/network.h
../../CppFBPComponents/Components/ThFileRd.o: ../../CppFBPCore/Headers/compsvcs.h
../../CppFBPComponents/Components/ThFileRd.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPComponents/Components/ThFileWt.o: ../../CppFBPCore/Headers/compsvcs.h
../../CppFBPComponents/Components/ThFileWt.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPComponents/Components/ThCopyNL.o: ../../CppFBPCore/Headers/compsvcs.h
../../CppFBPComponents/Components/ThCopyNL.o: ../../CppFBPCore/Headers/thxanch.h
../../CppFBPComponents/Helper_Code/dfs.o: ../../CppFBPCore/Headers/thxanch.h
CopyFile.o: ../../CppFBPCore/Headers/thxdef.h
CopyFile.o: ../../CppFBPCore/Headers/thxanch.h
