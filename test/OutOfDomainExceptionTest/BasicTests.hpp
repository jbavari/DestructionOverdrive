#ifndef OUTOFDOMAINEXCEPTION_BASICTESTS_H
#define OUTOFDOMAINEXCEPTION_BASICTESTS_H 1

#include "OutOfDomainException.h"
#include <cppunit/extensions/HelperMacros.h>

using LightningDev::OutOfDomainException;



class BasicTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( BasicTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp();
  void tearDown();
  
  void testConstructor();
};

#endif
