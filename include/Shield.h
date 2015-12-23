/* -*-c++-*- */
#ifndef LD_SHIELD_H
#define LD_SHIELD_H 1

#include "CapacitorModule.h"
#include "XmlSerialization.h"
#include "DamageType.h"

namespace LightningDev
{
  /**
   * Abstracts the concept of a defense shield.  Like in Star Trek, and
   * every Science Fiction novel writen thereafter.  Shields soak damage
   * dependant upon damage type.
   */
  class Shield : public CapacitorModule, virtual public XmlSerialization
  {
  private:
    /** The shield's efficiency at blocking damage based on type. */
    DamageType typeEfficiency;

    /** 
     * The shield's base efficiency. This attribute
     * reflects how much power is concumed by the mechanism when
     * soaking damage.
     */
    float baseEfficiency;
  public:
    
    /**
      * Primary Constructor
      */
    
    Shield(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
                    const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
                    const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff, 
                    const DamageType& newTypeEfficiency, const float& newBaseEfficiency);
                    
    /**
      * Copy Constructor
      */
    Shield( const Shield& toCopy );
    
    /** 
      * Xml Serialization Constructor
      */
    Shield( xmlNodePtr inNode);
    
    /** 
      * Accessor method for typeEfficiency
      */
    const DamageType& getTypeEfficiency() const;
    
    /** 
      * Accessor method for baseEfficiency
      */
    const float& getBaseEfficiency() const;
    
    /**
      * Xml Serialization
      */
    void getXml(unsigned int baseIndent, ostream& retStream) const;
  };
}

#endif /* LD_SHIELD_H */
