CXXFLAGS = -Wall -Werror
LDFLAGS = -lboost_signals


.PHONY:	all clean


all:	SigProto1 SigProto2

SigProto1:	SigProto1.o
		g++ $(CXXFLAGS) $(LDFLAGS) -o SigProto1 SigProto1.o

SigProto1.o:	SigProto1.cpp
		g++ $(CXXFLAGS) -c -o SigProto1.o SigProto1.cpp

SigProto2:	SigProto2.o
		g++ $(CXXFLAGS) $(LDFLAGS) -o SigProto2 SigProto2.o

SigProto2.o:	SigProto2.cpp
		g++ $(CXXFLAGS) -c -o SigProto2.o SigProto2.cpp


test:		SigProto2
		./SigProto2

clean:
		rm -f *.o
		rm -f SigProto1