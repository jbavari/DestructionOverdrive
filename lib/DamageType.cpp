#include "DamageType.h"

namespace LightningDev
{

  DamageType::DamageType(float newKinetic)
      :kinetic(newKinetic)
  {
    if ( kinetic > 1.0 )
      {
	throw OutOfDomainException("newKinetic is greater than 1");
      }
    if ( kinetic < 0.0 )
      {
	throw OutOfDomainException("newKinetic is less than 0");
      }
    
  }
  
  DamageType::DamageType(const DamageType& toCopy)
      :kinetic(toCopy.kinetic)
  {}
  



  /**********************************************************
   *  XmlSerialziation Stuff                                *
   *********************************************************/
  
  DamageType::DamageType(xmlNodePtr inNode)
  {
    for ( xmlNodePtr curNode = inNode->children; curNode != 0; curNode=curNode->next )
      {
	if ( strcmp(getAttributeName(curNode), "kinetic") == 0 )
	  {
	    kinetic = getFloatAttributeValue(curNode);
	  }
      }
  }
  
  
  const xmlChar* 
  DamageType::getXml(unsigned int baseIndent) const
  {
    static ostringstream retStream;
    retStream.str("");

    getXml(baseIndent, retStream);

    return (xmlChar*)retStream.str().c_str();
  }
  
  void 
  DamageType::getXml(unsigned int baseIndent, ostream& retStream) const
  {
    getStartObjectElement(baseIndent, "DamageType", retStream);
    getFloatAttributeElement(baseIndent+1, "kinetic", kinetic, retStream);
    getEndObjectElement(baseIndent, retStream);
  }
  
  
  /**********************************************************
   *  Regular Stuff                                         *
   *********************************************************/
  
  


  float 
  DamageType::getKinetic() const
  {
    return kinetic;
  }
  
  
  float 
  DamageType::getRadiant() const
  {
    return 1.0 - kinetic;
  }
  
}
