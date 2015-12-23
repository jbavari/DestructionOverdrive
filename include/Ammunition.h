/* -*-c++-*- */
#ifndef LD_AMMO_H
#define LD_AMMO_H 1

#include "DamageType.h"
#include "XmlSerialization.h"

namespace LightningDev
{
  /**
   * This class abstracts ammunition that launchers hold.
   */
  class Ammunition
  {
  private:
    /** The type of damage this does. */
    DamageType damageType;

  public:
    /**
     * Primary Constructor.
     *
     * @param newDamageType const DamageType& to the DamageType this does.
     */
    Ammunition(const DamageType& newDamageType);

    /**
     * Copy Constructor.
     *
     * @param toCopy const Ammunition& to the Ammunition instance to copy from.
     */
    Ammunition(const Ammunition& toCopy);

    /**
     * Returns the damage type caused by this ammunition.
     *
     * @return const DamageType& type of damage caused by this ammunition.
     */
    const DamageType& getDamageType() const;
    
    /**
     * From XmlSerialization
     */
    const xmlChar* getXml(unsigned int baseIndent=0) const;

    /**
     * From XmlSerialization
     */
    void getXml(unsigned int baseIndent, ostream& retStream) const;

    /**
     * Constructs power from an xmlNodePtr at a Power object node.
     *
     * @param inNode xmlNodePtr to the object node of type Power.
     */
    Ammunition(xmlNodePtr inNode);
     
  };

}

#endif /* LD_AMMO_H */
