#include "Capacitor.h"

namespace LightningDev
{
  

  Capacitor::Capacitor(unsigned int newMaxCharge, unsigned int newCurCharge,
		       unsigned int newUpkeep,    unsigned int newBleedOff,
		       unsigned int newPowerSupplied)
      :PowerSuppliable(newPowerSupplied),
       maxCharge(newMaxCharge),
       curCharge(newCurCharge),
       upkeep(newUpkeep),
       bleedOff(newBleedOff)

  {}
  

  Capacitor::Capacitor(const Power& newMaxCharge, const Power& newCurCharge,
		       const Power& newUpkeep,    const Power& newBleedOff,
		       const Power& newPowerSupplied)
      :PowerSuppliable(newPowerSupplied),
       maxCharge(newMaxCharge),
       curCharge(newCurCharge),
       upkeep(newUpkeep),
       bleedOff(newBleedOff)
  {
  }
  


  Capacitor::Capacitor(const Capacitor& toCopy)
      :PowerSuppliable(toCopy),
       maxCharge(toCopy.maxCharge),
       curCharge(toCopy.curCharge),
       upkeep(toCopy.upkeep),
       bleedOff(toCopy.bleedOff)
  {}
  



  /**********************************************************
   *  XmlSerialziation Stuff                                *
   *********************************************************/
  
  Capacitor::Capacitor(xmlNodePtr inNode)
      :PowerSuppliable(getParentsObjectNode(inNode, "PowerSuppliable")),
       maxCharge(getObjectAttributeObject(inNode, "maxCharge")),
       curCharge(getObjectAttributeObject(inNode, "curCharge")),
       upkeep(getObjectAttributeObject(inNode, "upkeep")),
       bleedOff(getObjectAttributeObject(inNode, "bleedOff"))
  {}
    

  void 
  Capacitor::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "Capacitor", retStream);
    getStartParentsElement(baseIndent+1, retStream);
    PowerSuppliable::getXml(baseIndent+2, retStream);
    getEndParentsElement(baseIndent+1, retStream);
    getObjAttributeElement(baseIndent+1, "maxCharge", "Power", maxCharge, retStream);
    getObjAttributeElement(baseIndent+1, "curCharge", "Power", curCharge, retStream);
    getObjAttributeElement(baseIndent+1, "upkeep", "Power", upkeep, retStream);
    getObjAttributeElement(baseIndent+1, "bleedOff", "Power", bleedOff, retStream);
    getEndObjectElement(baseIndent, retStream);
  }
  

  /**********************************************************
   *  Regular Stuff                                         *
   *********************************************************/
  

  const Power& 
  Capacitor::getMaxCharge() const
  {
    return maxCharge;
  }
  
  
  const Power& 
  Capacitor::getCurCharge() const
  {
    return curCharge;
  }
  
  
  const Power& 
  Capacitor::getUpkeep() const
  {
    return upkeep;
  }
  
  
  const Power& 
  Capacitor::getBleedOff() const
  {
    return bleedOff;
  }
  
  
  void 
  Capacitor::disscharge(const Power& amount)
  {
    if ( curCharge < amount )
      {
	throw InsufficientPowerException("In Capacitor::disscharge(Power&)");
      }

    curCharge -= amount;
  }
  
  
  void 
  Capacitor::disscharge(unsigned int amount)
  {
    if ( curCharge < amount )
      {
	throw InsufficientPowerException("In Capacitor::disscharge(int)");
      }

    curCharge -= amount;
  }
  
  
  Power 
  Capacitor::disscharge()
  {
    Power retVal(curCharge);

    curCharge.setAmount(0);

    return retVal;
  }
  
  
} /* end namespace LightningDev */
