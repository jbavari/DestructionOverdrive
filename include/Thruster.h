/* -*-c++-*- */

#ifndef LD_THRUSTER_H
#define LD_THRUSTER_H 1

#include "CapacitorModule.h"
/* #include "Fireable.h" */

namespace LightningDev
{
  /**
   * Thrustors cause the ship to move.
   * Generally, the more powerfull the thrustors (additive)
   * the faster the ship moves.
   */
  class Thruster : public CapacitorModule, virtual public XmlSerialization
  /* public Fireable */
  {
  private:
    /** The amount of thrust this thruster can provide */
    Power thrust;
  public:
    /**
     * Primary Constructor.
     *
     * Constructs a new thruster object with thrust newThrust.
     *
     * @param newThrust const Power& to the amount of thrust this thruster can provide
     */
    Thruster(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
                    const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
                    const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff, const Power& newThrust);

    /**
     * Copy Constructor.
     * Copies toCopy into a newly created Thruster instance.
     *
     * @param toCopy const Thruster& to the Thruster to copy from.
     */
    Thruster(const Thruster& toCopy);
    
    /** 
      * Xml Serialization Constructor
      */
    Thruster( xmlNodePtr inNode);

    /**
     * Returns the amount of thrust this thruster provides.
     *
     * @return const Power& the amount of thrust this module provides.
     */
    const Power& getThrust() const;
    
    /**
       * From XmlSerialziation
       */
    void getXml(unsigned int baseIndent, ostream& retStream) const;
  };
}


#endif /* LD_THRUSTERS_H */
