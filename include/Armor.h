/* -*-c++-*- */
#ifndef LD_ARMOR_H
#define LD_ARMOR_H 1

#include "Power.h"
#include "Damage.h"
#include "PowerSuppliable.h"
#include "XmlSerialization.h"
#include <string>
#include "Module.h"

namespace LightningDev
{
  class Armor : public Module, virtual public XmlSerialization
  {
  private:
          /** percent of ship covered by armor */
          float coverage;
          
          /** The strenght of this armor */
          const Damage strength;
  public:
          
         /**
          * Primary Constructor.
          * @param coveragePercent represents armor coverage
          */
          Armor(const Power& newPowerSupplied, const Power& newUpkeep,
                const Power& newSuggestedUpkeep, const Power& newMaxUpkeep,
                const char* newName, float coveragePercent, const Damage newStrength);
         
         /**
          * Copy Constructor.
          * @param toCopy const Armor& represents Armor object to copy from
          */
          Armor(const Armor& toCopy);
         
         /** return armor coverage for the ship
          */
          float getCoverage() const;
         
         /** returns a reference to the damage amount called strength that the
          *  ship can handle
          */
          const Damage& getDamage() const;
         
         
          /** From XmlSerialization
           */
           const xmlChar* getXml(unsigned int baseIndent=0) const;

          /**
           * From XmlSerialization
           */
           void getXml(unsigned int baseIndent, ostream& retStream) const;

          /**
           * Constructs Armor from an xmlNodePtr to an Armor object node.
           * @param inNode xmlNodePtr to the object node of type Armor.
           */
           Armor(xmlNodePtr inNode);
  };
}


#endif /* LD_ARMOR_H */
