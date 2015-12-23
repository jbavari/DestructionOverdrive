#include "MessageTests.hpp"
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
CPPUNIT_TEST_SUITE_REGISTRATION( MessageTests ); 

void 
MessageTests::setUp() 
{ 
} 


void 
MessageTests::tearDown() 
{ 
} 


void 
MessageTests::testConstructor() 
{
  string msgString("Blah it's a message");
  CombatUnitId cu(12, 16);
  Message a(5, 6, msgString);
  Message b(5, 6, msgString, cu);


  CPPUNIT_ASSERT(a.getSenderPid() == 5);
  CPPUNIT_ASSERT(a.getMIdent() == 6);
  CPPUNIT_ASSERT(msgString == string(a.getContents()));
  CPPUNIT_ASSERT(b.getSenderPid() == 5);
  CPPUNIT_ASSERT(b.getMIdent() == 6);
  CPPUNIT_ASSERT(msgString == string(a.getContents()));
  CPPUNIT_ASSERT(b.getCombUnitId() == cu);
}


void 
MessageTests::testCopyConstructor()
{
  string msgString("Blah it's a message");
  CombatUnitId cu(12, 16);  
  Message a(5, 6, msgString, cu);
  Message b(a);
  
  CPPUNIT_ASSERT(a.getSenderPid() == b.getSenderPid());
  CPPUNIT_ASSERT(a.getMIdent() == b.getMIdent());
  CPPUNIT_ASSERT(string(b.getContents()) == string(a.getContents()));
  CPPUNIT_ASSERT(a.getCombUnitId() == b.getCombUnitId());
}

void 
MessageTests::testEquals()
{
  /**
   * Messages must have identical mIdents AND senderIds to be
   * equivilant.  The contents make no difference.
   */
  string msgString("Blah it's a message");
  Message a(5, 6, msgString);
  Message b(5, 6, "ARGLE");
  Message c(5, 7, msgString);
  Message d(6, 6, msgString);
  
  CPPUNIT_ASSERT(a == b);
  CPPUNIT_ASSERT(!(c == b));
  CPPUNIT_ASSERT(!(d == b));
  CPPUNIT_ASSERT(!(c == d));
  CPPUNIT_ASSERT(!(d == a));
}


void 
MessageTests::testNEquals()
{
  /**
   * Messages must have identical mIdents AND senderIds to be
   * equivilant.  The contents make no difference.
   */
  string msgString("Blah it's a message");
  Message a(5, 6, msgString);
  Message b(5, 6, "ARGLE");
  Message c(5, 7, msgString);
  Message d(6, 6, msgString);
  
  CPPUNIT_ASSERT(!(a != b));
  CPPUNIT_ASSERT(c != b);
  CPPUNIT_ASSERT(d != b);
  CPPUNIT_ASSERT(c != d);
  CPPUNIT_ASSERT(d != a);
}


void 
MessageTests::testGT()
{
  /**
   * Messages are greater and less than based on message ident only
   */
  string msgString("Blah it's a message");
  Message a(5, 6, msgString);
  Message b(6, 6, "ARGLE");
  Message c(5, 7, "ARGLE");

  CPPUNIT_ASSERT( !(a > b) );
  CPPUNIT_ASSERT( c > b );
  CPPUNIT_ASSERT( !(b > c) );
}

void 
MessageTests::testLT()
{
  /**
   * Messages are greater and less than based on message ident only
   */
  string msgString("Blah it's a message");
  Message a(5, 6, msgString);
  Message b(6, 6, "ARGLE");
  Message c(5, 7, "ARGLE");

  CPPUNIT_ASSERT( a < b );
  CPPUNIT_ASSERT( b < c );
  CPPUNIT_ASSERT( !(c < b) );
}



