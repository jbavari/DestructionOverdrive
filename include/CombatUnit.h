/* -*-c++-*- */
#ifndef LD_COMBATUNIT_H
#define LD_COMBATUNIT_H 1

#include <vector>
#include "DamageType.h"
//#include "Power.h"
#include "Damage.h"
#include "Shield.h"
//#include "Armor.h"
#include "ReactorModule.h"
#include "CombatUnitId.h"

using std::vector;


namespace LightningDev
{
  /**
   * Everything that can happen to a combat unit.
   */
  class CombatUnit
  {
  private:
    /**
        Each shield has a capacitor backing it.  Based on the 'amount' Damage
        has it will calculate how much to remove from the capacitor and remove it.
        Each call will also reduce the 'amount' in Damage and return it.
    */
    Damage &DamageShields( Damage &DamageAmount, DamageType DamgeType );

    /**
        Each call will reduce the amount of the ship that is covered by armor
        and will reduce the 'amount' in Damage maybe.  If a part of the ship that is
        not covered is hit the 'amount' in Damage will NOT be reduced and the
        amount of the ship that is covered by armor will NOT be reduced either.
    */
    Damage &DamageArmor( Damage &DamageAmount, DamageType DamgeType );

    /**
        Each call will reduce the amount of core the combat unit has by the 'amount'
        in Damage.  If the 'amount' in Damage is greater than the amount of core
        the combat unit is destroied.
    */
     void DamageCore( Damage &DamageAmount, DamageType DamgeType );
  protected:
//     vector<const Shield&> shields;
//     vector<const Armor&> armor;
//     vector<const ReactorModule&> reactors;
  public:
    virtual ~CombatUnit();
    /**
     *  Used to damage the current ship.  The amount of damage maybe modified by the current 
     *  ship's attributes.
     *
     *  @param damgeAmount Power& to the base damage being dealt.
     *  @param damageType  DamageType& to the type of damage being dealt.
     */
    void damage( const Power& power, const DamageType& type );


    /** The combat unit id.  Needed in maintaining cluster state and gamemaker synchronization */
    const CombatUnitId id;

    /**
       Used to get he shield strength with the current ship setup.
       @return double The shield strength of the ship with the current setup of this ship.
    */
    virtual const Power& getShieldStrength() const;

    /**
       Used to get he armor strength with the current ship setup.
       @return double The shield strength of the ship with the current setup of this ship.
    */
    virtual const Power& getArmorStrength() const;

    /**
       Used to get he core strength with the current ship setup.
       @return double The shield strength of the ship with the current setup of this ship.
    */
    virtual const Power& getCoreStrength() const;


    /**
       This will look at a single weapon in the vector of weapons and return it's damage amount if it were to cause damage.
       This does not check to see if this weapon made contact with an object or if this weapon caused damage or
       anything remotely dealing with if this weapon caused damage.  This is only the amount of damage if it were to cause damage.
       @param Weapon An integer reference in the vector of weapons for this ship.
       @throw 
       @return double The base damage amount the single weapon can cause.
    */
    const Power& getWeaponDamage( int Weapon ) const;

    /**
       This will look at all the weapons moduels in this ship and total all of the damage amount they could inflict.
       This does not check to see if these weapons made contact with an object or if these weapons caused damage or
       anything remotely dealing with if these weapons caused damage.  This is only the amount of damage 
       if these weapons were to cause damage.

       @return double The base damage amount the single weapon can cause.
    */
    const Power& getWeaponDamage() const;

    /**
       This will return the sensor strength of the current ship setup.
       @return double The strength of sensors for the current setup of this ship.
    */
    virtual const Power& getSensorStrength() const;

    /**
       This is the range that the current setup can detected the stats of another ship or object.
       @return double The range to be used in GML that this ship can see the stats of another ship.
    */
    long unsigned int getTargetingRange() const;

    /**
       This is the radius that this ship will effect with it's current setup when it's core levels reach zero.
       @return double This range can be used in GML to test if an object is in range of this ship's explotion radius.
    */
    long unsigned int getExplosionRadius() const;

    /**
       This is the damage that this ship with it's current setup will deal to objects in it's explotion radius.
       @return double Amount of damage this ship will do to object in it's explotion radius.
    */
    long unsigned int getExplosionDamage() const;

    /**
     * Returns a const reference to the CombatUnitId.
     *
     * @return const CombatUnitId& to the id of this CombatUnit.
     */
    const CombatUnitId& getId() const;
    
  };
} /* end namespace LightningDev */



#endif /* LD_COMBATUNIT_H */
