#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include "XmlSerialization.h"
#include "Power.h"
#include "Damage.h"
#include "Armor.h"


using namespace std;
using namespace LightningDev;

int main(int argc, char *argv[])
{
    cout << "HI!" << endl;
    Power upkeep(1);
    Power suggestedUpkeep(1);
    Power maxUpkeep(5);
    Power supplied(6);
    Power power(3);
    DamageType damagetype(2.5);
    Damage newStrength(power, damagetype);
   
    
    Armor armor1(supplied, upkeep, suggestedUpkeep, maxUpkeep, "NewArmor", 0.8, newStrength);
    ofstream writer("getxml.xml", ios::out);
    const xmlChar* firstXml = armor1.XmlSerialization::getXml();
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



      Armor armor2( docRoot );
      if ( armor1.getUpkeep() == armor2.getUpkeep() )
	cout << "TRUE!!!!" << endl;
      else
	{
	  cout << "FALSE!" << endl;
	  return -1;
	}
 
    

      xmlFreeDoc(doc);
      xmlCleanupParser();
    }
    system("PAUSE");
    return 0;
}

