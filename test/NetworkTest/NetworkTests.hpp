#ifndef LD_NETWORKTESTS_H
#define LD_NETWORKTESTS_H 1

#include "Network.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class NetworkTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( NetworkTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testSend );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testSend();
};

#endif
