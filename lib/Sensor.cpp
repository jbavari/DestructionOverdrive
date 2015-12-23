#include "Sensor.h"

namespace LightningDev
{

    Sensor::Sensor( unsigned int Range, const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
	    const Power& newMaxUpkeep, const char* newName, bool newActive )
    :PassiveModule( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName, newActive ),
    range( Range )
    {
    }


    Sensor::Sensor(xmlNodePtr inNode)
           :PassiveModule( getParentsObjectNode(inNode, "PassiveModule") )
    {
      for ( xmlNodePtr curNode = inNode->children; curNode != 0; curNode=curNode->next )
      {
        if ( strcmp( getAttributeName( curNode ), "range" ) == 0 )
        {
            range = getULIntAttributeValue( curNode );
        }
      }
    }

    void Sensor::getXml( unsigned int baseIndent, ostream& retStream ) const
    {
     getStartObjectElement( baseIndent, "Sensor", retStream );
        getStartParentsElement( baseIndent+1, retStream );
                PassiveModule::getXml( baseIndent+2, retStream );
        getEndParentsElement( baseIndent+1, retStream );
        getULIntAttributeElement( baseIndent+1, "range", range, retStream );
     getEndObjectElement( baseIndent, retStream );

    }

    unsigned int Sensor::getRange()
    {
        return range;
    }

    void Sensor::setRange( unsigned int Range )
    {
        range = Range;
    }
}
