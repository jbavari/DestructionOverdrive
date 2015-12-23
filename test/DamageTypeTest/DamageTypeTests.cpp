#include "DamageTypeTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( DamageTypeTests ); 

void 
DamageTypeTests::setUp() 
{ 
} 


void 
DamageTypeTests::tearDown() 
{ 
} 


void 
DamageTypeTests::testConstructor() 
{
  DamageType a;
  DamageType b(.6);


  CPPUNIT_ASSERT_DOUBLES_EQUAL( a.getKinetic(), 0.5, 0.001 );
  CPPUNIT_ASSERT_DOUBLES_EQUAL( b.getKinetic(), 0.6, 0.001 );
}

void
DamageTypeTests::testConstructExecptLow()
{
  DamageType a(-0.1);
}


void
DamageTypeTests::testConstructExceptHigh()
{
  DamageType b(1.1);
}


void
DamageTypeTests::testGetRadiant()
{
  DamageType a;
  DamageType b(0.0);
  DamageType c(1.0);

  CPPUNIT_ASSERT_DOUBLES_EQUAL(a.getRadiant(), 0.5, 0.001);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(b.getRadiant(), 1.0, 0.001);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(c.getRadiant(), 0.0, 0.001);
}







/*****************************************************************
 *         XmlSerialization Tests                                *
 ****************************************************************/

void
DamageTypeTests::getDoc(ostream& ref)
{
  /* Get the Xml document string to test against for 
     comparison to what is generated */
  ref << "<object type=\"DamageType\">\n";
  ref << "   <attribute name=\"kinetic\" type=\"float\">0.8</attribute>\n";
  ref << "</object>\n";
}



void
DamageTypeTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  DamageType tc(0.8);
  
  getDoc(ref);


  tc.getXml(0, impl);

//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
DamageTypeTests::testGetXmlChar()
{
  ostringstream ref;
  char* impl;
  DamageType tc(0.8);
  int cmp = -1;

  getDoc(ref);

  impl = (char*)tc.getXml();
  
//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl<<"'"<<endl;
//   cerr<<"cref:\n'"<<ref.str().c_str()<<"'"<<endl;



  /* For whatever reason strcmp wasn't working in the CPPUNIT_ASSERT macro */
  cmp = strcmp(ref.str().c_str(),impl);
  CPPUNIT_ASSERT( cmp == 0 );
}




void 
DamageTypeTests::testXmlNodeConstructor()
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

  DamageType tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();


  CPPUNIT_ASSERT_DOUBLES_EQUAL(tc.getKinetic(), 0.8, 0.001);
}
