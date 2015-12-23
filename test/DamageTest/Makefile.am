TESTS = check_Damage
check_PROGRAMS = check_Damage


check_Damage_SOURCES = 	check_Damage.cpp \
			@top_srcdir@/include/Damage.h \
			DamageTests.hpp \
			DamageTests.cpp

check_Damage_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Damage_LDFLAGS = $(CPPUNIT_LIBS)
check_Damage_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la