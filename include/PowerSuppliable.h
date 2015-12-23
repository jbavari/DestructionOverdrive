/* -*-c++-*- */
#ifndef LD_POWERSUPPLIABLE_H
#define LD_POWERSUPPLIABLE_H 1

#include "Power.h"

namespace LightningDev
{
  /**
   * Defines the amount of power supplied to 
   * objects which use power.
   */
  class PowerSuppliable : virtual public XmlSerialization
  {
  private:
    Power powerSupplied;
  public:
    /**
     * Primary constructor.  Accepting an unsigned int for the
     * amount of power supplied after construction, which defaults
     * to zero.
     *
     * @param newPowerSupplied unsigned int for the amount of power supplied after construction, defaults to zero.
     */
    PowerSuppliable(unsigned int newPowerSupplied=0);

    /**
     * Constructor which accepts a const Power refernce for the
     * amount of power supplied at construction time.
     *
     * @param newPowersupplied const Power& to the amount of power supplied after construction.
     */
    PowerSuppliable(const Power& newPowerSupplied);
    

    /**
     * Copy Constructor
     *
     * @param toCopy const PowerSuppliable& to the PowerSuppliable object to copy.
     */
    PowerSuppliable(const PowerSuppliable& toCopy);



    /**************************************************************************
     *  XmlSerialization stuff
     *************************************************************************/

    /**
     * xml constructor
     *
     * @param inNode xmlNodePtr to an object node of PowerSuppliable type.
     */
    PowerSuppliable(xmlNodePtr inNode);

    void getXml(unsigned int baseIndent, ostream& retStream) const;
    const xmlChar* getXml(unsigned int baseIndent=0) const;


    /**************************************************************************
     * Regular members
     **************************************************************************/

    /**
     * Returns a reference to the amount of power currently supplied.  The
     * reference is not valid after object destruction.
     *
     * @return const Power& to the powerSupplied attribute.
     */
    const Power& getPowerSupplied() const;

    /**
     * Sets the amount of power supplied.
     *
     * @param newPowerSupplied const Power& to the new amount of Power to be supplied.
     */
    void setPowerSupplied(const Power& newPowerSupplied);
  };
}

#endif
