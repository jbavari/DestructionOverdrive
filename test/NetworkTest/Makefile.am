TESTS = check_Network
check_PROGRAMS = check_Network


check_Network_SOURCES = 	check_Network.cpp \
				@top_srcdir@/include/Network.h \
				NetworkTests.hpp \
				NetworkTests.cpp

check_Network_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Network_LDFLAGS = $(CPPUNIT_LIBS)
check_Network_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la