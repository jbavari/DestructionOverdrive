#include "CombatUnitId.h"

#include <iostream>
using std::cerr;
using std::endl;


namespace LightningDev
{
  CombatUnitId::CombatUnitId(unsigned long int newPlayerId, unsigned long int newObjectId)
      :playerId(newPlayerId),
       objId(newObjectId)
  {}
  
  
  CombatUnitId::CombatUnitId(const CombatUnitId& toCopy)
      :playerId(toCopy.playerId),
       objId(toCopy.objId)
  {}
  
  
  
  CombatUnitId::CombatUnitId(xmlNodePtr inNode)
  {
    for (xmlNodePtr curNode = inNode->children; curNode != 0; curNode = curNode->next)
      {
	if ( strcmp(getAttributeName(curNode), "playerId") == 0 )
	  {
	    playerId = getULIntAttributeValue(curNode);
	  }
	if ( strcmp(getAttributeName(curNode), "objId") == 0 )
	  {
	    objId = getULIntAttributeValue(curNode);
	  }
      }
  }
  
  
  void
  CombatUnitId::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "CombatUnitId", retStream);
    getULIntAttributeElement(baseIndent+1, "playerId", playerId, retStream);
    getULIntAttributeElement(baseIndent+1, "objId", objId, retStream);
    getEndObjectElement(baseIndent, retStream);
  }
  
  
  unsigned long int 
  CombatUnitId::getPlayerId()
  {
    return playerId;
  }
  
  
  unsigned long int 
  CombatUnitId::getObjectId()
  {
    return objId;
  }
  
  
  
  bool 
  operator==(const CombatUnitId& a, const CombatUnitId&b)
  {
    return (a.playerId == b.playerId) && (a.objId == b.objId);
  }
  

  bool 
  operator!=(const CombatUnitId& a, const CombatUnitId&b)
  {
    return !(a == b);
  }

}
