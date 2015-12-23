TESTS = check_DamageType
check_PROGRAMS = check_DamageType


check_DamageType_SOURCES = 	check_DamageType.cpp \
				@top_srcdir@/include/DamageType.h \
				DamageTypeTests.hpp \
				DamageTypeTests.cpp

check_DamageType_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_DamageType_LDFLAGS = $(CPPUNIT_LIBS)
check_DamageType_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la