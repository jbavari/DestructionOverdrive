TESTS = check_Module
check_PROGRAMS = check_Module


check_Module_SOURCES = 	main.cpp \
			@top_srcdir@/include/Module.h

check_Module_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Module_LDFLAGS = $(CPPUNIT_LIBS)
check_Module_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la