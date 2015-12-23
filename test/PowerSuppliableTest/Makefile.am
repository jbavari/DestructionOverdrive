TESTS = check_PowerSuppliable
check_PROGRAMS = check_PowerSuppliable


check_PowerSuppliable_SOURCES = 	check_PowerSuppliable.cpp \
					@top_srcdir@/include/PowerSuppliable.h \
					PowerSuppliableTests.hpp \
					PowerSuppliableTests.cpp

check_PowerSuppliable_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_PowerSuppliable_LDFLAGS = $(CPPUNIT_LIBS)
check_PowerSuppliable_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la