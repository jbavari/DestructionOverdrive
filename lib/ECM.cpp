#include "ECM.h"

namespace LightningDev
{
  ECM::ECM( unsigned int Strength, const Power& newPowerSupplied, const Power& newUpkeep, const Power& newSuggestedUpkeep,
	    const Power& newMaxUpkeep, const char* newName, bool newActive )
    :PassiveModule( newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep, newName, newActive )
  {
    strength = Strength;
  }
    
  ECM::ECM( xmlNodePtr inNode )
      :PassiveModule( getParentsObjectNode(inNode, "PassiveModule") )
  {
    for ( xmlNodePtr curNode = inNode->children; curNode != 0; curNode=curNode->next )
      {
        if ( strcmp( getAttributeName( curNode ), "strength" ) == 0 )
	    {
            strength = getULIntAttributeValue( curNode );
        }
      }
  }

  void 
  ECM::getXml( unsigned int baseIndent, ostream& retStream ) const
  {
    getStartObjectElement( baseIndent, "ECM", retStream );
        getStartParentsElement( baseIndent+1, retStream );
        PassiveModule::getXml( baseIndent+2, retStream );
        getEndParentsElement( baseIndent+1, retStream );
        getULIntAttributeElement( baseIndent+1, "strength", strength, retStream );
    getEndObjectElement( baseIndent, retStream );
  }

  unsigned int 
  ECM::getStrength()
  {
    return strength;
  }

  void 
  ECM::setStrength( unsigned int Strength )
  {
    strength = Strength;
  }
}
