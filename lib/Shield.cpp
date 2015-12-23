#include "Shield.h"

namespace LightningDev
{            
  Shield::Shield(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
		 const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
		 const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff, 
		 const DamageType& newTypeEfficiency, const float& newBaseEfficiency)
      :CapacitorModule( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName, newMaxCharge,
			newCurCharge, newCUpkeep, newBleedOff ), typeEfficiency(newTypeEfficiency), 
       baseEfficiency(newBaseEfficiency)
  { }    
            
  Shield::Shield( const Shield& toCopy ) 
      : CapacitorModule(toCopy), typeEfficiency(toCopy.typeEfficiency),
	baseEfficiency(toCopy.baseEfficiency)
  { }
            
  Shield::Shield( xmlNodePtr inNode) 
      : CapacitorModule(getParentsObjectNode(inNode, "CapacitorModule")),
	typeEfficiency(getObjectAttributeObject(inNode, "typeEfficiency")), 
	baseEfficiency(getFloatAttributeValueByName(inNode, "baseEfficiency"))
  { }            

  const DamageType& Shield::getTypeEfficiency() const
  {
    return typeEfficiency;
  }
            
  const float& Shield::getBaseEfficiency() const
  {
    return baseEfficiency;
  }
            
  void Shield::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "Shield", retStream);
    getStartParentsElement(baseIndent+1, retStream);
    CapacitorModule::getXml(baseIndent+2, retStream);
    getEndParentsElement(baseIndent+1, retStream);
    getObjAttributeElement(baseIndent+1, "typeEfficiency", "DamageType", typeEfficiency, retStream);
    getFloatAttributeElement(baseIndent+1, "baseEfficiency", baseEfficiency, retStream); 
    getEndObjectElement(baseIndent, retStream);
  }
}
