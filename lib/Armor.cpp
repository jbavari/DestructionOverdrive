#include <iostream>
#include "Armor.h"

using namespace LightningDev;

using namespace std;

Armor::Armor(const Power& newPowerSupplied, const Power& newUpkeep,
                const Power& newSuggestedUpkeep, const Power& newMaxUpkeep,
                const char* newName, float coveragePercent, const Damage newStrength)
                :Module(newPowerSupplied, newUpkeep, newSuggestedUpkeep, newMaxUpkeep,
                 newName), strength(newStrength)
{
  coverage=coveragePercent;
}

Armor::Armor(const Armor& toCopy):Module(toCopy), strength(toCopy.strength)
{
  coverage = toCopy.coverage;
}

float Armor::getCoverage() const
{
  return coverage;
}

const Damage& Armor::getDamage() const
{
  return strength;
}

const xmlChar* Armor::getXml(unsigned int baseIndent) const
{
  static ostringstream retStream;
  retStream.str("");   
  getXml(baseIndent, retStream);
  return (const xmlChar*)retStream.str().c_str();
}


void Armor::getXml(unsigned int baseIndent, ostream& retStream) const
{
  getStartObjectElement(baseIndent, "Armor", retStream);
  getStartParentsElement(baseIndent+1, retStream);
  Module::getXml(baseIndent+2, retStream);
  getEndParentsElement(baseIndent+1, retStream);
  getFloatAttributeElement(baseIndent+1, "coverage", coverage, retStream);
  getObjAttributeElement(baseIndent+1, "strength", "Damage", strength, retStream);
  getEndObjectElement(baseIndent, retStream);
}

Armor::Armor(xmlNodePtr inNode):Module(getParentsObjectNode(inNode, "Module")), 
                        coverage(getFloatAttributeValueByName(inNode, "coverage")),
                        strength(getObjectAttributeObject(inNode, "strength"))
{ }
