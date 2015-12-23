#include <cstdlib>
#include <iostream>
#include "Power.h"
#include "Sensor.h"
#include "Module.h"
#include <fstream>


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{

    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    
    Sensor firstSensorModule(10, 5, upkeep, suggestedUpkeep, maxUpkeep, "Sensor", false);

    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = firstSensorModule.XmlSerialization::getXml();
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

      Sensor secondSensorModule( docRoot );
      if ( firstSensorModule.getUpkeep() == secondSensorModule.getUpkeep() )
	     cout << "TRUE!!!!" << endl;
      else
	      cout << "FALSE MOFO!" << endl;
  
     int x;
     cin >> x;
    

      xmlFreeDoc(doc);
      xmlCleanupParser();

    

    return EXIT_SUCCESS;
}
