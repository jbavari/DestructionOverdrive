#include "CapacitorModule.h"

namespace LightningDev
{

    CapacitorModule::CapacitorModule(const Power& newPowerSupplied, const Power& newUpkeep, 
               const Power& newSuggestedUpkeep, const Power& newMaxUpkeep, const char* newName, 
               const Power& newMaxCharge, const Power& newCurCharge, const Power& newCUpkeep, 
               const Power& newBleedOff)
             : Module( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName ), 
               capacitor( newMaxCharge, newCurCharge, newCUpkeep, newBleedOff, newPowerSupplied )
   { }       
             
    CapacitorModule::CapacitorModule(const Power& newPowerSupplied, const Power& newUpkeep, 
               const Power& newSuggestedUpkeep, const Power& newMaxUpkeep, const char* newName, 
               const Capacitor& newCapacitor)
             : Module( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName ), 
               capacitor( newCapacitor )
   { }
                                                      
   CapacitorModule::CapacitorModule( const CapacitorModule& toCopy ) :
                    Module( toCopy ), capacitor(toCopy.capacitor)
   { }
   
   CapacitorModule::CapacitorModule( xmlNodePtr inNode ) :
                    Module(getParentsObjectNode(inNode, "Module")),
                    capacitor(getObjectAttributeObject( inNode, "capacitor" ))
   { }
   
   const Power& CapacitorModule::getCapacitorMaxCharge() const
   {
         return capacitor.getMaxCharge();
   }
   
   const Power& CapacitorModule::getCapacitorCurCharge() const
   {
         return capacitor.getCurCharge();
   }
   
   const Power& CapacitorModule::getCapacitorUpkeep() const
   {
         return capacitor.getUpkeep();
   }
   
   const Power& CapacitorModule::getCapacitorBleedOff() const
   {
         return capacitor.getBleedOff();
   }
   
   void CapacitorModule::getXml( unsigned int baseIndent, ostream& retStream ) const
   {
        getStartObjectElement(baseIndent, "CapacitorModule", retStream);
        getStartParentsElement(baseIndent+1, retStream);
        Module::getXml(baseIndent+2, retStream);
        getEndParentsElement(baseIndent+1, retStream);
        getObjAttributeElement(baseIndent+1, "capacitor", "Capacitor", capacitor, retStream);
        getEndObjectElement(baseIndent, retStream);
   }
           
}        
        
        
        
