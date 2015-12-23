#include "CapacitorModule.h"
#include "Thruster.h"

namespace LightningDev
{
    //Power thrust; Field of Thruster
    Thruster::Thruster( const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
                    const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
                    const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff, const Power& newThrust )               
                    : CapacitorModule(newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName,
                      newMaxCharge, newCurCharge, newCUpkeep, newBleedOff ), thrust(newThrust)
    { } 

    Thruster::Thruster( const Thruster& toCopy ) : CapacitorModule(toCopy), thrust(toCopy.thrust)
    { }
    
    Thruster::Thruster( xmlNodePtr inNode ) : CapacitorModule(getParentsObjectNode(inNode, "CapacitorModule")),
                                              thrust(getObjectAttributeObject( inNode, "thrust" ))
    { }
    
    void Thruster::getXml( unsigned int baseIndent, ostream& retStream ) const
    {
        getStartObjectElement(baseIndent, "Thruster", retStream);
        getStartParentsElement(baseIndent+1, retStream);
        CapacitorModule::getXml(baseIndent+2, retStream);
        getEndParentsElement(baseIndent+1, retStream);
        getObjAttributeElement(baseIndent+1, "thrust", "Power", thrust, retStream);
        getEndObjectElement(baseIndent, retStream);  
    }
    
    const Power& Thruster::getThrust() const
    {
          return thrust;
    }
}
