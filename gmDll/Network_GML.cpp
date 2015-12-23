#include "Network_GML.h"
#include "dllEntry.h"

extern "C"
{
  DLLIMPORT float 
  getMessage()
  {
    LightningDev::Message* curMessage = LightningDev::network.getMessage();
    if ( curMessage == 0 )
      {
	/* The message queue is empty */
	net_mIdent = -1;
	net_contents = "";
      }
    else
      {
	net_contents = curMessage->getContents();
	net_mIdent = curMessage->getMIdent();
	delete curMessage;
      }

    return (float)net_mIdent;
  }

  DLLIMPORT float 
  getMessageIdent()
  {
    return (float)net_mIdent;
  }

  DLLIMPORT float 
  getMessageContentsNumber()
  {
    if(net_mIdent == 15 ||
       net_mIdent == 16)
      {
	char* tail = 0;
	float retVal;
	
	errno = 0;
	retVal = strtof(net_contents.c_str(), &tail);
	if ( errno !=0 )
	  {
	    std::cerr << "Problem with strtoul";
	    abort();
	  }
	return retVal;
      }
    else
      {
	return -5555.5555;
      }
  }

  DLLIMPORT const char*
  getMessageContentsChar()
  {
    return net_contents.c_str();
  }
}
