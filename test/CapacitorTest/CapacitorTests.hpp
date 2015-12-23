#ifndef LD_CAPACITORTESTS_H
#define LD_CAPACITORTESTS_H 1

#include "Capacitor.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class CapacitorTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( CapacitorTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testDisscharge );
  CPPUNIT_TEST_EXCEPTION( testIntDissExcept, InsufficientPowerException );
  CPPUNIT_TEST_EXCEPTION( testPowerDissExcept, InsufficientPowerException );

  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testGetXmlChar );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();


  void getDoc(ostream& ref);
  
public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testDisscharge();
  void testIntDissExcept();
  void testPowerDissExcept();
  

  /**********************************************
   *          XmlSerialization stuff            *
   *********************************************/

  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
