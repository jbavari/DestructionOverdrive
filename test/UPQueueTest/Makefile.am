TESTS = check_UPQueue
check_PROGRAMS = check_UPQueue


check_UPQueue_SOURCES = 	check_UPQueue.cpp \
				@top_srcdir@/include/UPQueue.h \
				UPQueueTests.hpp \
				UPQueueTests.cpp

check_UPQueue_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_UPQueue_LDFLAGS = $(CPPUNIT_LIBS)
check_UPQueue_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la