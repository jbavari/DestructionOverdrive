#include "BasicTests.hpp"


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BasicTests ); 

void 
BasicTests::setUp() 
{ 
} 


void 
BasicTests::tearDown() 
{ 
} 


void BasicTests::testConstructor() 
{ 
  LDException aDefault;
  LDException aArg("Blah");
  
  CPPUNIT_ASSERT( strcmp(aDefault.what(), "LDException" ) == 0);
  CPPUNIT_ASSERT( strcmp(aArg.what(), "Blah") == 0);
}

