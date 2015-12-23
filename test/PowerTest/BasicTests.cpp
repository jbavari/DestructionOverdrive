#include "BasicTests.hpp"
#include <limits.h>
#include <iostream>
#include <sstream>
using std::ostringstream;
using std::cerr;
using std::cout;
using std::endl;


// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( BasicTests ); 

void 
BasicTests::setUp() 
{ 
} 


void 
BasicTests::tearDown() 
{ 
} 


void 
BasicTests::testConstructor() 
{ 
  Power aDefault;
  Power anArg(5);
  
  CPPUNIT_ASSERT(aDefault.getAmount() == 0);
  CPPUNIT_ASSERT(anArg.getAmount() == 5);
}

void 
BasicTests::testCopyConstructor() 
{
  Power tc(5);
  Power other(tc);
  
  CPPUNIT_ASSERT(tc.getAmount() == other.getAmount());
}


void 
BasicTests::testSetAmount() 
{
  Power tc;

  tc.setAmount(5);

  CPPUNIT_ASSERT(tc.getAmount() == 5);
}



void 
BasicTests::testOpPlus()
{
  Power a(5);
  Power b(6);
  Power c(a+b);
  
  CPPUNIT_ASSERT(c.getAmount() == 11);
}


void 
BasicTests::testOpMinus()
{
  Power a(6);
  Power b(5);
  Power c(a-b);
  Power d(b-a);
  
  CPPUNIT_ASSERT(c.getAmount() == 1);
  CPPUNIT_ASSERT(d.getAmount() == 0);
}



void 
BasicTests::testOpMul()
{
  Power a(6);
  Power b(6);
  Power c(a*b);
  
  CPPUNIT_ASSERT(c.getAmount() == 36);
}


void 
BasicTests::testOpDiv()
{
  Power a(6);
  Power b(6);
  Power d(a/b);
  
  CPPUNIT_ASSERT(d.getAmount() == 1);
}


void 
BasicTests::testOpMod()
{
  Power a(12);
  Power b(7);
  Power d(a%b);
  
  CPPUNIT_ASSERT(d.getAmount() == 12%7);
}


void 
BasicTests::testOpAssign()
{
  Power a(6);
  Power b((unsigned long int)0);
  
  a = b;
  
  CPPUNIT_ASSERT(a.getAmount() == 0);
}


void 
BasicTests::testOpPlusAssign()
{
  Power a(6);
  Power b(7);
  
  a+=b;
  
  CPPUNIT_ASSERT(a.getAmount() == 13);
}


void 
BasicTests::testOpMinusAssign()
{
  Power a(6);
  Power b(7);
  Power c(8);
  Power d(6);  
  
  a-=b;
  c-=d;
  

  CPPUNIT_ASSERT(a.getAmount() == 0);
  CPPUNIT_ASSERT(c.getAmount() == 2);
}


void 
BasicTests::testOpMulAssign()
{
  Power a(6);
  Power b(6);
  
  a*=b;
  
  CPPUNIT_ASSERT(a.getAmount() == 36);
}


void 
BasicTests::testOpDivAssign()
{
  Power a(6);
  Power b(6);
  
  a/=b;
  
  CPPUNIT_ASSERT(a.getAmount() == 1);
}


void 
BasicTests::testOpModAssign()
{
  Power a(12);
  Power b(7);
  
  a%=b;
  
  CPPUNIT_ASSERT(a.getAmount() == 12%7);
}


void 
BasicTests::testOpPreInc()
{
  Power a(5);

  CPPUNIT_ASSERT((++a).getAmount() == 6);
}


void 
BasicTests::testOpPostInc()
{
  Power a(5);

  CPPUNIT_ASSERT(a++.getAmount() == 6);
}


void 
BasicTests::testOpPreDec()
{
  Power a(5);

  CPPUNIT_ASSERT((--a).getAmount() == 4);
}


void 
BasicTests::testOpPostDec()
{
  Power a(5);

  CPPUNIT_ASSERT(a--.getAmount() == 4);
}


void 
BasicTests::testOpGT()
{
  Power a(5);
  Power b(6);
  
  CPPUNIT_ASSERT(b>a);
  CPPUNIT_ASSERT(!(a>b));
}


void 
BasicTests::testOpGE()
{
  Power a(5);
  Power b(6);
  Power c(6);
  
  CPPUNIT_ASSERT(b>=a);
  CPPUNIT_ASSERT(!(a>=b));
  CPPUNIT_ASSERT(b>=c);
}


void 
BasicTests::testOpLT()
{
  Power a(5);
  Power b(6);
  
  CPPUNIT_ASSERT(a<b);
  CPPUNIT_ASSERT(!(b<a));  
}


void 
BasicTests::testOpLE()
{
  Power a(5);
  Power b(6);
  Power c(6);
  
  CPPUNIT_ASSERT(a<=b);
  CPPUNIT_ASSERT(!(b<=a));
  CPPUNIT_ASSERT(b<=c);
}


void 
BasicTests::testOpNE()
{
  Power a(5);
  Power b(6);
  Power c(6);
  
  CPPUNIT_ASSERT(a!=b);
  CPPUNIT_ASSERT(!(c!=b));
}


void 
BasicTests::testOpEQ()
{
  Power a(5);
  Power b(6);
  Power c(6);
  
  CPPUNIT_ASSERT(b==c);
  CPPUNIT_ASSERT(!(a==b));
}


void 
BasicTests::testGetXml()
{
  ostringstream ref;
  ostringstream impl;
  Power tc(5);
  
  ref << "<object type=\"Power\">\n";
  ref << "   <attribute name=\"amount\" type=\"ULInt\">5</attribute>\n";
  ref << "</object>\n";

  tc.getXml(0, impl);
  
  CPPUNIT_ASSERT(ref.str() == impl.str());
}

void 
BasicTests::testGetXmlChar()
{
  ostringstream ref;
  char* impl;
  Power tc(5);
  int cmp = -1;

  ref << "<object type=\"Power\">\n";
  ref << "   <attribute name=\"amount\" type=\"ULInt\">5</attribute>\n";
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
BasicTests::testXmlNodeConstructor()
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

  Power tc(docRoot);


  xmlFreeDoc(doc);
  xmlCleanupParser();


  CPPUNIT_ASSERT(tc.getAmount() == 12);
}
