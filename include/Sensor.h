/* -*-c++-*- */
#ifndef LD_SENSOR_H
#define LD_SENSOR_H 1

#include "PassiveModule.h"
#include "XmlSerialization.h"

namespace LightningDev
{
  /**
   * Sensors allow ships to sence the environment, the
   * better the sensors, the better they sence.
   */
  class Sensor : public PassiveModule,
                 virtual public XmlSerialization
  {
    private:
        unsigned int range;
    public:
        /**
            Constructor for Sensor.
        */
        Sensor();

        /**
            Constructor for Sensor.
            @param Range Sets the range for this sensor as it's made.
        */
        Sensor( unsigned int Range, const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
	            const Power& newMaxUpkeep, const char* newName, bool newActive );


        /**
            Constructor for Sensor.
            @param Range Sets the range for this sensor as it's made.
        */
        Sensor( unsigned int range );

        /**
            Constructor using a xmlNodePtr to build this sensor.
            @param inNode This is a xmlNodePtr for building this sensor from.
        */
        Sensor(xmlNodePtr inNode);

        /**
         * From XmlSerialization
         */
        void getXml( unsigned int baseIndent, ostream& retStream ) const;

        /**
            Gets the range that this sensor works at.
            @return unsigned int The range that this sensor works at.
        */
        unsigned int getRange();

        /**
            Sets the range that this sensor can see.
            @param range The range that this sensor can see.
        */
        void setRange( unsigned int range );
  };
};


#endif /* LD_SENSOR_H */
