TESTS = check_DumbMovement
check_PROGRAMS = check_DumbMovement


check_DumbMovement_SOURCES = 	check_DumbMovement.cpp \
				@top_srcdir@/include/DumbMovement.h \
				DumbMovementTests.hpp \
				DumbMovementTests.cpp

check_DumbMovement_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_DumbMovement_LDFLAGS = $(CPPUNIT_LIBS)
check_DumbMovement_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la