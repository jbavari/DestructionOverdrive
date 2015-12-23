/* -*-c++-*- */
#ifndef LD_ECM_H
#define LD_ECM_H 1

#include "PassiveModule.h"
#include "XmlSerialization.h"

namespace LightningDev
{
  /**
   * Modules in this class attempt to obscure enemy sensors.
   */
  class ECM : public PassiveModule,
              virtual public XmlSerialization
  {
    private:
        unsigned int strength;
    public:

        /**
            Constructor for ECM.
            @param Strength Sets the strength for this sensor as it's made.
        */
        ECM( unsigned int Strength, const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
	     const Power& newMaxUpkeep, const char* newName, bool newActive = false );

        /**
            Constructor using a xmlNodePtr to build this sensor.
            @param inNode This is a xmlNodePtr for building this sensor from.
        */
        ECM(xmlNodePtr inNode);

        /**
         * From XmlSerialization
         */
        void getXml( unsigned int baseIndent, ostream& retStream ) const;

        /**
            Gets the strength that this sensor works at.
            @return unsigned int The strength that this sensor works at.
        */
        unsigned int getStrength();

        /**
            Sets the strength that this sensor can see.
            @param strength The strength that this sensor can see.
        */
        void setStrength( unsigned int strength );
  };
}


#endif /* LD_ECM_H */
