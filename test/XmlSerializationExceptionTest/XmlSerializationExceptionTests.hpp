#ifndef XMLSERIALIZATIONEXCEPTION_TESTS_H
#define XMLSERIALIZATIONEXCEPTION_TESTS_H 1

#include "XmlSerializationException.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;



class XmlSerializationExceptionTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( XmlSerializationExceptionTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp();
  void tearDown();
  
  void testConstructor();
};

#endif
