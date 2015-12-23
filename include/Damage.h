/* -*-c++-*- */
#ifndef LD_DAMAGE_H
#define LD_DAMAGE_H 1

#include "DamageType.h"
#include "Power.h"

namespace LightningDev
{
  /**
   * This class abstracts the concept of Damage.
   * Damage consists power, or strength, and
   * What type.  Damage is immutable.
   */
  class Damage : virtual public XmlSerialization
  {
  private:
    /** Amount of Damage dealt, or the 'strength' of the damage */
    Power amount;

    /** Type of damage dealt */
    DamageType type;
  public:
    /**
     * Default constructor.  Probably shouldn't ever be used, but here
     * to prevent the compiler defaults.
     */
    Damage();

    /**
     * Primary constructor.
     *
     * @param newAmount const Power& which will be copied into amount.
     * @param newType const DamageType& which will be copied into type.
     */
    Damage(const Power& newAmount, const DamageType& newType);

    /**
     * Copy Constructor.
     *
     * @param toCopy const Damage& to the Damage instance to copy from.
     */
    Damage(const Damage& toCopy);

    /**
     * XmlSerialization constructor.
     * Accepts an xmlNodePtr to a object type="Damage" element and constructs a
     * damage instance from it.
     *
     * @param inNode xmlNodePtr to a Damage type object element.
     */
    Damage(xmlNodePtr inNode);

    /** From XmlSerialization */
    void getXml(unsigned int baseIndent, ostream& retStream) const;

    /**
     * Returns a constant reference to the amount attribute.
     *
     * @return const Power& to the amount of power this Dammage deals.
     */
    const Power& getAmount() const;

    /**
     * Returns a constant DamageType reference to the type of Damage this
     * damage instance deals.
     *
     * @return const DamageType& to the type of damage dealt by this Damage.
     */
    const DamageType& getType() const;
  };
}

#endif
