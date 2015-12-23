TESTS = check_LDException
check_PROGRAMS = check_LDException


check_LDException_SOURCES = 	check_LDException.cpp \
				@top_srcdir@/include/LDException.h \
				BasicTests.hpp \
				BasicTests.cpp

check_LDException_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_LDException_LDFLAGS = $(CPPUNIT_LIBS)
check_LDException_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la