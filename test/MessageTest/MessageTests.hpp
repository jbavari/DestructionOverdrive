#ifndef LD_CAPACITORTESTS_H
#define LD_CAPACITORTESTS_H 1

#include "Message.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class MessageTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( MessageTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCopyConstructor );
  CPPUNIT_TEST( testEquals );
  CPPUNIT_TEST( testNEquals );
  CPPUNIT_TEST( testGT );
  CPPUNIT_TEST( testLT );
  CPPUNIT_TEST_SUITE_END();


public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testCopyConstructor();
  void testEquals();
  void testNEquals();
  void testGT();
  void testLT();
  

  /**********************************************
   *          XmlSerialization stuff            *
   *********************************************/

  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
