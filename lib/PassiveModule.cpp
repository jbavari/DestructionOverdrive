#include "PassiveModule.h"
#include "XmlSerialization.h"

namespace LightningDev
{
          PassiveModule::PassiveModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
                                             const Power& newMaxUpkeep, const char* newName, bool newActive )
                  : Module(newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName), active(newActive)
          { }
          
          PassiveModule::PassiveModule( const PassiveModule& toCopy ) : Module(toCopy), active(toCopy.active)
          { }
          
          PassiveModule::PassiveModule( xmlNodePtr inNode ) : 
                         Module(getParentsObjectNode(inNode, "Module")),
                         active(getBoolAttributeValue(inNode))
          { }
          
         bool PassiveModule::isActive()
         {
              return active;
         }
         
         void PassiveModule::getXml(unsigned int baseIndent, ostream& retStream) const
         {
              getStartObjectElement(baseIndent, "PassiveModule", retStream);
              getStartParentsElement(baseIndent+1, retStream);
              Module::getXml(baseIndent+2, retStream);
              getEndParentsElement(baseIndent+1, retStream);
              getBoolAttributeElement(baseIndent+1, "active", active, retStream);
              getEndObjectElement(baseIndent, retStream);
         }
}
