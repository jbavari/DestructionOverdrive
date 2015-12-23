#ifndef LD_DAMAGETYPETESTS_H
#define LD_DAMAGETYPETESTS_H 1

#include "DamageType.h"
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using std::ostream;

using namespace LightningDev;


class DamageTypeTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( DamageTypeTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testGetRadiant );
  CPPUNIT_TEST_EXCEPTION ( testConstructExecptLow, OutOfDomainException );
  CPPUNIT_TEST_EXCEPTION ( testConstructExceptHigh, OutOfDomainException );

  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testGetXmlChar );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();


  void getDoc(ostream& ref);
  
public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testConstructExecptLow();
  void testConstructExceptHigh();

  void testGetRadiant();

  /**********************************************
   *          XmlSerialization stuff            *
   *********************************************/

  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
