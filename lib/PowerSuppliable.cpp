#include "PowerSuppliable.h"

namespace LightningDev
{
  PowerSuppliable::PowerSuppliable( unsigned int newPowerSupplied )
      :powerSupplied(newPowerSupplied)
  {}
          
  PowerSuppliable::PowerSuppliable( const Power& newPowerSupplied )
      :powerSupplied(newPowerSupplied)
  {}
          

  PowerSuppliable::PowerSuppliable( const PowerSuppliable& toCopy )
      :powerSupplied(toCopy.powerSupplied)
  {}


  PowerSuppliable::PowerSuppliable( xmlNodePtr inNode )
      :powerSupplied(getObjectAttributeObject(inNode, "powerSupplied"))
  {}
  
  void 
  PowerSuppliable::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "PowerSuppliable", retStream);
    getObjAttributeElement(baseIndent+1, "powerSupplied", "Power", powerSupplied, retStream);
    getEndObjectElement(baseIndent, retStream);
  }
  
  const xmlChar*
  PowerSuppliable::getXml(unsigned int baseIndent) const
  {
    static ostringstream retStream;
    retStream.str("");
    
    getXml(baseIndent, retStream);

    return (xmlChar*)retStream.str().c_str();
  }
  



  const Power& 
  PowerSuppliable::getPowerSupplied() const
  {
    return powerSupplied;
  }
          

  void 
  PowerSuppliable::setPowerSupplied( const Power& newPowerSupplied )
  {
    powerSupplied = newPowerSupplied;
  }        
}
