#include <cstdlib>
#include <iostream>
#include "CapacitorModule.h"
#include <fstream>

using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{
    /*
        CapacitorModule::CapacitorModule(const Power& newPowerSupplied, const Power& newUpkeep, 
               const Power& newSuggestedUpkeep, const Power& newMaxUpkeep, const char* newName, 
               const Power& newMaxCharge, const Power& newCurCharge, const Power& newCUpkeep, 
               const Power& newBleedOff)
             : Module( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName ), 
               capacitor( newMaxCharge, newCurCharge, newCUpkeep, newBleedOff, newPowerSupplied )
               */
                 
    Power powerSupplied(1);
    Power upkeep(1);
    Power suggestedUpkeep(2);
    Power maxUpkeep(5);
    const char* name = "FirstCModule";
    Power maxCharge(5);
    Power curCharge(10);
    Power Cupkeep(5);
    Power bleedOff(1);
    CapacitorModule firstCModule( powerSupplied, upkeep, suggestedUpkeep, maxUpkeep, name, maxCharge,
                      curCharge, Cupkeep, bleedOff );
                            
    ofstream writer("getxml.xml", ios::out);
//    XmlSerialization& xs = firstCModule;
    const xmlChar* firstXml = firstCModule.XmlSerialization::getXml();
    writer << (const char*) firstXml;
//      firstCModule.getXml((unsigned int)0, (ostream&)writer);
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
  


      CapacitorModule secondCModule( docRoot );
      if ( firstCModule.getUpkeep() == secondCModule.getUpkeep() )
	cout << "TRUE!!!!" << endl;
      else
	cout << "FALSE MOFO!" << endl;
  
     int x;
     cin >> x;
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }


    system("PAUSE");
    return EXIT_SUCCESS;
}
