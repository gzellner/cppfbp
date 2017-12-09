
CPP=g++
CPPFLAGS=-Wall -std=c++11 -I../../CppFBPCore/Headers
LIBS=-lpthread -lboost_system -lboost_thread -lboost_chrono
INCLUDES=-Y../../CppFBPCore/Headers
SRCS=CopyFile.cpp
PROG=copyfile

OBJCPP=$(wildcard ../../CppFBPCore/Services/*.cpp) $(wildcard ../../CppFBPCore/intcomps/*.cpp) ../../CppFBPComponents/Components/ThFileRd.cpp ../../CppFBPComponents/Components/ThFileWt.cpp ../../CppFBPComponents/Components/ThCopyNL.cpp $(wildcard ../../CppFBPComponents/Helper_Code/*.cpp)

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
	$(MAKE) -C ../../CppFBPComponents/Helper_Code
	$(CPP) $(CPPFLAGS) -c $<



clean:
	rm -f *.o *~ $(PROG)
	$(MAKE) -C ../../CppFBPCore/Services clean
	$(MAKE) -C ../../CppFBPCore/intcomps clean
	$(MAKE) -C ../../CppFBPComponents/Components clean
	$(MAKE) -C ../../CppFBPComponents/Helper_Code clean

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it.

CopyFile.o: ../../CppFBPCore/Headers/thxdef.h
CopyFile.o: ../../CppFBPCore/Headers/thxanch.h
