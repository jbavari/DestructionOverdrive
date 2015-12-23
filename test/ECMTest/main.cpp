#include <cstdlib>
#include <iostream>
#include "Power.h"
#include "ECM.h"
#include "Module.h"
#include <fstream>


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{

    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    
    ECM firstECMModule(10, 5, upkeep, suggestedUpkeep, maxUpkeep, "ECM", false);

    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = firstECMModule.XmlSerialization::getXml();
    writer << (const char*) firstXml;
    writer.close();
    
    
      xmlDocPtr doc;
      xmlNodePtr docRoot;
  
      doc = xmlReadFile("getxml.xml", NULL, 0);
  
      if (doc == NULL) 
	  {
	    cerr<<"error: could not parse file test.xml"<<endl;
	    abort();
	  }

  
      // Get the root element node 
      docRoot = xmlDocGetRootElement(doc);
      if ( docRoot == NULL )
	  {
	    cerr<<"error: could not get doc root node"<<endl;      
	    abort();
	  }

      ECM secondECMModule( docRoot );
      if ( firstECMModule.getUpkeep() == secondECMModule.getUpkeep() )
	     cout << "TRUE!!!!" << endl;
      else
	{
	  cout << "FALSE MOFO!" << endl;
	  return -1;
	}
      
  
      //     int x;
      //cin >> x;
    

      xmlFreeDoc(doc);
      xmlCleanupParser();

    

    return EXIT_SUCCESS;
}
