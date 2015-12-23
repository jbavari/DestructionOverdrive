TESTS = check_XmlSerializationException
check_PROGRAMS = check_XmlSerializationException


check_XmlSerializationException_SOURCES = 	check_XmlSerializationException.cpp \
					@top_srcdir@/include/XmlSerializationException.h \
					XmlSerializationExceptionTests.hpp \
					XmlSerializationExceptionTests.cpp

check_XmlSerializationException_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_XmlSerializationException_LDFLAGS = $(CPPUNIT_LIBS)
check_XmlSerializationException_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la