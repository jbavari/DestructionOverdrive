/* -*-c++-*- */
#ifndef LD_PASSIVE_MODULE_H
#define LD_PASSIVE_MODULE_H 1

#include "Module.h"

namespace LightningDev
{
  /**
   * A passive module is one which, so long as it has power,
   * is always working.  Things like sensors, missile bay, etc... 
   */
  class PassiveModule : public Module, virtual public XmlSerialization
  {
  private:
    bool active;
  public:
    /**
     * Primary Constructor.
     * @param newUpkeep const Power& reflecting the upkeep of this Module.
     * @param newSuggestedUpkeep const Power& reflecting the suggested upkeep of this Module.
     * @param newMaxUpkeep const Power& reflecting the maxUpkeep of this Module.
     * @param newActive bool if the module is active after construction, the default is false.
     */
    PassiveModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
		  const Power& newMaxUpkeep, const char* newName, bool newActive=false);

    /** 
      * Copy Constructor
      */
    PassiveModule( const PassiveModule& toCopy );
    
    /**
      * Xml Serialization constructor.
      */
    PassiveModule(xmlNodePtr inNode);

    /**
     * A convieniance constructor using unsigned ints instead of Power objects.
     *
     * @param newUpkeep const unsigned int reflecting the upkeep of this Module.
     * @param newSuggestedUpkeep const unsigned int reflecting the suggested upkeep of this Module.
     * @param newMaxUpkeep const unsigned int reflecting the maxUpkeep of this Module.
     * @param newActive bool if the module is active after construction, the default is false.
     */
//     Module(const unsigned int newUpkeep, const unsigned int newSuggestedUpkeep, 
// 	   const unsigned int newMaxUpkeep, bool newActive=false);


    /**
     * Returns true if this module is currently active (has enough power)
     */
    bool isActive();
    
    
    /** XmlSerialization Stuff.. */
    void getXml(unsigned int baseIndent, ostream& retStream) const;
  };
}


#endif /* LD_PASSIVE_MODULE_H */
