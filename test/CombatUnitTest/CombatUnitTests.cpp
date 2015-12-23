#include "CombatUnitTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( CombatUnitTests ); 

void 
CombatUnitTests::setUp() 
{ 
} 


void 
CombatUnitTests::tearDown() 
{ 
} 


void 
CombatUnitTests::testConstructor() 
{
  CPPUNIT_FAIL("NotImplimented");
}






/*****************************************************************
 *         XmlSerialization Tests                                *
 ****************************************************************/

void
CombatUnitTests::getDoc(ostream& ref)
{
  ref << "";
}



void
CombatUnitTests::testGetXml()
{
  CPPUNIT_FAIL("NotImplimented");
//   ostringstream ref;
//   ostringstream impl;
//   CombatUnit tc(1, 2, 3, 4, 5);
  
//   getDoc(ref);


//   tc.getXml(0, impl);

// //   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
// //   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
//   CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
CombatUnitTests::testGetXmlChar()
{
  CPPUNIT_FAIL("NotImplimented");
//   ostringstream ref;
//   char* impl;
//   CombatUnit tc(1, 2, 3, 4, 5);
//   int cmp = -1;

//   getDoc(ref);

//   impl = (char*)tc.getXml();
  
// //   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
// //   cerr<<"impl:\n'"<<impl<<"'"<<endl;
// //   cerr<<"cref:\n'"<<ref.str().c_str()<<"'"<<endl;



//   /* For whatever reason strcmp wasn't working in the CPPUNIT_ASSERT macro */
//   cmp = strcmp(ref.str().c_str(),impl);
//   CPPUNIT_ASSERT( cmp == 0 );
}




void 
CombatUnitTests::testXmlNodeConstructor()
{
  CPPUNIT_FAIL("NotImplimented");
//   xmlDocPtr doc;
//   xmlNodePtr docRoot;
  
//   doc = xmlReadFile("test.xml", NULL, 0);
  
//   if (doc == NULL) 
//     {
//       cerr<<"error: could not parse file test.xml"<<endl;
//       abort();
//     }
  
//   /*Get the root element node */
//   docRoot = xmlDocGetRootElement(doc);
//   if ( docRoot == NULL )
//     {
//       cerr<<"error: could not get doc root node"<<endl;      
//       abort();
//     }

//   CombatUnit tc(docRoot);


//   xmlFreeDoc(doc);
//   xmlCleanupParser();


//   CPPUNIT_ASSERT(tc.getMaxCharge() == 1);
//   CPPUNIT_ASSERT(tc.getCurCharge() == 2);
//   CPPUNIT_ASSERT(tc.getUpkeep() == 3);
//   CPPUNIT_ASSERT(tc.getBleedOff() == 4);
//   CPPUNIT_ASSERT(tc.getPowerSupplied() == 5);
}
