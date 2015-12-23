/* -*-c++-*- */
#ifndef LD_REACTORMODULE_H
#define LD_REACTORMODULE_H 1

#include "XmlSerialization.h"
#include "Module.h"

namespace LightningDev
{
  class ReactorModule : virtual public XmlSerialization, public Module
    {
    private:
      /**Amount of power supplied each tick. NOW REMOVED.. PowerSuppliable parent
         class has powerSupplied contained in it.
      //const Power powerSupplied; */
    public:
      /**
       * Primary Constructor.
       *
       * @param newPowerSupplied const Power& to the amount of power supplied by this reactor.
       */
      ReactorModule(const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep, 
	   const Power& newMaxUpkeep, const char* newName);

       /** 
         * Copy Constructor
         */
       ReactorModule( const ReactorModule& toCopy );

      /**
       * Xml constructor.
       *
       * @param inNode xmlNodePtr to an object of ReactorModule type.
       */
      ReactorModule(xmlNodePtr inNode);


      /**
       * From XmlSerialziation
       */
      void getXml(unsigned int baseIndent, ostream& retStream) const;


      /**
       * Returns a constant reference to powerSupplied.
       *
       * @return const Power& getPowerSupplied
       */
      const Power& getPowerSupplied() const;
    };
}

#endif /* LD_REACTORMODULE_H */
