#include "DamageTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( DamageTests ); 

void 
DamageTests::setUp() 
{ 
} 


void 
DamageTests::tearDown() 
{ 
} 


void 
DamageTests::testConstructor() 
{
  Damage a;
  Damage b(12, 0.8);
  Damage c(b);

  CPPUNIT_ASSERT(a.getAmount().getAmount() == 0);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(a.getType().getKinetic(), 0.5, 0.001);
  CPPUNIT_ASSERT(b.getAmount().getAmount() == 12);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(b.getType().getKinetic(), 0.8, 0.001);
  CPPUNIT_ASSERT(c.getAmount().getAmount() == 12);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(c.getType().getKinetic(), 0.8, 0.001);
}






/*****************************************************************
 *         XmlSerialization Tests                                *
 ****************************************************************/

void
DamageTests::getDoc(ostream& ref)
{
  /* Get the Xml document string to test against for 
     comparison to what is generated */
  ref << "<object type=\"Damage\">\n";
  ref << "   <attribute name=\"amount\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">12</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "   <attribute name=\"type\" type=\"DamageType\">\n";
  ref << "      <object type=\"DamageType\">\n";
  ref << "         <attribute name=\"kinetic\" type=\"float\">0.8</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "</object>\n";
}



void
DamageTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  Damage tc(12, 0.8);
  
  getDoc(ref);


  tc.getXml(0, impl);

//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
DamageTests::testGetXmlChar()
{
  ostringstream ref;
  char* impl;
  Damage tc(12, 0.8);
  int cmp = -1;

  getDoc(ref);

  impl = (char*)tc.XmlSerialization::getXml();
  
//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl<<"'"<<endl;
//   cerr<<"cref:\n'"<<ref.str().c_str()<<"'"<<endl;



  /* For whatever reason strcmp wasn't working in the CPPUNIT_ASSERT macro */
  cmp = strcmp(ref.str().c_str(),impl);
  CPPUNIT_ASSERT( cmp == 0 );
}




void 
DamageTests::testXmlNodeConstructor()
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

  Damage tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();

  CPPUNIT_ASSERT(tc.getAmount().getAmount() == 12);
  CPPUNIT_ASSERT_DOUBLES_EQUAL(tc.getType().getKinetic(), 0.8, 0.001);
}
