/* -*-c++-*- */
#include "Damage.h"

namespace LightningDev
{
  

  Damage::Damage()
  {
  }
  
  
  Damage::Damage(const Power& newAmount, const DamageType& newType)
      :amount(newAmount),
       type(newType)
  {
  }
  
  
  Damage::Damage(const Damage& toCopy)
      :amount(toCopy.amount),
       type(toCopy.type)
  {
  }
  
  
  Damage::Damage(xmlNodePtr inNode)
      :amount(getObjectAttributeObject(inNode, "amount")),
       type(getObjectAttributeObject(inNode, "type"))
  {
  }
  
  
  void 
  Damage::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "Damage", retStream);
    getObjAttributeElement(baseIndent+1, "amount", "Power", amount, retStream);
    getObjAttributeElement(baseIndent+1, "type", "DamageType", type, retStream);
    getEndObjectElement(baseIndent, retStream);
  }
  
  
  const Power& 
  Damage::getAmount() const
  {
    return amount;
  }
  
  
  const DamageType& 
  Damage::getType() const
  {
    return type;
  }
  
} /* namespace LightningDev */
