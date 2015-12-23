TESTS = check_Capacitor
check_PROGRAMS = check_Capacitor


check_Capacitor_SOURCES = 	check_Capacitor.cpp \
				@top_srcdir@/include/Capacitor.h \
				CapacitorTests.hpp \
				CapacitorTests.cpp

check_Capacitor_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Capacitor_LDFLAGS = $(CPPUNIT_LIBS)
check_Capacitor_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la