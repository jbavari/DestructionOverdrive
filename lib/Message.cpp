/* -*-c++-*- */
#include "Message.h"


namespace LightningDev
{
  Message::Message(long unsigned int inSenderPid, long unsigned int inMIdent, 
		   const string& inContents)
      :senderPid(inSenderPid),
       mIdent(inMIdent),
       contents(inContents),
       combUnitId(0,0)
  {}
  
  
  Message::Message(const Message& toCopy)
      :senderPid(toCopy.senderPid),
       mIdent(toCopy.mIdent),
       contents(toCopy.contents),
       combUnitId(toCopy.combUnitId)
  {}


  Message::Message(long unsigned int inSenderPid, long unsigned int  inMIdent, 
		   const string&     inContents,  const CombatUnitId newCombUnitId)
      :senderPid(inSenderPid),
       mIdent(inMIdent),
       contents(inContents),
       combUnitId(newCombUnitId)
  {}
  
  unsigned long int 
  Message::getSenderPid() const
  {
    return senderPid;
  }
  
  
  unsigned long int 
  Message::getMIdent() const
  {
    return mIdent;
  }
  

  const string& 
  Message::getContents() const
  {
    return contents;
  }


  const CombatUnitId& 
  Message::getCombUnitId() const
  {
    return combUnitId;
  }


  bool operator>(const Message& a, const Message& b)
  {
    if ( a.mIdent > b.mIdent )
      {
	return true;
      }
    else if ( a.mIdent == b.mIdent && a.senderPid > b.senderPid )
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool operator<(const Message& a, const Message& b)
  {
    if ( a.mIdent < b.mIdent )
      {
	return true;
      }
    else if ( a.mIdent == b.mIdent && a.senderPid < b.senderPid )
      {
	return true;
      }
    else
      {
	return false;
      }
  }

  bool operator==(const Message& a, const Message &b)
  {
    if ( a.mIdent >= Message::START_NONCOMBATUNIT_MESSAGES )
      {
	return (a.senderPid == b.senderPid) && (a.mIdent == b.mIdent);
      }
    else
      {
	return (a.senderPid == b.senderPid) && (a.mIdent == b.mIdent) && (a.combUnitId == b.combUnitId);
      }
  }

  bool operator!=(const Message& a, const Message &b)
  {
    return !(a == b);
  }
}
