#include "XmlSerializationFixture.hpp"
#include <string.h>
#include <sstream>
#include <iostream>
using std::ostringstream;
using std::cout;
using std::cerr;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BasicTests ); 

void 
BasicTests::setUp() 
{ 
  doc = xmlReadFile("test.xml", NULL, 0);
  
  if (doc == NULL) 
    {
      cerr<<"error: could not parse file test.xml"<<endl;
      abort();
    }
  
  /*Get the root element node */
  docRoot = xmlDocGetRootElement(doc);
  if ( docRoot == NULL )
    {
      cerr<<"error: could not get doc root node"<<endl;      
      abort();
    }
} 


void 
BasicTests::tearDown() 
{
  xmlFreeDoc(doc);
  xmlCleanupParser();
}

void 
BasicTests::testGetIndent() 
{ 
  XmlSerialization::getIndent(3);
  
  CPPUNIT_ASSERT(strcmp(XmlSerialization::getIndent(0), "") == 0);
  CPPUNIT_ASSERT(strcmp(XmlSerialization::getIndent(3), "         ") == 0);
}

void 
BasicTests::testGetAttributeName() 
{
  xmlNodePtr curNode = docRoot->children->next->next->next;


  CPPUNIT_ASSERT(strcmp(XmlSerialization::getAttributeName(curNode), "a") == 0);
}

void 
BasicTests::testGetAttributeType() 
{ 
  xmlNodePtr curNode = docRoot->children->next->next->next;
  CPPUNIT_ASSERT(strcmp(XmlSerialization::getAttributeType(curNode), "int") == 0);
}



void 
BasicTests::testGetIntAttributeElement() 
{
  ostringstream tmp;
  XmlSerialization::getIntAttributeElement(0, "a", 5, tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "<attribute name=\"a\" type=\"int\">5</attribute>\n") == 0);
}


void 
BasicTests::testGetCStrAttributeElement() 
{ 
  ostringstream tmp;
  XmlSerialization::getCStrAttributeElement(0, "a", "blah", tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "<attribute name=\"a\" type=\"CStr\">blah</attribute>\n") == 0);
}


void 
BasicTests::testGetStartObjectElement() 
{
  ostringstream tmp;
  XmlSerialization::getStartObjectElement(0, "MyObj", tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "<object type=\"MyObj\">\n") == 0);  
}


void 
BasicTests::testGetEndObjectElement() 
{ 
  ostringstream tmp;
  XmlSerialization::getEndObjectElement(0, tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "</object>\n") == 0);  
}


void 
BasicTests::testGetStartParentsElement() 
{ 
  ostringstream tmp;
  XmlSerialization::getStartParentsElement(0, tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "<parents>\n") == 0);
}

void 
BasicTests::testGetEndParentsElement() 
{ 
  ostringstream tmp;
  XmlSerialization::getEndParentsElement(0, tmp);

  
  CPPUNIT_ASSERT(strcmp(tmp.str().c_str(), "</parents>\n") == 0);
}


void 
BasicTests::testGetCStrAttributeCopy() 
{ 
  xmlNodePtr curNode = docRoot->children->next->children->next->children->next;
  char* tmp = XmlSerialization::getCStrAttributeCopy(curNode);

  CPPUNIT_ASSERT(strcmp(tmp, "ReadIn1") == 0);

  delete tmp;

  //Making sure we didn't segfault deleting tmp.
  CPPUNIT_ASSERT(1);
}

void 
BasicTests::testGetCStrAttributeValue() 
{ 
  xmlNodePtr curNode = docRoot->children->next->children->next->children->next;
  const char* tmp = XmlSerialization::getCStrAttributeValue(curNode);

  CPPUNIT_ASSERT(strcmp(tmp, "ReadIn1") == 0);
}


void 
BasicTests::testGetIntAttributeValue() 
{
  xmlNodePtr curNode = docRoot->children->next->next->next;
  int tmp;
  
  tmp = XmlSerialization::getIntAttributeValue(curNode);

  CPPUNIT_ASSERT(tmp == 20);
}



