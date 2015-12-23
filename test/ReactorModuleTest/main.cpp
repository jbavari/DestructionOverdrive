#include <cstdlib>
#include <iostream>
#include "Power.h"
#include <fstream>
#include <memory.h>
#include <stdlib.h>
#include <string.h>
#include "ReactorModule.h"


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{
    Power powerSupplied(5);
    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    //ReactorModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
	//   const Power& newMaxUpkeep, const char* newName);
    ReactorModule firstRModule( powerSupplied, upkeep, suggestedUpkeep, maxUpkeep, "ReactorSuperModule");
    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = firstRModule.XmlSerialization::getXml();
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



      ReactorModule secondRModule( docRoot );
      if ( firstRModule.getUpkeep() == secondRModule.getUpkeep() )
	     cout << "Upkeep is the same!!!!" << endl;
      else
      {
	      cout << "FALSE, Upkeep is different!" << endl;
	      exit(1);
      }
 
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }
    int y;
    cin >> y;
    return EXIT_SUCCESS;
}
