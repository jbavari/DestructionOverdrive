#ifndef OUTOFDOMAINEXCEPTION_BASICTESTS_H
#define OUTOFDOMAINEXCEPTION_BASICTESTS_H 1

#include "XmlSerialization.h"
#include <cppunit/extensions/HelperMacros.h>

using namespace LightningDev;

class ObjTestClass : public XmlSerialization
{
private:
public:
  const xmlChar* getXml(unsigned int baseIndent=0) const;
  void getXml(unsigned int baseIndent, ostream& retStream) const;
};


class BasicTests : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( BasicTests );
  CPPUNIT_TEST( testGetIndent );
  CPPUNIT_TEST( testGetAttributeName );
  CPPUNIT_TEST( testGetAttributeType );
  CPPUNIT_TEST( testGetIntAttributeElement );
  CPPUNIT_TEST( testGetCStrAttributeElement );
  CPPUNIT_TEST( testGetStartObjectElement );
  CPPUNIT_TEST( testGetEndObjectElement );
  CPPUNIT_TEST( testGetStartParentsElement );
  CPPUNIT_TEST( testGetEndParentsElement );
  CPPUNIT_TEST( testGetCStrAttributeCopy );
  CPPUNIT_TEST( testGetCStrAttributeValue );
  CPPUNIT_TEST( testGetIntAttributeValue );
  CPPUNIT_TEST( testGetParentsObjectNode );
  CPPUNIT_TEST( testGetObjectAttributeElement );
  CPPUNIT_TEST( testGetObjAttObj );
  CPPUNIT_TEST( testGetULIntAttributeValue );
  CPPUNIT_TEST( testGetULIntAttributeElement );
  CPPUNIT_TEST( testGetStartAttributeElement );
  CPPUNIT_TEST( testGetEndAttributeElement );
  CPPUNIT_TEST( testGetFloatAttributeElement );
  CPPUNIT_TEST( testGetFloatAttributeValue );
  CPPUNIT_TEST( testGetBoolAttributeElement );
  CPPUNIT_TEST( testGetBoolAttributeValue );
  CPPUNIT_TEST( testGetBoolAttributeValueByName );
  CPPUNIT_TEST_EXCEPTION( testGetBoolAttributeValueByNameNF, XmlSerializationException );
  CPPUNIT_TEST_EXCEPTION( testParentsObjectNodeNF, XmlSerializationException );
  CPPUNIT_TEST_EXCEPTION( testObjAttObjNF, XmlSerializationException );

  CPPUNIT_TEST( testGetFloatAttributeValueByName );
  CPPUNIT_TEST_EXCEPTION( testGetFloatAttributeValueByNameNF, XmlSerializationException );

  CPPUNIT_TEST( testGetCStrAttributeValueByName );
  CPPUNIT_TEST_EXCEPTION( testGetCStrAttributeValueByNameNF, XmlSerializationException );


  CPPUNIT_TEST( testGetIntAttributeValueByName );
  CPPUNIT_TEST_EXCEPTION( testGetIntAttributeValueByNameNF, XmlSerializationException );


  CPPUNIT_TEST( testGetULIntAttributeValueByName );
  CPPUNIT_TEST_EXCEPTION( testGetULIntAttributeValueByNameNF, XmlSerializationException );


  CPPUNIT_TEST_SUITE_END();

  xmlNodePtr docRoot;
  xmlDocPtr  doc;
  
public:
  void setUp();
  void tearDown();
  
  void testGetIndent();
  void testGetAttributeName();
  void testGetAttributeType();
  void testGetIntAttributeElement();
  void testGetCStrAttributeElement();
  void testGetStartObjectElement();
  void testGetEndObjectElement();
  void testGetStartParentsElement();
  void testGetEndParentsElement();
  void testGetCStrAttributeCopy();
  void testGetCStrAttributeValue();
  void testGetIntAttributeValue();
  void testGetParentsObjectNode();
  void testGetObjectAttributeElement();
  void testGetObjAttObj();
  void testGetULIntAttributeValue();
  void testGetULIntAttributeElement();
  void testGetStartAttributeElement();
  void testGetEndAttributeElement();
  void testGetFloatAttributeElement();
  void testGetFloatAttributeValue();
  void testGetBoolAttributeElement();
  void testGetBoolAttributeValue();
  void testGetBoolAttributeValueByName();
  void testGetBoolAttributeValueByNameNF();
  void testParentsObjectNodeNF();
  void testObjAttObjNF();
  void testGetFloatAttributeValueByName();
  void testGetFloatAttributeValueByNameNF();
  void testGetCStrAttributeValueByName();
  void testGetCStrAttributeValueByNameNF();
  void testGetIntAttributeValueByName();
  void testGetIntAttributeValueByNameNF();
  void testGetULIntAttributeValueByName();
  void testGetULIntAttributeValueByNameNF();

};

#endif
