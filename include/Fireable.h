/* -*-c++-*- */
#ifndef LD_WEAPON_H
#define LD_WEAPON_H 1

#include "CombatUnit.h"
#include "XmlSerialization.h"
#include "Power.h"

namespace LightningDev
{
  /**
   * This class abstracts the properties of a weapon
   */
  class Fireable : virtual public XmlSerialization
  {
  private:
    /** Amount of power required to fire this object, zero is explicitly allowed. */
    const Power powerRequired;

    /** Base accuracy of this object */
    const float accuracy;

    /** Base range of this object */
    const unsigned int range;

    /** Time it takes this object to be prepaired to fire again, in game ticks */
    const unsigned int refractTime;

    /** Time to fire.  Time left until this object may fire again */
    unsigned int timeTillFire;
  public:
    /**
     * Primary Constructor.
     *
     * @param newPowerRequired const Power& to the amount of power required to fire this object.
     * @param newAccuracy float the accuracy of this weapon, a value between 0 and 1.
     * @param newRange unsigned int the range of this weapon.
     * @param newRefractTime unsigned int the time required between fireings of this object.
     * @throw OutOfDomainException when newAccuracy is below zero or greater than 1.
     */
    Fireable( const Power& newPowerRequired, const float& newAccuracy, 
                              const unsigned int& newRange, const unsigned int& newRefractTime,
                              const unsigned int& newTimeTillFire );

    /** 
      * Copy Constructor
      */
    Fireable( const Fireable& toCopy );

    /** 
      * Xml Serialization Constructor
      */
    Fireable( xmlNodePtr inNode );
    
    /**
     * Causes the object to fire.
     * The details of this operation are greatly dependant
     * upon what type of module is fireing.  MissleLaunchers instantiate
     * a new missile with the new target.  Lasers directly compute hit and
     * call dammage methods.
     *
     * This implementation should provide refractTime and range computations.
     *
     * @param target const Targetable& to the object to fire at.
     * @throw RefractException when insufficient time has passed since the last fire attempt.
     * @throw OutOfRangeException when the target is out of range.
     */
    void fire(const CombatUnit& target);

    /**
     * Returns the accuracy of this object, a value between 0 and 1;
     *
     * @return const float& the accuracy of this object.
     */
    const float& getAccuracy() const;

    /**
     * Returns the maximum range of this object.
     *
     * @return const unsigned int& the maximum range of this object.
     */
    const unsigned int& getRange() const;

    /**
      * Returns the refract time of this object.
      *
      * @return const unsigned int the refract time of this object.
      */
    const unsigned int& getRefractTime() const;
    
    /**
      * Returns the time till fire of this object.
      *
      * @return const unsigned int& the time until this object can fire.
      */
    const unsigned int& getTimeTillFire() const;
    
    /**
     * Returns a const Power& to the power required to fire this
     * object.  This refernce in invalid when this is destroyed.
     *
     * @return const Power& of the amount of power required to fire this object, invalid if this is destroyed.
     */
    const Power& getPowerRequired() const;
    
    /**
      * Xml Serialization output method
      */
    void getXml( unsigned int baseIndent, ostream& retStream );
  };
}

#endif /* LD_WEAPON_H */
