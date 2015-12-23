#include "Module.h"

namespace LightningDev
{
          Module::Module(const Power& newPowerSupplied, const Power& newUpKeep, const Power& newSuggestedUpkeep,
                         const Power& newMaxUpkeep, const char* newName) 
                 : PowerSuppliable(newPowerSupplied)
          {
             upkeep = newUpKeep;
             suggestedUpkeep = newSuggestedUpkeep;
             maxUpkeep = newMaxUpkeep;
             name = newName;
          }
          /* Ignored.
          Module::Module(unsigned int newUpkeep,unsigned int newSuggestedUpkeep,
                         unsigned int newMaxUpkeep, const char* newName) 
                         :upkeep(newUpkeep), 
                          suggestedUpkeep(newUpkeep), 
                          maxUpkeep(newMaxUpkeep), 
                          name(newName)
          { } */
          
          Module::Module(const Module& toCopy) 
                         :upkeep(toCopy.upkeep),
                          suggestedUpkeep(toCopy.suggestedUpkeep),
                          maxUpkeep(toCopy.maxUpkeep),
                          name(toCopy.name)
          { }
          
          Module::Module(xmlNodePtr inNode) : PowerSuppliable(getParentsObjectNode(inNode, "PowerSuppliable")),
                                    upkeep(getObjectAttributeObject(inNode, "upkeep")),
                                    suggestedUpkeep(getObjectAttributeObject(inNode, "suggestedUpkeep")),
                                    maxUpkeep(getObjectAttributeObject(inNode, "maxUpkeep"))
          {  for ( xmlNodePtr curNode = inNode->children; curNode != 0; curNode=curNode->next )
             {
	             if ( strcmp(getAttributeName(curNode), "name") == 0 )
	             {
	                name = getCStrAttributeValue(curNode);
                 }
              }      
          }
          
          void Module::getXml(unsigned int baseIndent, ostream& retStream) const
          {
               getStartObjectElement(baseIndent, "Module", retStream);
               getStartParentsElement(baseIndent+1, retStream);
               PowerSuppliable::getXml(baseIndent+2, retStream);
	           getEndParentsElement(baseIndent+1, retStream);
               getObjAttributeElement(baseIndent+1, "upkeep", "Power", upkeep, retStream);
               getObjAttributeElement(baseIndent+1, "suggestedUpkeep", "Power", suggestedUpkeep, retStream);
               getObjAttributeElement(baseIndent+1, "maxUpkeep", "Power", maxUpkeep, retStream);
               getCStrAttributeElement(baseIndent+1, "name", name.c_str(), retStream);
               getEndObjectElement(baseIndent, retStream);
          }
            
          const Power& Module::getUpkeep() const
          {
             return upkeep;
          }
          
          const Power& Module::getSuggestedUpkeep() const
          {
             return suggestedUpkeep;
          }
          
          const Power& Module::getMaxUpkeep() const
          {
             return maxUpkeep;
          }
          
          const string& Module::getName() const
          {
             return name;
          }
}
