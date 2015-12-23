#ifndef LD_COMBATUNITTESTS_H
#define LD_COMBATUNITTESTS_H 1

#include "CombatUnitId.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class CombatUnitIdTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( CombatUnitIdTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCopyConstructor );
  CPPUNIT_TEST( testEq );
  CPPUNIT_TEST( testNEq );
  //  CPPUNIT_TEST_EXCEPTION( testPowerDissExcept, InsufficientPowerException );

  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();


  void getDoc(ostream& ref);
  
public:
  void setUp();
  void tearDown();

  void testConstructor();
  void testCopyConstructor();
  void testEq();
  void testNEq();
  

  /**********************************************
   *          XmlSerialization stuff            *
   *********************************************/

  void testGetXml();
  void testXmlNodeConstructor();
};

#endif
