#include "CapacitorTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( CapacitorTests ); 

void 
CapacitorTests::setUp() 
{ 
} 


void 
CapacitorTests::tearDown() 
{ 
} 


void 
CapacitorTests::testConstructor() 
{
  Capacitor a(1, 2, 3, 4);
  Capacitor b(1, 2, 3, 4, 5);
  Capacitor c(Power(6), Power(7), Power(8), Power(9), Power(10));
  Capacitor d(c);

  CPPUNIT_ASSERT(a.getMaxCharge() == 1);
  CPPUNIT_ASSERT(a.getCurCharge() == 2);
  CPPUNIT_ASSERT(a.getUpkeep() == 3);
  CPPUNIT_ASSERT(a.getBleedOff() == 4);
  CPPUNIT_ASSERT(a.getPowerSupplied() == (unsigned long int)0);

  CPPUNIT_ASSERT(b.getMaxCharge() == 1);
  CPPUNIT_ASSERT(b.getCurCharge() == 2);
  CPPUNIT_ASSERT(b.getUpkeep() == 3);
  CPPUNIT_ASSERT(b.getBleedOff() == 4);
  CPPUNIT_ASSERT(b.getPowerSupplied() == 5);

  CPPUNIT_ASSERT(c.getMaxCharge() == 6);
  CPPUNIT_ASSERT(c.getCurCharge() == 7);
  CPPUNIT_ASSERT(c.getUpkeep() == 8);
  CPPUNIT_ASSERT(c.getBleedOff() == 9);
  CPPUNIT_ASSERT(c.getPowerSupplied() == 10);

  CPPUNIT_ASSERT(d.getMaxCharge() == 6);
  CPPUNIT_ASSERT(d.getCurCharge() == 7);
  CPPUNIT_ASSERT(d.getUpkeep() == 8);
  CPPUNIT_ASSERT(d.getBleedOff() == 9);
  CPPUNIT_ASSERT(d.getPowerSupplied() == 10);
}


void 
CapacitorTests::testDisscharge()
{
  Capacitor a(10,10,10,10,10);
  Capacitor b(10,10,10,10,10);
  Capacitor c(10,10,10,10,10);
  Power res;
  
  a.disscharge(Power(5));
  b.disscharge(5);
  res = c.disscharge();
  
  CPPUNIT_ASSERT(a.getCurCharge() == 5);
  CPPUNIT_ASSERT(b.getCurCharge() == 5);
  CPPUNIT_ASSERT(c.getCurCharge() == (unsigned long int)0);
  CPPUNIT_ASSERT(res == 10);
}


void
CapacitorTests::testIntDissExcept()
{
  Capacitor a(1,1,1,1,1);
  a.disscharge(10);
}

void
CapacitorTests::testPowerDissExcept()
{
  Capacitor a(1,1,1,1,1);
  a.disscharge(Power(10));
}




/*****************************************************************
 *         XmlSerialization Tests                                *
 ****************************************************************/

void
CapacitorTests::getDoc(ostream& ref)
{
  ref << "<object type=\"Capacitor\">\n";
  ref << "   <parents>\n";
  ref << "      <object type=\"PowerSuppliable\">\n";
  ref << "         <attribute name=\"powerSupplied\" type=\"Power\">\n";
  ref << "            <object type=\"Power\">\n";
  ref << "               <attribute name=\"amount\" type=\"ULInt\">5</attribute>\n";
  ref << "            </object>\n";
  ref << "         </attribute>\n";
  ref << "      </object>\n";
  ref << "   </parents>\n";
  ref << "   <attribute name=\"maxCharge\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">1</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "   <attribute name=\"curCharge\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">2</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "   <attribute name=\"upkeep\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">3</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "   <attribute name=\"bleedOff\" type=\"Power\">\n";
  ref << "      <object type=\"Power\">\n";
  ref << "         <attribute name=\"amount\" type=\"ULInt\">4</attribute>\n";
  ref << "      </object>\n";
  ref << "   </attribute>\n";
  ref << "</object>\n";
}



void
CapacitorTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  Capacitor tc(1, 2, 3, 4, 5);
  
  getDoc(ref);


  tc.getXml(0, impl);

//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl.str()<<"'"<<endl;

  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
CapacitorTests::testGetXmlChar()
{
  ostringstream ref;
  char* impl;
  Capacitor tc(1, 2, 3, 4, 5);
  int cmp = -1;
  XmlSerialization& xtc = tc;

  getDoc(ref);

  impl = (char*)xtc.getXml();
  
//   cerr<<"ref :\n'"<<ref.str()<<"'"<<endl;
//   cerr<<"impl:\n'"<<impl<<"'"<<endl;
//   cerr<<"cref:\n'"<<ref.str().c_str()<<"'"<<endl;



  /* For whatever reason strcmp wasn't working in the CPPUNIT_ASSERT macro */
  cmp = strcmp(ref.str().c_str(),impl);
  CPPUNIT_ASSERT( cmp == 0 );
}




void 
CapacitorTests::testXmlNodeConstructor()
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

  Capacitor tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();


  CPPUNIT_ASSERT(tc.getMaxCharge() == 1);
  CPPUNIT_ASSERT(tc.getCurCharge() == 2);
  CPPUNIT_ASSERT(tc.getUpkeep() == 3);
  CPPUNIT_ASSERT(tc.getBleedOff() == 4);
  CPPUNIT_ASSERT(tc.getPowerSupplied() == 5);
}
