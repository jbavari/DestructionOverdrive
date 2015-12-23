#ifndef LD_DAMAGETYPETESTS_H
#define LD_DAMAGETYPETESTS_H 1

#include "Damage.h"
#include <cppunit/extensions/HelperMacros.h>
#include <iostream>
using std::ostream;

using namespace LightningDev;


class DamageTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( DamageTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testGetXmlChar );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();


  void getDoc(ostream& ref);
  
public:
  void setUp();
  void tearDown();

  void testConstructor();
  

  /**********************************************
   *          XmlSerialization stuff            *
   *********************************************/

  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
