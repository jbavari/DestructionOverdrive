#include <cstdlib>
#include <iostream>
#include "Shield.h"
#include <fstream>
#include "DamageType.h"

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
    const char* name = "FirstThruster";
    Power maxCharge(5);
    Power curCharge(10);
    Power Cupkeep(5);
    Power bleedOff(1);
    DamageType typeEfficiency(.5);
    float baseEfficiency = 5;
    Shield firstShield( powerSupplied, upkeep, suggestedUpkeep, maxUpkeep, name, maxCharge,
                      curCharge, Cupkeep, bleedOff, typeEfficiency, baseEfficiency );
    ofstream writer("getxml.xml", ios::out);
//    XmlSerialization& xs = firstCModule;
    const xmlChar* firstXml = firstShield.XmlSerialization::getXml();
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
  


      Shield secondShield( docRoot );
      cout << "First sheld base efficiency : " << firstShield.getBaseEfficiency() << endl;
      cout << "Second sheld base efficiency : " << secondShield.getBaseEfficiency() << endl;

      if ( firstShield.getBaseEfficiency() == secondShield.getBaseEfficiency() )
	{
	  cout << "Base Effeciency PASS!!" << endl;
	}
      else
	{
	  cout << "Base Effeciency FAIL!!" << endl;
	  return -1;
	}

      if ( firstShield.getUpkeep() == secondShield.getUpkeep() )
	{
	  cout << "Upkeep PASS!!!!" << endl;
	}
      else
	{
	  cout << "Upkeep FAIL!" << endl;
	  return -1;
	}
      
  
      //      int x;
      //      cin >> x;
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }


    system("PAUSE");
    return EXIT_SUCCESS;
}
