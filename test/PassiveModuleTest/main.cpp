#include <cstdlib>
#include <iostream>
#include "Power.h"
#include "PassiveModule.h"
#include "Module.h"
#include <fstream>


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{
    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    Power powerSuppliable(1);
    PassiveModule firstPModule(powerSuppliable,upkeep, suggestedUpkeep, maxUpkeep, "PassiveModule", false);
    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = firstPModule.XmlSerialization::getXml();
    writer << (const char*) firstXml;
    writer.close();
    
    {
      xmlDocPtr doc;
      xmlNodePtr docRoot;
  
      doc = xmlReadFile("getxml.xml", NULL, 0);
  
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
  


      PassiveModule secondModule( docRoot );
      if ( firstPModule.getUpkeep() == secondModule.getUpkeep() )
	cout << "TRUE!!!!" << endl;
      else
	cout << "FALSE MOFO!" << endl;
  
     int x;
     cin >> x;
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }
    
    return EXIT_SUCCESS;
}
