TESTS = check_CombatUnit
check_PROGRAMS = check_CombatUnit


check_CombatUnit_SOURCES = 	check_CombatUnit.cpp \
				@top_srcdir@/include/CombatUnit.h \
				CombatUnitTests.hpp \
				CombatUnitTests.cpp

check_CombatUnit_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_CombatUnit_LDFLAGS = $(CPPUNIT_LIBS)
check_CombatUnit_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la