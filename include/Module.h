/* -*-c++-*- */
#ifndef LD_MODULES_H
#define LD_MODULES_H 1

#include <string>
using std::string;
#include "Power.h"
#include "PowerSuppliable.h"

namespace LightningDev
{
  /**
   * This is the fundamental type for all modules.
   */
  class Module : public PowerSuppliable, virtual XmlSerialization
  {
  private:
    /** 
     * How much power per turn this module requires to stay active.
     */
    Power upkeep;

    /** 
     * How much power per turn this module suggests be provided to it.
     * This is arbitrarily set by the module designer, but it is suggested
     * that this value reflect the minimum value required for proper use
     * of this module.
     */
    Power suggestedUpkeep;

    /**
     * The point at which additional power no longer provides any benifit to
     * the use of this module.
     */
    Power maxUpkeep;


    /**
     * The name of this module
     */
    string name;
  public:
    /**
     * The Primary constructor.
     *
     * @param newUpkeep const Power& reflecting the upkeep of this Module.
     * @param newSuggestedUpkeep const Power& reflecting the suggested upkeep of this Module.
     * @param newMaxUpkeep const Power& reflecting the maxUpkeep of this Module.
     * @param name const char* of the modules name.
     */
    Module( const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
	   const Power& newMaxUpkeep, const char* newName);

    /**
     * A convieniance constructor using unsigned ints instead of Power objects.
     *
     * @param newUpkeep const unsigned int reflecting the upkeep of this Module.
     * @param newSuggestedUpkeep const unsigned int reflecting the suggested upkeep of this Module.
     * @param newMaxUpkeep const unsigned int reflecting the maxUpkeep of this Module.
     * @param name const char* of the modules name.
     Ignore this for now.
    Module(unsigned int newUpkeep, unsigned int newSuggestedUpkeep, 
	   unsigned int newMaxUpkeep, char* newName);
     */ 
    /**
     * Copy constructor.
     *
     * @param toCopy const Module& reference to the Module object to copy, or clone.
     */
    Module(const Module& toCopy);
    
    /***************************************************************************
    *  XmlSerialization Stuff                                                  *
    ***************************************************************************/
    
    /** Constructor for XML Node pointer. */
    Module(xmlNodePtr inNode);
    
    /** Function that will get called from getXml(unsigned int baseIndent). */
    void getXml(unsigned int baseIndent, ostream& retStream) const;
    
    /**
     * Returns the upkeep cost of this Module.  Upkeep cost is the minimum amount
     * of power required for this Module to function.  The returned reference is not valid after
     * the object is destroyed.
     *
     * @return const Power& to the upkeep cost.  Not valid after object destruction.
     */
    const Power& getUpkeep() const;

    /**
     * Returns the suggested upkeep cost of this module.  Suggested
     * upkeep cost is the amount of power the module designer recomends for effective use of this
     * module.  The returned reference is not valid after object destruction.
     *
     * @return const Power& to suggestedUpkeep. 
     */
    const Power& getSuggestedUpkeep() const;

    /**
     * Returns the max upkeep cost of this Module.  The max upkeep is the point at which
     * further power does not increase the efficacy of this Module.  The returned reference
     * is not valid after this object is destroyed.
     *
     * @return const Power& to the maxUpkeep of this Module.
     */
    const Power& getMaxUpkeep() const;

    /**
     * Returns the modules name.  The reference is invalid after the object is
     * destroyed.
     *
     * @return const string& to the modules name.  The reference
     *         is invalid after the object is destroyed.
     */
    const string& getName() const;
  };
}

#endif /* LD_MODULES_H */
