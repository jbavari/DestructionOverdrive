#include "Network.h"
#include <iostream>
using std::cerr;
using std::endl;


namespace LightningDev
{  
  Network::Network()
      :playerId(0)
  {
  }
  

  void
  Network::sendMessage(unsigned long int destPlayerId, Message* newMessage)
  {
    if ( destPlayerId != 0 )
      {
	cerr << "SENDMESSAGE TO REMOTE HOST NOT IMPLEMENTED!" << endl;
	abort();
      }
    
    messageQueue.enq(newMessage);
  }
  


  void
  Network::sendMessageAll(Message* newMessage)
  {
    messageQueue.enq(newMessage);
  }


  Message* 
  Network::getMessage()
  {
    return messageQueue.deq();
  }
  
  long unsigned int
  Network::getPlayerId()
  {
    return playerId;
  }
  
} /* end namespace LightningDev */
