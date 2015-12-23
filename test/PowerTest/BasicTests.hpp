#ifndef OUTOFDOMAINEXCEPTION_BASICTESTS_H
#define OUTOFDOMAINEXCEPTION_BASICTESTS_H 1

#include "Power.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;


class BasicTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( BasicTests );
  CPPUNIT_TEST( testConstructor );
  CPPUNIT_TEST( testCopyConstructor );
  CPPUNIT_TEST( testSetAmount );
  CPPUNIT_TEST ( testOpPlus );
  CPPUNIT_TEST ( testOpMinus );
  CPPUNIT_TEST ( testOpMul );
  CPPUNIT_TEST ( testOpDiv );
  CPPUNIT_TEST ( testOpMod );
  CPPUNIT_TEST ( testOpAssign );
  CPPUNIT_TEST ( testOpPlusAssign );
  CPPUNIT_TEST ( testOpMinusAssign );
  CPPUNIT_TEST ( testOpMulAssign );
  CPPUNIT_TEST ( testOpDivAssign );
  CPPUNIT_TEST ( testOpModAssign );
  CPPUNIT_TEST ( testOpPreInc );
  CPPUNIT_TEST ( testOpPostInc );
  CPPUNIT_TEST ( testOpPreDec );
  CPPUNIT_TEST ( testOpPostDec );
  CPPUNIT_TEST ( testOpGT );
  CPPUNIT_TEST ( testOpGE );
  CPPUNIT_TEST ( testOpLT );
  CPPUNIT_TEST ( testOpLE );
  CPPUNIT_TEST ( testOpNE );
  CPPUNIT_TEST ( testOpEQ );
  CPPUNIT_TEST ( testGetXml );
  CPPUNIT_TEST ( testGetXmlChar );
  CPPUNIT_TEST ( testXmlNodeConstructor );
  CPPUNIT_TEST_SUITE_END();
  
public:
  void setUp();
  void tearDown();
  
  void testConstructor();
  void testCopyConstructor();
  void testSetAmount();
  void testOpPlus();
  void testOpMinus();
  void testOpMul();
  void testOpDiv();
  void testOpMod();
  void testOpAssign();
  void testOpPlusAssign();
  void testOpMinusAssign();
  void testOpMulAssign();
  void testOpDivAssign();
  void testOpModAssign();
  void testOpPreInc();
  void testOpPostInc();
  void testOpPreDec();
  void testOpPostDec();
  void testOpGT();
  void testOpGE();
  void testOpLT();
  void testOpLE();
  void testOpNE();
  void testOpEQ();
  void testGetXml();
  void testGetXmlChar();
  void testXmlNodeConstructor();
};

#endif
