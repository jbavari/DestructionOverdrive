/* -*-c++-*- */
#ifndef LD_CAPACITOR_H
#define LD_CAPACITOR_H 1

#include "Power.h"
#include "PowerSuppliable.h"
#include "XmlSerialization.h"
#include "InsufficientPowerException.h"

namespace LightningDev
{
  /**
   * This class abstracts a Capacitor.  It requires time to charge, and
   * a certain amount of power supplied to prevent power loss.  Capacitors
   * may be disscharged to provide a great deal of power at once.
   *
   * Capacitors have values for upkeep and bleedOff.  BleedOff is the amount
   * of power lost every turn to ineficiancies in the capacitor design, upkeep
   * is the amount of power required to 'make up' for this bleedOff.  They are
   * not required to be the same value, and a small difference between the two is
   * encouraged unless the module is very expensive.
   */
  class Capacitor : public PowerSuppliable,
		    virtual public XmlSerialization
  {
  private:
    /* The maximum charge this capacitor */
    const Power maxCharge;

    /* The current charge of this capacitor */
    Power curCharge;

    /** The amount of power supplied to prevent charge loss */
    const Power upkeep;

    /** The amount of power lost every turn */
    const Power bleedOff;
  public:
    /**
     * Primary Constructor.  Constructs a new capacitor with
     * an initial power supplie of newPowerSupplied.
     *
     * @param newMaxCharge unsigned int for the maxCharge this capacitor should hold.
     * @param newCurCharge unsigned int for the charge this capacitor holds to start with
     * @param newUpkeep unsigned int for the minimum power to prevent bleedoff.
     * @param newBleedOff unsigned int the amount of power lost per turn to prevent bleedoff.
     * @param newPowerSupplied unsigned int for the amount of power to be supplied at construction,  defaults to zero.
     */
    Capacitor(unsigned int newMaxCharge, unsigned int newCurCharge,
	      unsigned int newUpkeep,    unsigned int newBleedOff,
	      unsigned int newPowerSupplied=0);

    /**
     * Constructor.  Creates a new Capacitor Object whith
     * an initial power supply of newPowerSupplied.
     *
     * @param newMaxCharge const Power& for the maxCharge this capacitor should hold.
     * @param newCurCharge const Power& for the charge this capacitor holds to start with
     * @param newUpkeep const Power& for the minimum power to prevent bleedoff.
     * @param newBleedOff const Power& the amount of power lost per turn to prevent bleedoff.
     * @param newPowerSupplied const Power& to the amount of power being supplied at construction time.
     */
    Capacitor(const Power& newMaxCharge, const Power& newCurCharge,
	      const Power& newUpkeep,    const Power& newBleedOff,
	      const Power& newPowerSupplied);


    /**
     * Copy constructor.
     * Copies toCopy into a newly created Capacitor Object.
     *
     * @param toCopy const Capacitor& of the Capacitor object to copy from.
     */
    Capacitor(const Capacitor& toCopy);



    /**********************************************************
     *  XmlSerialziation Stuff                                *
     *********************************************************/

    /**
     * XmlNodePtr constructor, inNode should point at an
     * object node with type Capacitor.
     *
     * @param inNode xmlNodePtr to an object node of type Capacitor.
     */
    Capacitor(xmlNodePtr inNode);

    void getXml(unsigned int baseIndent, ostream& retStream) const;

    /**********************************************************
     *  Regular Stuff                                         *
     *********************************************************/


    /**
     * Returns the maximum charge this capacitor can hold.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the maxCharge attribute, not valid after object destruction.
     */
    const Power& getMaxCharge() const;

    /**
     * Returns the current charge this capacitor can hold.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the curCharge attribute, not valid after object destruction.
     */
    const Power& getCurCharge() const;

    /**
     * Returns the upkeep this capacitor requires to prevent bleedoff.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the upkeep attribute, not valid after object destruction.
     */
    const Power& getUpkeep() const;

    /**
     * Returns the amount of charge this capacitor looses to bleedoff every turn.  The
     * returned reference is not valid after this object is
     * destroyed.
     *
     * @return const Power& referring to the maxCharge attribute, not valid after object destruction.
     */
    const Power& getBleedOff() const;

    /**
     * Disscharges the capacitor by amount.
     *
     * @param amount const Power& to the amount of power to disscharge from the capacitor.
     * @throw InsufficientPowerException
     */
    void disscharge(const Power& amount);

    /**
     * Disscharges capacitor by amount.
     *
     * @param amount unsigned int for the amount of power to disscharge from the capacitor.
     * @throw InsufficientPowerException
     */
    void disscharge(unsigned int amount);

    /**
     * Disscharges the entire charge in this capacitor.
     * 
     * @return the amount of power disscharged.
     */
    Power disscharge();
  };
} /* namespace LightningDev */


#endif /* LD_CAPACITORMODULE_H */
