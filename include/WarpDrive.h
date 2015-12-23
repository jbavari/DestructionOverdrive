/* -*-c++-*- */
#ifndef LD_WARPDRIVE_H
#define LD_WARPDRIVE_H 1

#include "Thruster.h"

namespace LightningDev
{
  /**
   * This special class of thruster allows a ship to 'jump' between two
   * points in space without traveling between them.
   */
  class WarpDrive : public Thruster, virtual public XmlSerialization
  {     private:
                /** The power in which thrust will be increased. */
                Power& increaseThrust;
        public:
               /**
                 * Primary constructor
                 *
                 */
               WarpDrive( const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
                    const Power& newMaxUpkeep, const char* newName, const Power& newMaxCharge,
                    const Power& newCurCharge, const Power& newCUpkeep, const Power& newBleedOff, const Power& newThrust,
                    const Power& newIncreaseThrust);

               /**
                 * Copy Constructor
                 */
               WarpDrive( const WarpDrive& toCopy ); 
               
               /**
                 * Xml Serialization Constructor 
                 */
               WarpDrive( xmlNodePtr inNode );
               
               /**
                 * Xml Serialization output
                 */
               void getXml( unsigned int baseIndent, ostream& retStream );
  };
}


#endif /* LD_WARPDRIVE_H */
