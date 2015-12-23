TESTS = check_CombatUnitId
check_PROGRAMS = check_CombatUnitId


check_CombatUnitId_SOURCES = 	check_CombatUnitId.cpp \
				@top_srcdir@/include/CombatUnitId.h \
				CombatUnitIdTests.hpp \
				CombatUnitIdTests.cpp

check_CombatUnitId_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_CombatUnitId_LDFLAGS = $(CPPUNIT_LIBS)
check_CombatUnitId_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la