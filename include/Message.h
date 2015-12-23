/* -*-c++-*- */
#ifndef LD_MESSAGE_H
#define LD_MESSAGE_H 1

#include <string>
using std::string;

#include "CombatUnitId.h"

namespace LightningDev
{
  /**
   * Message is the foundation class for a network transmission.
   * Conceptually it is the smallest unit of the doverdrive protocol.
   * It is immutable.
   */
  class Message
  {
  private:
    /** Player ID that sent the message */
    const long unsigned int senderPid;




    /** 
     * Integer identifier of the message.  These
     * are used instead of a string compare.
     *
     * 0 == Critical Message
     * 10 == Movement Message
     * 1000 == Player Chat Message
     *
     * Etcetera, the message idents are not described in this document, rather
     * they are defined in the protocol documentation.
     *
     */
    const long unsigned int mIdent;


    /** The contents of the message */
    const string contents;


    /**
     * The Combat Unit ID of the object this message contains.
     * If this is zero, the message does not contain a CombatUnit
     */
    const CombatUnitId combUnitId;


    friend bool operator>(const Message& a, const Message& b);
    friend bool operator<(const Message& a, const Message&b);
    friend bool operator==(const Message& a, const Message&b);
    friend bool operator!=(const Message& a, const Message&b);

  public:
    /** This is the lowest mIdent that can relate to a non-combat unit */
    static const long unsigned int START_NONCOMBATUNIT_MESSAGES = 5000;


    /**
     * Principal constructor for Combat Unit Messages.  All parameters
     * are copied.
     *
     * @param inSenderPid long int of the Player Id of the sender.
     * @param inMIdent lont int of the Message Ident number.
     * @param contents const char* to the contents of this message.  In many cases
     *        this will be an XML document fragment.
     * @param newCombUnitId the CombatUnitId this message relates to, it is copied.
     */
    Message(long unsigned int inSenderPid, long unsigned int inMIdent, const string& inContents,
	    const CombatUnitId newCombUnitId);
    

    /**
     * Principal constructor for non combat unit messages.  This should only
     * be used when the message does not relate to a combat unit, as the UPQueue
     * Does not EVER match duplicates of these messages.
     *
     * @param inSenderPid long int of the Player Id of the sender.
     * @param inMIdent lont int of the Message Ident number.
     * @param contents const char* to the contents of this message.  In many cases
     *        this will be an XML document fragment.
     */
    Message(long unsigned int inSenderPid, long unsigned int inMIdent, const string& inContents);

    /**
     * Copy Constructor
     *     
     * @param toCopy const Message& to the Message instance to copy.
     */
    Message(const Message& toCopy);

    /**
     * Returns the value of senderPid
     *
     * @return long int copy of senderPid.
     */
    unsigned long int getSenderPid() const;

    /**
     * Returns a copy of mIdent
     *
     * @return unsigned long int copy of mIdent.
     */
    unsigned long int getMIdent() const;

    /**
     * Returns a constant char* of contents.
     *
     * @return const char* to contents.
     */
    const string& getContents() const;

    
    /**
     * Returns a constant CombatUnitId& of combUnitId.
     *
     * @return const CombatUnitId& to combUnitId.
     */
    const CombatUnitId& getCombUnitId() const;
  };


  /**
   * Do NOT expect these to work the way you think they do.  Operator >
   * returns true iff if a.senderId is greater than b.senderId.
   *
   * Message is used principally by UPQueue and it
   * is in that context these rules make sence.
   *
   * @param a const Message& to the left operand.
   * @param b const Message& to the right operand.
   * @return bool true iff a.senderId > b.senderId.
   */
  bool operator>(const Message& a, const Message& b);


  /**
   * Do NOT expect these to work the way you think they do.  Operator >
   * returns true iff if a.senderId is less than b.senderId.
   *
   * Message is used principally by UPQueue and it
   * is in that context these rules make sence.
   *
   * @param a const Message& to the left operand.
   * @param b const Message& to the right operand.
   * @return bool true iff a.senderId < b.senderId.
   */
  bool operator<(const Message& a, const Message&b);


  /**
   * Do NOT expect these to work the way you think they do.  Operator==
   * 
   * If mIdent >= START_NONCOMBAT_UNIT_MESSAGES
   * Returns true iff if a.senderId is equal to b.senderId
   * AND a.mIdent is equal to b.mIdent AND 
   * a.combUnitId is equal to b.combUnitId.
   *
   * If mIdent < START_NONCOMBAT_UNIT_MESSAGES
   * Returns true iff if a.senderId is equal to b.senderId
   * AND a.mIdent is equal to b.mIdent
   *
   * Combat Unit is ignored in the second case.
   *
   * Message is used principally by UPQueue and it
   * is in that context these rules make sence.
   *
   * @param a const Message& to the left operand.
   * @param b const Message& to the right operand.
   * @return bool true iff a.senderId == b.senderId && a.mIdent == b.mIdent && 
                  if( mIdent >= START_NONCOMBAT_UNIT_MESSAGES){ a.combUnitId == b.combUnitId}.
   */
  bool operator==(const Message& a, const Message&b);

  /**
   * Read operator ==
   *
   * @return !(a == b)
   */
  bool operator!=(const Message& a, const Message&b);

}

#endif /* LD_MESSAGE_H */
