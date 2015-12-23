TESTS = check_XmlSerialization
check_PROGRAMS = check_XmlSerialization


check_XmlSerialization_SOURCES = 	check_XmlSerialization.cpp \
					@top_srcdir@/include/XmlSerialization.h \
					XmlSerializationFixture.hpp \
					XmlSerializationFixture.cpp

check_XmlSerialization_CXXFLAGS = $(CPPUNIT_CFLAGS) @LIBXML2_CFLAGS@ -I@top_srcdir@/include/
check_XmlSerialization_LDFLAGS = $(CPPUNIT_LIBS)
check_XmlSerialization_LDADD = -ldl @LIBXML2_LIBS@ @top_srcdir@/lib/libdoverdrive.la