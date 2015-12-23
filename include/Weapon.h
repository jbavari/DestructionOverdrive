/* -*-c++-*- */

#ifndef LD_WEAPON_H
#define LD_WEAPON_H 1

#include "Module.h"
#include "Power.h"
#include "DamageType.h"

namespace LightningDev
{
  /**
   * A weapon is anything which can be used to cause damage to another player.
   */
  class Weapon : public Fireable, virtual public XmlSerialization
  {
  private:
    /** Amount Damage this weapon causes.  It may be modified based on other attributes at fire time */
    Power baseDamage;

    /** Type of damage this weapon causes. */
    DamageType damageType;

    /** The maximum amount of radiant damage this weapon can deal */
    DamageType maxRadiant;

    /** The maximum amount of kinetic damage this weapon can deal */
    DamageType maxKinetic;

    /** The maximum power this weapon can deal */
    Power maxBaseDamage;
  public:
    /**
     * Primary Constructor.
     *
     * @param baseDamage const Power& to the base damage this weapon may cause.
     * @param damageType const DamageType& to the types of damage this weapon causes.
     */
    Weapon(const Power& baseDamage, const DamageType& damageType);

    /**
     * Copy Constructor.
     * Copies toCopy into newly created Weapon
     *
     * @param toCopy const Weapon& to the weapon instance to copy from.
     */
    Weapon(const Weapon& toCopy);

    /**
      * Xml Serialization constructor
      */
    Weapon( xmlNodePtr inNode );

    /**
     * Returns a constant reference to the base damage attribute.
     *
     * @return const Power& reflecting the base amount of damage this weapon can cause.
     */
    const Power& getBaseDamage() const;

    /**
     * Returns a constant reference to the DamageType attribute.
     */
    const DamageType& getDamageType() const;

    /**
     * Adjusts the power this weapon can deal by amount.  Here
     * we are discussing the attribute baseDamage, which must be
     * between zero and maxBaseDamage.
     *
     * It is not an error for amount to cause baseDamage to move out
     * of range, rather baseDamage is set at the most extreme value closest
     * to the resultant figure.  I.e. if the adjusted amount would be larger
     * than maxBaseDamage, baseDamage is set at maxBaseDamage.
     *
     * @param amount int amount to adjust baseDamage by, negative numbers are explicitly allowed.
     */
    void adjustPower(int amount);


    /**
     * Adjusts the damage type this weapon deals by amount.  Here
     * we are discussing the attribute damageType.
     *
     * It is not an error for amount to cause damageType to go out
     * of bounds, instead damageType is set in such that damageType.kinetic
     * is closest to the resultant amoutn without going over one, or below zero.
     *
     * DamageType is restricted such that radiant+kinetic = 1 for all valid values
     * of radiant and kinetic.  Thus, the result of adjusting the kinetic damage,
     * will also adjust radiant damage by the same amount in the opposite direction.
     *
     * @param amount int amount to adjust damageType.kinetic by, negative numbers are explicitly allowed.
     */
    void adjustKinetic(float amount);


    /**
     * Adjusts the damage type this weapon deals by amount.  Here
     * we are discussing the attribute damageType.
     *
     * It is not an error for amount to cause damageType to go out
     * of bounds, instead damageType is set in such that damageType.radiant
     * is closest to the resultant amoutn without going over one, or below zero.
     *
     * DamageType is restricted such that radiant+kinetic = 1 for all valid values
     * of radiant and kinetic.  Thus, the result of adjusting the radiant damage,
     * will also adjust kinetic damage by the same amount in the opposite direction.
     *
     * @param amount float amount to adjust damageType.radiant by, negative numbers are explicitly allowed.
     */
    void adjustRadiant(float amount);
    
    /** 
      * Xml Serialization Output
      */
    void getXml( unsigned int baseIndent, ostream& retStream );
  };
  
};
#endif /* LD_WEAPON_H */
