/* -*-c++-*- */
#include "XmlSerialization.h"
#include "ReactorModule.h"
#include "CapacitorModule.h"

namespace LightningDev
{
      ReactorModule::ReactorModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
	   const Power& newMaxUpkeep, const char* newName) :
             Module(newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName)
      { }

      ReactorModule::ReactorModule(const ReactorModule& toCopy ) : Module(toCopy)
      { }

      ReactorModule::ReactorModule(xmlNodePtr inNode) : Module(getParentsObjectNode(inNode, "Module"))
      { }

      void ReactorModule::getXml(unsigned int baseIndent, ostream& retStream) const
      {
           getStartObjectElement(baseIndent, "ReactorModule", retStream);
           getStartParentsElement(baseIndent+1, retStream);
           Module::getXml(baseIndent+2, retStream);
           getEndParentsElement(baseIndent+1, retStream);
           getEndObjectElement(baseIndent, retStream);
      }

      /**
       * Returns a constant reference to powerSupplied.
       * NOTE: Use PowerSuppliable.getPowerSupplied() instead of this.
       *
       * @return const Power& getPowerSupplied
       
      const Power& getPowerSupplied() const
      */
}
