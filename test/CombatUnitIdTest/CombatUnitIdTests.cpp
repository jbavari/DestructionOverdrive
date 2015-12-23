#include "CombatUnitIdTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( CombatUnitIdTests ); 

void 
CombatUnitIdTests::setUp() 
{ 
} 


void 
CombatUnitIdTests::tearDown() 
{ 
} 


void 
CombatUnitIdTests::testConstructor() 
{
  CombatUnitId a(12, 16);
  
  CPPUNIT_ASSERT(a.getPlayerId() == 12);
  CPPUNIT_ASSERT(a.getObjectId() == 16); 
}

void 
CombatUnitIdTests::testCopyConstructor() 
{
  CombatUnitId a(12, 16);
  CombatUnitId b(a);
  
  
  CPPUNIT_ASSERT(b.getPlayerId() == 12);
  CPPUNIT_ASSERT(b.getObjectId() == 16);
}

void 
CombatUnitIdTests::testEq() 
{
  CombatUnitId a(12, 16);
  CombatUnitId b(a);
  CombatUnitId c(16, 12);
  
  CPPUNIT_ASSERT(a == b);
  CPPUNIT_ASSERT(!(a == c));
}



void 
CombatUnitIdTests::testNEq() 
{
  CombatUnitId a(12, 16);
  CombatUnitId b(a);
  CombatUnitId c(16, 12);
  
  CPPUNIT_ASSERT(!(a != b));
  CPPUNIT_ASSERT(a != c);
}


/*****************************************************************
 *         XmlSerialization Tests                                *
 ****************************************************************/

void
CombatUnitIdTests::getDoc(ostream& ref)
{
  ref << "<object type=\"CombatUnitId\">\n";
  ref << "   <attribute name=\"playerId\" type=\"ULInt\">12</attribute>\n";
  ref << "   <attribute name=\"objId\" type=\"ULInt\">16</attribute>\n";
  ref << "</object>\n";
}



void
CombatUnitIdTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  CombatUnitId tc(12, 16);
  
  getDoc(ref);


  tc.getXml(0, impl);

//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}


void 
CombatUnitIdTests::testXmlNodeConstructor()
{
  xmlDocPtr doc;
  xmlNodePtr docRoot;
  
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

  CombatUnitId tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();

  cerr << "playerId: " << tc.getPlayerId() <<"\n";
  cerr << "objId: " << tc.getObjectId() <<"\n";
  CPPUNIT_ASSERT(tc.getPlayerId() == 12);
  CPPUNIT_ASSERT(tc.getObjectId() == 16);
}
