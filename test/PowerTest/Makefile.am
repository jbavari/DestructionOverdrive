TESTS = check_Power
check_PROGRAMS = check_Power


check_Power_SOURCES = 	check_Power.cpp \
			@top_srcdir@/include/Power.h \
			BasicTests.hpp \
			BasicTests.cpp

check_Power_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Power_LDFLAGS = $(CPPUNIT_LIBS)
check_Power_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la