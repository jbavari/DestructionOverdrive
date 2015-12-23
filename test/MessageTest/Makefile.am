TESTS = check_Message
check_PROGRAMS = check_Message


check_Message_SOURCES = 	check_Message.cpp \
				@top_srcdir@/include/Message.h \
				MessageTests.hpp \
				MessageTests.cpp

check_Message_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_Message_LDFLAGS = $(CPPUNIT_LIBS)
check_Message_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la