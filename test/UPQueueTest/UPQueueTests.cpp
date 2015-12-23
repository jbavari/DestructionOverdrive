#include "UPQueueTests.hpp"
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
CPPUNIT_TEST_SUITE_REGISTRATION( UPQueueTests ); 

void 
UPQueueTests::setUp() 
{ 
} 


void 
UPQueueTests::tearDown() 
{ 
} 


void 
UPQueueTests::testConstructor() 
{
  UPQueue a;
}


void 
UPQueueTests::testCopyConstructor()
{
  Message* m1 = new Message(0, 0, "blah");
  Message* m2 = 0;
  UPQueue a;
  a.enq(m1);
  UPQueue b(a);

  m2 = b.deq();
  
  /** operator== on Message */
  CPPUNIT_ASSERT(*m2 == *m1);

  /** Pointer comparison to ensure the message was copied. */
  CPPUNIT_ASSERT(m2 != m1);
}


/**
 * Tests basic enqueue and dequeue functionality.
 * especially the ordering of the messages.  It does
 * not test messages that have a duplicate and should
 * be removed.
 */
void 
UPQueueTests::testEnq()
{
  /**
   * Messages are in the order they should come off.
   */
  Message* mArray[6];


  mArray[0] = new Message(0, 500000, "blah");
  mArray[1] = new Message(1, 500000, "blah");
  mArray[2] = new Message(2, 500000, "blah");
  mArray[3] = new Message(0, 500001, "blah");
  mArray[4] = new Message(1, 500001, "blah");
  mArray[5] = new Message(0, 500002, "blah");

  UPQueue a;
  
  a.enq(mArray[5]);
  a.enq(mArray[4]);
  a.enq(mArray[2]);
  a.enq(mArray[3]);
  a.enq(mArray[1]);
  a.enq(mArray[0]);

  for ( int i = 0; i < 6; i++ )
    {
      Message* mp = a.deq();
      CPPUNIT_ASSERT( *mp == *(mArray[i]) );
      delete mp;
    }
}


/**
 * Tests enqueu and dequeue of messages that
 * are duplicates.  That are not combat unit messages,
 * and that are combat unit messages, ensuring that the
 * proper order is dequeued.
 */
void 
UPQueueTests::testDupeEnq()
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

  UPQueue a;
  
  a.enq(mArray[5]);
  a.enq(mArray[4]);
  a.enq(mArray[2]);
  a.enq(mArray[3]);
  a.enq(mArray[1]);
  a.enq(mArray[0]);

  for ( int i = 0; i < 5; i++ )
    {
      Message* mp = a.deq();
      
      cerr<<"mp->senderPid: "<< mp->getSenderPid() << endl;
      cerr<<"mp->mIdend: "<< mp->getMIdent() << endl;

      CPPUNIT_ASSERT( *mp == *(mArray[i]) );
      delete mp;
    }

  CPPUNIT_ASSERT ( a.deq() == 0 );
}