void 
BasicTests::testGetObjectAttributeElement() 
{
  ostringstream tmp;
  ostringstream ref;
  ObjTestClass otc;
  
  XmlSerialization::getObjAttributeElement(0, "a", "ObjTestClass", otc, tmp);
  
  ref << "<attribute name=\"a\" type=\"ObjTestClass\">\n   <object type=\"ObjTestClass\">\n   </object>\n</attribute>\n";


//   cerr<<"'"<<tmp.str()<<"'"<<endl;
//   cerr<<"'"<<ref.str()<<"'"<<endl;
  CPPUNIT_ASSERT(tmp.str() == ref.str());
  
}


//static xmlNodePtr getObjectAttributeObject(xmlNodePtr inNode, const char* thisType);
void 
BasicTests::testGetObjAttObj() 
{ 
  xmlNodePtr curNode = docRoot->children->next->children->next->next->next;
  xmlNodePtr destNode = docRoot->children->next->children->next->next->next->children->next->next->next->children->next;
 
//   cerr<<curNode->name<<endl;
//   cerr<<destNode->name<<endl;

  CPPUNIT_ASSERT(XmlSerialization::getObjectAttributeObject(curNode, "testAgregation") == destNode);
}



void 
BasicTests::testGetParentsObjectNode() 
{ 
  xmlNodePtr parentObjectNode = XmlSerialization::getParentsObjectNode(docRoot, "ParentClassA");
  CPPUNIT_ASSERT(strcmp((char*)parentObjectNode->name, "object") == 0);
}



