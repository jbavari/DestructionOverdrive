#include "UPQueue.h"
#include <iostream>
using std::cout;
using std::cerr;
using std::endl;


namespace LightningDev
{
  UPQueue::UPQueue()
  {}
  
      

  UPQueue::UPQueue(const UPQueue& toCopy)
  {
    for(vector<Message*>::const_iterator i = toCopy.data.begin();
	i != toCopy.data.end();
	i++)
      {
	data.push_back(new Message(**i));
      }
  }
  

  UPQueue::~UPQueue()
  {
    for(vector<Message*>::const_iterator i = data.begin();
	i != data.end();
	i++)
      {
	delete *i;
      }
  }


  Message* 
  UPQueue::deq()
  {
    if ( data.size() == 0 )
      {
	return 0;
      }

    Message* tmp = data[0];

    data.erase(data.begin());

    return tmp;
  }
  

  void 
  UPQueue::enq(const Message& newMessage)
  {
    enq(new Message(newMessage));
  }
  

  void 
  UPQueue::enq(Message* newMessage)
  {
    vector<Message*>::iterator i;


//     cerr<<"**************BeforeInsert***************"<<endl;
//     for(i = data.begin();
// 	i != data.end();
// 	i++)
//       {
// 	cerr <<"BIns: " << (*i)->getSenderPid() << " -- " << (*i)->getMIdent() <<endl;
//       }
//     cerr<<"**************END BEFORE INSERT**********"<<endl;
    
    /* Scan to the insertion point */
    /* Since this is a linear search on a sorted array, we
       may wish to change to a binary search later */
    for(i = data.begin();
	i != data.end() && (*newMessage) > (**i);
	i++);


    /* pointing at the element to follow newMessage */
    if ( newMessage->getMIdent() < Message::START_NONCOMBATUNIT_MESSAGES &&
	 i != data.end() &&
	 **i == *newMessage )
      {
	data.erase(i);
      }
    data.insert(i, newMessage);


//     cerr<<"**************AfterInsert***************"<<endl;
//     for(i = data.begin();
// 	i != data.end();
// 	i++)
//       {
// 	cerr <<"AIns: " << (*i)->getSenderPid() << " -- " << (*i)->getMIdent() <<endl;
//       }
//     cerr<<"**************END AFTER INSERT**********"<<endl;

  }
} /* namespace LightningDev */
