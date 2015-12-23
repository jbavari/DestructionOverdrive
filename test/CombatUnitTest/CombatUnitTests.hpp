#ifndef LD_COMBATUNITTESTS_H
#define LD_COMBATUNITTESTS_H 1

#include "CombatUnit.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class CombatUnitTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( CombatUnitTests );
  CPPUNIT_TEST( testConstructor );
  //  CPPUNIT_TEST_EXCEPTION( testPowerDissExcept, InsufficientPowerException );

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
