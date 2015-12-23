/* -*-c++-*- */
#ifndef LD_UPQUEUE_H
#define LD_UPQUEUE_H 1

#include <vector>
using std::vector;

#include "Message.h"
#include "CombatUnitId.h"
namespace LightningDev
{

  /**
   * This class is like a priority queue for Messages, except
   * it permits only one message of each 'key' value.  For this
   * queue, a 'key' value is the concatination of mIdent with senderPid.  
   * so if player 0 sends a message with ident 1, the
   * key is 10 (MESSAGE IDENT == 1, PLAYERID == 0).  The actual values will 
   * consume two machine words
   * however, so implementing comparison operators on Message may be useful.
   *
   * The principal purpose of this structure is to only update gamemaker with
   * the most recent version of a message per tick, rather than continuously update
   * DURING the tick until we reach the most recent version.
   *
   * Message Uniqueness is determined by the entire key, however message
   * ordering in the queue should only be based on mIdent, such that 
   * FIFO behavior can be expected when mIdents are the same.
   *
   * Some Notation.  The 'key' shall be denoted as mIdent-senderPid, so, with 
   * senderPid of 0, and mIdent of 1, we notate the key as 1-0-a, with a
   * being the time the message arrive (handled implictly by the UPQueue).  Simmilarly
   * with senderPid of 1, and mIdent of 1 we notate the key as 1-1-a.
   *
   * An EXAMPLE: the messages, 0-0-a, 0-1-b, 0-0-c, 0-0-d arrive in this order.
   * note that the letters on the end are only here for us to track the order of
   * arrival in text.
   *
   * Message 0-0-a is deleted by the arrival of 0-0-c, which is deleted by 0-0-d.  So
   * when the messages are removed from the queue, they come off in this order:
   * 0-1-b, 0-0-d
   *
   * Another EXAMPLE:  1-0-a, 1-1-b, 1-1-c, 0-1-a  is removed from the queue as
   * 0-1-a, 1-0-a, 1-1-c.  0 sorts first, and 1-1-b is deleted by the arrival of 1-1-c.
   *
   * Anoter EXAMPLE:  The messages 1-0-a, 1-0-b, 1-1-c, 0-1-d, 1-1-e, when dequeued the
   * order of removal is: 0-1-d, 1-0-b, 1-1-e.   0-1-e is first, because it's mIdent
   * is the smallest.
   */
  class UPQueue
    {
    private:
      vector<Message*> data;
    public:
      /**
       * Primary Constructor.
       */
      UPQueue();
      

      /**
       * Copy Constructor.
       *
       * This implements a 'deep' copy in which all the elements are also copied.
       * It's expensive so avoid it.
       *
       * @param toCopy const UPQueue& to the UPQueue to copy from.
       */
      UPQueue(const UPQueue& toCopy);


      /**
       * Destructor.
       */
      ~UPQueue();

      /**
       * Removes the top message from the Queue and returns it.  The
       * calling code takes ownership of the return and must delete() it.
       *
       * @return Message* to the relevant message which the caller MUST delete(), 0 if the queue is empty.
       */
      Message* deq();

      /**
       * Copies newMessage and inserts it into this UPQueue.  
       *
       * @param newMessage const Message& to the message to copy and insert.
       */
      void enq(const Message& newMessage);

      /**
       * Inserts newMessage into this UPQueue.  The calling code MUST NOT
       * further modify message, and is free to reuse any pointer which was
       * referring to the message.  newMessage is not copied and MUST have
       * been created with the new operator.
       *
       * @param newMessage Message* to a message created with the new operator which will be inserted into the queue.
       */
      void enq(Message* newMessage);
    };
}

#endif /* LD_UPQUEUE_H */
