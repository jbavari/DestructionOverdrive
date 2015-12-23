#ifndef LD_UPQUEUETESTS_H
#define LD_UPQUEUETESTS_H 1

#include "UPQueue.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class UPQueueTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( UPQueueTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCopyConstructor );
  CPPUNIT_TEST( testEnq );
  CPPUNIT_TEST( testDupeEnq );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testCopyConstructor();
  void testEnq();
  void testDupeEnq();
};

#endif
