#include <cstdlib>
#include <iostream>
#include "Power.h"
#include "Module.h"
#include <fstream>
#include <memory.h>
#include <stdlib.h>
#include <string.h>


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{
    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    Power supplied(6);
    
    Module firstModule(supplied, upkeep, suggestedUpkeep, maxUpkeep, "SuperModule");
    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = firstModule.XmlSerialization::getXml();
    writer << (const char*) firstXml;    
    writer.close();
    


    /* How to parse the XML Document */
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



      Module secondModule( docRoot );
      if ( firstModule.getUpkeep() == secondModule.getUpkeep() )
	cout << "TRUE!!!!" << endl;
      else
	{
	  cout << "FALSE MOFO!" << endl;
	  return -1;
	}
 
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }
    //    int y;
    //cin >> y;
    return EXIT_SUCCESS;
}
