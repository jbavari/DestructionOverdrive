/* -*-c++-*- */
#ifndef LD_COMBATUNITID_H
#define LD_COMBATUNITID_H 1

#include "XmlSerialization.h"


namespace LightningDev
{
  /**
   * This is an immutable class used to uniquely identify a
   * CombatUnit in combat.  The ID is guarunteed to be globally
   * unique in the cluster.
   *
   * As this is in an agregation relationship with CombatUnit
   * it must implement XmlSerialization.
   */
  class CombatUnitId : virtual public XmlSerialization
    {
    private:
      /**
       * The playerId of the owning player.  This is
       * NOT the players name.  And does not identify
       * the player between combat sessions.
       */
      unsigned long int playerId;

      /**
       * This is the objectId.  Each combat task tracks the
       * last objectId it assigned, this may be duplicated
       * between tasks.
       */
      unsigned long int objId;

      friend bool operator==(const CombatUnitId& a, const CombatUnitId& b);
      friend bool operator!=(const CombatUnitId& a, const CombatUnitId& b);


    public:
      
      CombatUnitId(unsigned long int newPlayerId, unsigned long int newObjectId);

      /**
       * Copy Constructor.
       *
       * @param toCopy const CombatUnitId& to the CombatUnitId instance to copy from.
       */
      CombatUnitId(const CombatUnitId& toCopy);

      /**
       * XmlSerialization constructor.
       * Constructs a combat unit from inNode, which must
       * point at a CombatUnitId object element.
       *
       * @param inNode xmlNodePtr to a CombatUnitId element.
       */

      CombatUnitId(xmlNodePtr inNode);
      /**
       * From XmlSerialization.
       */
      void getXml(unsigned int baseIndent, ostream& retStream) const;
      unsigned long int getPlayerId();
      unsigned long int getObjectId();
    };
  
  /**
   * CombatUnitId's are equivilant if objId and
   * playerId are equivilant.
   *
   * @param a const CombatUnitId& to the left operand.
   * @param b const CombatUnitId& to the right operand.
   * @return bool true iff a.playerId == b.playerId && a.objId == b.objId.
   */
  bool operator==(const CombatUnitId& a, const CombatUnitId& b);


  /**
   * CombatUnitId's are equivilant if objId and
   * playerId are equivilant.
   *
   * @param a const CombatUnitId& to the left operand.
   * @param b const CombatUnitId& to the right operand.
   * @return bool !(a == b).
   */
  bool operator!=(const CombatUnitId& a, const CombatUnitId& b);

} /* end namespace LightningDev */




#endif /* LD_COMBATUNITID_H */
