#include "PowerSuppliableTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( PowerSuppliableTests ); 

void 
PowerSuppliableTests::setUp() 
{ 
} 


void 
PowerSuppliableTests::tearDown() 
{ 
} 


void 
PowerSuppliableTests::testConstructor() 
{ 
  Power power(12);
  PowerSuppliable aDefault;
  PowerSuppliable anInt(5);
  PowerSuppliable aPower(power);
  PowerSuppliable aCopy(anInt);
  
  CPPUNIT_ASSERT(aDefault.getPowerSupplied() == (unsigned long int)0);
  CPPUNIT_ASSERT(anInt.getPowerSupplied() == 5);
  CPPUNIT_ASSERT(aPower.getPowerSupplied() == 12);
  CPPUNIT_ASSERT(aCopy.getPowerSupplied() == 5);
}

void 
PowerSuppliableTests::testSetPowerSupplied() 
{
  PowerSuppliable tc(5);
  
  tc.setPowerSupplied(12);

  CPPUNIT_ASSERT(tc.getPowerSupplied() == 12);
}


void
PowerSuppliableTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  PowerSuppliable tc(12);
  
  ref << "<object type=\"PowerSuppliable\">\n";
  ref << "   <attribute name=\"powerSupplied\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">12</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "</object>\n";

  tc.getXml(0, impl);

//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
PowerSuppliableTests::testGetXmlChar()
{
  ostringstream ref;
  char* impl;
  PowerSuppliable tc(12);
  int cmp = -1;

  ref << "<object type=\"PowerSuppliable\">\n";
  ref << "   <attribute name=\"powerSupplied\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">12</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "</object>\n";

  impl = (char*)tc.getXml();
  
//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl<<"'"<<endl;
//   cerr<<"cref:\n'"<<ref.str().c_str()<<"'"<<endl;



  /* For whatever reason strcmp wasn't working in the CPPUNIT_ASSERT macro */
  cmp = strcmp(ref.str().c_str(),impl);
  CPPUNIT_ASSERT( cmp == 0 );
}




void 
PowerSuppliableTests::testXmlNodeConstructor()
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

  PowerSuppliable tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();


  CPPUNIT_ASSERT(tc.getPowerSupplied() == 12);
}
