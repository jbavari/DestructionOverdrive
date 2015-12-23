#ifndef LD_DUMBMOVEMENTTESTS_H
#define LD_DUMBMOVEMENTTESTS_H 1

#include "DumbMovement.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class DumbMovementTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( DumbMovementTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testKup );
  CPPUNIT_TEST( testKdown );
  CPPUNIT_TEST( testKleft );
  CPPUNIT_TEST( testKright );
  CPPUNIT_TEST( testIncThrust );
  CPPUNIT_TEST( testDecThrust );
  CPPUNIT_TEST_SUITE_END();

  Network network;
public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testKup();
  void testKdown();
  void testKleft();
  void testKright();
  void testIncThrust();
  void testDecThrust();
};

#endif
