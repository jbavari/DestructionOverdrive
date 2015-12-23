#include "NetworkTests.hpp"
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
CPPUNIT_TEST_SUITE_REGISTRATION( NetworkTests ); 

void 
NetworkTests::setUp() 
{ 
} 


void 
NetworkTests::tearDown() 
{ 
} 


void 
NetworkTests::testConstructor() 
{
  Network a;
}




/**
 * Tests enqueu and dequeue of messages that
 * are duplicates.  That are not combat unit messages,
 * and that are combat unit messages, ensuring that the
 * proper order is dequeued.
 *
 * This only works with the local host right now,
 * and it doesn't even send through the local host yet.
 * it's just a message queue for expansion next week.
 */
void 
NetworkTests::testSend()
{
  /**
   * Messages are in the order they should come off.
   */
  Message* mArray[6];
  CombatUnitId* cuArray[6];

  cuArray[0] = new CombatUnitId(0, 10);
  cuArray[1] = new CombatUnitId(1, 20);
  cuArray[2] = new CombatUnitId(2, 10);
  cuArray[3] = new CombatUnitId(1, 10);
  cuArray[4] = new CombatUnitId(2, 20);
  cuArray[5] = new CombatUnitId(1, 10);

  mArray[0] = new Message(0, 0, "blah", *(cuArray[0]));
  mArray[1] = new Message(1, 0, "blah", *(cuArray[1]));
  mArray[2] = new Message(2, 0, "blah", *(cuArray[2]));
  mArray[3] = new Message(0, 1, "blah", *(cuArray[3]));
  mArray[4] = new Message(1, 1, "blah", *(cuArray[4]));
  mArray[5] = new Message(0, 1, "blah", *(cuArray[5]));

  Network a;
  
  a.sendMessage(0, mArray[5]);
  a.sendMessage(0, mArray[4]);
  a.sendMessage(0, mArray[2]);
  a.sendMessage(0, mArray[3]);
  a.sendMessage(0, mArray[1]);
  a.sendMessage(0, mArray[0]);

  for ( int i = 0; i < 5; i++ )
    {
      Message* mp = a.getMessage();
      
      CPPUNIT_ASSERT( *mp == *(mArray[i]) );
      delete mp;
    }

  CPPUNIT_ASSERT ( a.getMessage() == 0 );
}