void 
BasicTests::testGetStartAttributeElement()
{
  ostringstream ref;
  ostringstream impl;
  
  ref << "<attribute name=\"name\" type=\"type\">";
  XmlSerialization::getStartAttributeElement(0, "name", "type", impl);

  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
BasicTests::testGetEndAttributeElement()
{
  ostringstream ref;
  ostringstream impl;
  
  ref << "</attribute>\n";
  XmlSerialization::getEndAttributeElement(0, impl);

  CPPUNIT_ASSERT(ref.str() == impl.str());
}


void 
BasicTests::testGetULIntAttributeValue()
{
  xmlNodePtr curNode = docRoot->children->next->next->next->next->next->next->next;
  unsigned long int tmp = 0;
  
//   cerr<<"nodeName: "<<curNode->name<<endl;
//   cerr<<"attName : "<<XmlSerialization::getAttributeName(curNode)<<endl;
  
  tmp = XmlSerialization::getULIntAttributeValue(curNode);

  CPPUNIT_ASSERT(tmp == 20);
}

void 
BasicTests::testGetULIntAttributeElement()
{
  ostringstream ref;
  ostringstream impl;
  
  ref << "<attribute name=\"ulInt\" type=\"ULInt\">";
  ref << "12";
  ref << "</attribute>\n";

  XmlSerialization::getULIntAttributeElement(0, "ulInt", 12, impl);

//   cerr<<"ref : "<<ref.str()<<endl;
//   cerr<<"impl: "<<impl.str()<<endl;

  CPPUNIT_ASSERT(ref.str() == impl.str());
}



void 
BasicTests::testGetFloatAttributeElement()
{
  ostringstream ref;
  ostringstream impl;
  
  ref << "<attribute name=\"floatTest\" type=\"float\">";
  ref << "12.5";
  ref << "</attribute>\n";

  XmlSerialization::getFloatAttributeElement(0, "floatTest", 12.5, impl);

//   cerr<<"ref : "<<ref.str()<<endl;
//   cerr<<"impl: "<<impl.str()<<endl;

  CPPUNIT_ASSERT(ref.str() == impl.str());
}


void 
BasicTests::testGetFloatAttributeValue()
{
  xmlNodePtr curNode = docRoot->children->next->next->next->next->next->next->next->next->next;
  float tmp = 0;
  
//   cerr<<"nodeName: "<<curNode->name<<endl;
//   cerr<<"attName : "<<XmlSerialization::getAttributeName(curNode)<<endl;
  
  tmp = XmlSerialization::getFloatAttributeValue(curNode);

  //  cerr << "tmp: " << tmp << endl;

  CPPUNIT_ASSERT(tmp == 20.5);
}



void
BasicTests::testGetBoolAttributeElement()
{
  ostringstream ref;
  ostringstream impl;
  
  ref << "<attribute name=\"boolTest\" type=\"bool\">";
  ref << "true";
  ref << "</attribute>\n";

  XmlSerialization::getBoolAttributeElement(0, "boolTest", true, impl);

//   cerr<<"ref : "<<ref.str()<<endl;
//   cerr<<"impl: "<<impl.str()<<endl;

  CPPUNIT_ASSERT(ref.str() == impl.str());




  ref << "<attribute name=\"boolTest\" type=\"bool\">";
  ref << "false";
  ref << "</attribute>\n";

  XmlSerialization::getBoolAttributeElement(0, "boolTest", false, impl);

//   cerr<<"ref : "<<ref.str()<<endl;
//   cerr<<"impl: "<<impl.str()<<endl;

  CPPUNIT_ASSERT(ref.str() == impl.str());
}


void 
BasicTests::testGetBoolAttributeValue()
{
  xmlNodePtr curNode = docRoot->children->next->next->next->next->next->next->next->next->next->next->next;
  float tmp = 0;  

//   cerr<<"nodeName: "<<curNode->name<<endl;
//   cerr<<"attName : "<<XmlSerialization::getAttributeName(curNode)<<endl;
  
  tmp = XmlSerialization::getBoolAttributeValue(curNode);

  //  cerr << "tmp: " << tmp << endl;

  CPPUNIT_ASSERT(tmp == false);
}

void 
BasicTests::testGetBoolAttributeValueByName()
{
  xmlNodePtr curNode = docRoot;
  float tmp = 0;
  
  tmp = XmlSerialization::getBoolAttributeValueByName(curNode, "e");

  CPPUNIT_ASSERT(tmp == false);
}


void 
BasicTests::testGetBoolAttributeValueByNameNF()
{
  xmlNodePtr curNode = docRoot;
  bool tmp = 0;
  
  tmp = XmlSerialization::getBoolAttributeValueByName(curNode, "bogus");

  CPPUNIT_ASSERT(tmp == false);
}



void 
BasicTests::testParentsObjectNodeNF()
{
  XmlSerialization::getParentsObjectNode(docRoot, "bogus");
}

void 
BasicTests::testObjAttObjNF()
{
  XmlSerialization::getObjectAttributeObject(docRoot, "bogus");
}


void 
BasicTests::testGetFloatAttributeValueByName()
{
  xmlNodePtr curNode = docRoot;
  float tmp = 0;
  
  tmp = XmlSerialization::getFloatAttributeValueByName(curNode, "d");

  CPPUNIT_ASSERT(tmp == 20.5);
}


void 
BasicTests::testGetFloatAttributeValueByNameNF()
{
  XmlSerialization::getFloatAttributeValueByName(docRoot, "bogus");
}


void 
BasicTests::testGetCStrAttributeValueByName()
{
  xmlNodePtr curNode = docRoot;
  const char* tmp = 0;
  
  tmp = XmlSerialization::getCStrAttributeValueByName(curNode, "f");

  CPPUNIT_ASSERT(strcmp(tmp, "ReadIn4") == 0);
}


void 
BasicTests::testGetCStrAttributeValueByNameNF()
{
  XmlSerialization::getCStrAttributeValueByName(docRoot, "bogus");
}



void 
BasicTests::testGetIntAttributeValueByName()
{
  xmlNodePtr curNode = docRoot;
  int tmp = 0;
  
  tmp = XmlSerialization::getIntAttributeValueByName(curNode, "a");

  CPPUNIT_ASSERT(tmp== 20);
}


void 
BasicTests::testGetIntAttributeValueByNameNF()
{
  XmlSerialization::getIntAttributeValueByName(docRoot, "bogus");
}


void 
BasicTests::testGetULIntAttributeValueByName()
{
  xmlNodePtr curNode = docRoot;
  unsigned long int tmp = 0;
  
  tmp = XmlSerialization::getULIntAttributeValueByName(curNode, "c");

  CPPUNIT_ASSERT(tmp== 20);
}


void 
BasicTests::testGetULIntAttributeValueByNameNF()
{
  XmlSerialization::getIntAttributeValueByName(docRoot, "bogus");
}


/******************************************************
 * ObjTestClass stuff                                 *
 ******************************************************/

const xmlChar*
ObjTestClass::getXml(unsigned int baseIndent) const
{
  static ostringstream retStream;
  
  getXml(baseIndent, retStream);

  return (xmlChar*)retStream.str().c_str();
}


void
ObjTestClass::getXml(unsigned int baseIndent, ostream& retStream) const
{
  getStartObjectElement(baseIndent, "ObjTestClass", retStream);
  getEndObjectElement(baseIndent, retStream);
}


