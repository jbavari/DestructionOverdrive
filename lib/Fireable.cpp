#include "Fireable.h"
#include "Power.h"

namespace LightningDev
{          
          Fireable::Fireable( const Power& newPowerRequired, const float& newAccuracy, 
                              const unsigned int& newRange, const unsigned int& newRefractTime,
                              const unsigned int& newTimeTillFire ) 
                              :
                              powerRequired(newPowerRequired), accuracy(newAccuracy),
                              range(newRange), refractTime(newRefractTime),
                              timeTillFire(newTimeTillFire)
          { }
          
          Fireable::Fireable( const Fireable& toCopy ) : powerRequired(toCopy.powerRequired),
                              accuracy(toCopy.accuracy), range(toCopy.range), refractTime(toCopy.refractTime),
                              timeTillFire(toCopy.timeTillFire)
          { }
          
          Fireable::Fireable( xmlNodePtr inNode ) : powerRequired(getObjectAttributeObject(inNode, "powerRequired")),
                              accuracy( getFloatAttributeValueByName(inNode, "accuracy")),
                              range( getULIntAttributeValueByName(inNode, "range")),
                              refractTime( getULIntAttributeValueByName(inNode, "refractTime")),
                              timeTillFire(getULIntAttributeValueByName(inNode, "timeTillFire"))
          { }
          
          void Fireable::fire(const CombatUnit& target)
          {
               
          }
          
          const float& Fireable::getAccuracy() const
          {
                return accuracy;
          }
          
          const unsigned int& Fireable::getRange() const
          {
                return range;
          }

          const Power& Fireable::getPowerRequired() const
          {
                return powerRequired;
          }
          
          const unsigned int& Fireable::getRefractTime() const
          {
                return refractTime;
          }
          
          const unsigned int& Fireable::getTimeTillFire() const
          {
                return timeTillFire;
          }
    
          void Fireable::getXml( unsigned int baseIndent, ostream& retStream )
          {
               getStartObjectElement(baseIndent, "Fireable", retStream);
               getObjAttributeElement(baseIndent+1, "powerRequired", "Power", powerRequired, retStream);
               getFloatAttributeElement(baseIndent+1, "accuracy", accuracy, retStream);
               getULIntAttributeElement(baseIndent+1, "range", range, retStream);
               getULIntAttributeElement(baseIndent+1, "refractTime", refractTime, retStream);
               getULIntAttributeElement(baseIndent+1, "timeTillFire", timeTillFire, retStream);
               getEndObjectElement(baseIndent, retStream);     
          }
}
