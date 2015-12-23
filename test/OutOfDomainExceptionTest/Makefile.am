TESTS = check_OutOfDomainException
check_PROGRAMS = check_OutOfDomainException


check_OutOfDomainException_SOURCES = 	check_OutOfDomainException.cpp \
					@top_srcdir@/include/OutOfDomainException.h \
					BasicTests.hpp \
					BasicTests.cpp

check_OutOfDomainException_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_OutOfDomainException_LDFLAGS = $(CPPUNIT_LIBS)
check_OutOfDomainException_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la