#include "XmlSerializationExceptionTests.hpp"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( XmlSerializationExceptionTests ); 

void 
XmlSerializationExceptionTests::setUp() 
{ 
} 


void 
XmlSerializationExceptionTests::tearDown() 
{ 
} 


void XmlSerializationExceptionTests::testConstructor() 
{ 
  XmlSerializationException aDefault;
  XmlSerializationException aArg("Blah");
  
  CPPUNIT_ASSERT( strcmp(aDefault.what(), "XmlSerializationException" ) == 0);
  CPPUNIT_ASSERT( strcmp(aArg.what(), "Blah") == 0);
}

