/* -*-c++-*- */
#ifndef LD_CAPACITORMODULE_H
#define LD_CAPACITORMODULE_H 1

#include "Power.h"
#include "Capacitor.h"
#include "Module.h"

namespace LightningDev
{
  class CapacitorModule : public Module,
                          virtual public XmlSerialization
  {
  protected:
    /** The capacitors in this module. */
    Capacitor capacitor;
  public:
    /**
     * Primary constructor.
     * Establishes the number of capacitors as numCapacitors and sets them all to the given values.
     * 
     * If numCapacitors is zero, throws a PositiveIntExpectedException.
     *
     * @param newMaxCharge unsigned int for the maxCharge this capacitor should hold.
     * @param newCurCharge unsigned int for the charge this capacitor holds to start with
     * @param newUpkeep unsigned int for the minimum power to prevent bleedoff.
     * @param newBleedOff unsigned int the amount of power lost per turn to prevent bleedoff.
     * @param newPowerSupplied unsigned int for the amount of power to be supplied at construction,  defaults to zero.
     * @param newNumCapacitors unsigned int which must be greater than zero.
     * @throw PositiveIntExpectedException
     */
     /* Ignore this convenience constructor for now.
    CapacitorModule(unsigned int newMaxCharge,       unsigned int newCurCharge,
		    unsigned int newUpkeep,          unsigned int newBleedOff,
		    unsigned int newPowerSupplied=0, unsigned int newNumCapacitors=1);
      */

    /**
     * Primary constructor.
     * Establishes the number of capacitors as numCapacitors and sets them all to the given values.
     *
     * @param newMaxCharge const Power& for the maxCharge this capacitor should hold.
     * @param newCurCharge const Power& for the charge this capacitor holds to start with
     * @param newUpkeep const Power& for the minimum power to prevent bleedoff.
     * @param newBleedOff const Power& the amount of power lost per turn to prevent bleedoff.
     * @param newPowerSupplied const Power& to the amount of power being supplied at construction time.
     * @param newNumCapacitors unsigned int which must be greater than zero.
     * @throw PositiveIntExpectedException
     */
    CapacitorModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
                    const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
                    const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff);

      /** Constructor for which a capacitor would already be set up and ready
        * for placement.
        */
    CapacitorModule(const Power& newPowerSupplied, const Power& newUpkeep, 
               const Power& newSuggestedUpkeep, const Power& newMaxUpkeep, const char* newName, 
               const Capacitor& newCapacitor);
      

    /**
     * Constructor for use whith a non-homogonouse set of capacitors.
     *
     * @param newNumCapacitors unsigned int for the number of capacitors this will hold..
     */
     /* Unknown constructor, ignore for now *******************************
    CapacitorModule(unsigned int newNumCapacitors);
    */


    /**
     * Copy Constructor.
     *
     * @param toCopy const CapacitorModule& of the Capacitor object to copy from.
     */
    CapacitorModule(const CapacitorModule& toCopy);

    /** Xml Serialization Constructor */
    CapacitorModule( xmlNodePtr inNode );

    /**
     * Returns the maximum charge capacitor can hold.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the maxCharge attribute, not valid after object destruction.
     */
    const Power& getCapacitorMaxCharge() const;

    /**
     * Returns the current charge capacitor can hold.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the curCharge attribute, not valid after object destruction.
     */
    const Power& getCapacitorCurCharge() const;

    /**
     * Returns the upkeep this capacitor requires to prevent bleedoff.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the upkeep attribute, not valid after object destruction.
     */
    const Power& getCapacitorUpkeep() const;

    /**
     * Returns the amount of charge this capacitor looses to bleedoff every turn.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the maxCharge attribute, not valid after object destruction.
     */
    const Power& getCapacitorBleedOff() const;
    
    
    /** XML STUFF *****************************************/
    void getXml(unsigned int baseIndent, ostream& retStream) const;
  };
}


#endif /* LD_CAPACITORMODULE_H */
