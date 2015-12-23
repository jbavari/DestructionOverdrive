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
  OutOfDomainException aDefault;
  OutOfDomainException aArg("Blah");
  
  CPPUNIT_ASSERT( strcmp(aDefault.what(), "OutOfDomainException" ) == 0);
  CPPUNIT_ASSERT( strcmp(aArg.what(), "Blah") == 0);
}

