#ifndef OUTOFDOMAINEXCEPTION_BASICTESTS_H
#define OUTOFDOMAINEXCEPTION_BASICTESTS_H 1

#include "Power.h"
#include "PowerSuppliable.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class PowerSuppliableTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( PowerSuppliableTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testSetPowerSupplied );
  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testGetXmlChar );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp();
  void tearDown();
  
  void testConstructor();
  void testSetPowerSupplied();
  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
