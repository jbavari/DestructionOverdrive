TESTS = check_ECM
check_PROGRAMS = check_ECM


check_ECM_SOURCES = 	main.cpp \
			@top_srcdir@/include/ECM.h

check_ECM_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_ECM_LDFLAGS = $(CPPUNIT_LIBS)
check_ECM_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la