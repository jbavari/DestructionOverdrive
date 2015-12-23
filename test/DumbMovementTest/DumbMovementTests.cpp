#include "DumbMovementTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
#include <string>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;
using std::string;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( DumbMovementTests ); 

void 
DumbMovementTests::setUp() 
{ 
} 


void 
DumbMovementTests::tearDown() 
{ 
} 


void 
DumbMovementTests::testConstructor() 
{
  DumbMovement a(network);
}

void
DumbMovementTests::testKup()
{
  DumbMovement a(network);
  Message* movMessage;
  a.kup();
  
  movMessage = network.getMessage();
  
  CPPUNIT_ASSERT(movMessage != 0);
  CPPUNIT_ASSERT(movMessage->getMIdent() == 16);
  CPPUNIT_ASSERT(strcmp(movMessage->getContents().c_str(), "-10") == 0);

  delete movMessage;
}

void
DumbMovementTests::testKdown()
{
  DumbMovement a(network);
  Message* movMessage;
  a.kdown();
  
  movMessage = network.getMessage();
  
  CPPUNIT_ASSERT(movMessage != 0);
  CPPUNIT_ASSERT(movMessage->getMIdent() == 16);
  CPPUNIT_ASSERT(strcmp(movMessage->getContents().c_str(), "10") == 0);

  delete movMessage;
}

void 
DumbMovementTests::testKleft()
{
  DumbMovement a(network);
  Message* movMessage;
  a.kleft();
  
  movMessage = network.getMessage();
  
  CPPUNIT_ASSERT(movMessage != 0);
  CPPUNIT_ASSERT(movMessage->getMIdent() == 15);
  CPPUNIT_ASSERT(strcmp(movMessage->getContents().c_str(), "-10") == 0);
  
  delete movMessage;
}


void 
DumbMovementTests::testKright()
{
  DumbMovement a(network);
  Message* movMessage;
  a.kright();
  
  movMessage = network.getMessage();
  
  CPPUNIT_ASSERT(movMessage != 0);
  CPPUNIT_ASSERT(movMessage->getMIdent() == 15);
  CPPUNIT_ASSERT(strcmp(movMessage->getContents().c_str(), "10") == 0);

  delete movMessage;
}


void 
DumbMovementTests::testIncThrust()
{
  DumbMovement a(network);
  Message* movMessage;
  a.incThrust();

  movMessage = network.getMessage();

  CPPUNIT_ASSERT(movMessage == 0);
}

void 
DumbMovementTests::testDecThrust()
{
  DumbMovement a(network);
  Message* movMessage;
  a.decThrust();

  movMessage = network.getMessage();
  CPPUNIT_ASSERT(movMessage == 0);
}






