/* -*-c++-*- */
#ifndef LD_DAMAGETYPE_H
#define LD_DAMAGETYPE_H

#include "XmlSerialization.h"
#include "OutOfDomainException.h"

namespace LightningDev
{
  
  /**
   * Abstracts the damage components, kinetic and radiant.
   * Kinetic damage is done by chunks of matter slamming into
   * other chunks of matter.  Radiant is from a laser beam.
   *
   * So, basic slugs (as get fired from a gun), deal kinetic
   * damage.  Basic lasers deal radiant damage.  Missiles deal
   * deal blended damage.
   *
   * kinetic + radiant = 1 at all times.  As they represent a
   * percent of the total damage done.
   */
  class DamageType : public virtual XmlSerialization
  {
  private:
    /** 
     * Percent of Damage wich is kinetic, radiant damage is
     * computed from this as radient = 1-kinetic.
     */ 
    float kinetic;

  public:
    /**
     * Primary Constructor.
     * Defaults to a 50/50 power distribution with no parameters.  With
     * a single parameter, the percent of power for the remaining attribute
     * is computed automatically.
     * 
     * @param kinetic float between 0 and 1 which represents the percent of damage whic is kinetic.
     * @throw OutOfDomainException when kinetic is less than 0 or greater than 1.
     */
    DamageType(float newKinetic=0.5);

    /**
     * Copy Constructor.
     *
     * @param toCopy const DamageType& to the DamageType instance to copy from.
     */
    DamageType(const DamageType& toCopy);



    /**********************************************************
     *  XmlSerialziation Stuff                                *
     *********************************************************/

    /**
     * XmlNodePtr constructor, inNode should point at an
     * object node with type Capacitor.
     *
     * @param inNode xmlNodePtr to an object node of type Capacitor.
     */
    DamageType(xmlNodePtr inNode);

    const xmlChar* getXml(unsigned int baseIndent=0) const;
    void getXml(unsigned int baseIndent, ostream& retStream) const;

    /**********************************************************
     *  Regular Stuff                                         *
     *********************************************************/




    /**
     * Returns the percentage of kinetic damage as a float between 0 and 1.  1 is 100 percent
     * and 0 is zero percent.
     *
     * @return float between 0 and 1 representing the percent of damage which is kinetic.
     */
    float getKinetic() const;

    /**
     * Returns the percentage of radiant damage as a float between 0 and 1.  1 is 100 percent
     * and 0 is zero percent.
     *
     * @reutnr float between 0 and 1 representing the percent of damage which is radiant.
     */
    float getRadiant() const;
  };
}


#endif /* LD_DAMAGETYPE_H */
