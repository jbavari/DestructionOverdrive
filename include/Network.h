/* -*-c++-*- */
#ifndef LD_NETWORK_H
#define LD_NETWORK_H
#include "UPQueue.h"

namespace LightningDev
{
  /**
   * This class abstracts ALL IPC communication, and facilitates
   * communication between the DLL layer and the GML layer for the
   * more complicated functions.
   *
   * This class is NOT copyable.  So don't do it!
   */
  class Network
    {
    private:
      /**
       * Contains the messages in priority order defined by UPQueue and Message.
       */
      UPQueue messageQueue;


      /**
       * The playerId of THIS player.
       */
      unsigned long int playerId;

      /* 
       * This class is left incomplete.  Evenutally it will need a couple
       * of maps to get IP's to PlayerIds etc....
       */
    public:
      /**
       * Primary Constructor, this will go away soon, and be replaced
       * by one which accepts an IP address.
       */
      Network();

      /**
       * Sends a message.  The network class does the lookup between
       * PlayerID and PlayerIP.
       */
      void sendMessage(unsigned long int destPlayerId, Message* newMessage);



      /**
       * Sends a message.  The network class does the lookup between
       * PlayerID and PlayerIP.
       */
      void sendMessageAll(Message* newMessage);


      /**
       * Get the next message off the queue.  The returned Message* now belongs
       * to the calling code, which must delete() it appropriately.
       *
       * @return Message* to the message pulled off the UPQueue, must delete
       *                  this when done with it.
       */
      Message* getMessage();

      /**
       * Returns the Player with playerId's IP address as a string.
       *
       * @param inPlayerId long unsigned int of the player id we're interested in.
       * @return string copy of the IP address of the player we're interested in.
       */
      //string getIPByPlayerId(long unsigned int inPlayerId);

      /**
       * Returns the playerId of this player, or 0 if unconnected.
       */
      long unsigned int getPlayerId();
    };

} /* namespace LightningDev */

#endif
