/* -*-c++-*- */
#ifndef LD_NETWORKGML_H
#define LD_NETWORKGML_H 1

#include "dllEntry.h"
#include "Network.h"


extern long int net_mIdent;
extern string net_contents;
extern std::string net_contents;

namespace LightningDev
{
   extern Network network;
}
extern "C"
{
  /**
   * Move a message off the queue and into a buffer space for
   * further manipulation and fetching.
   *
   * @return -1 if no new messages, otherwise the mIdent of the message retrieved.
   */
  DLLIMPORT float getMessage();

  /**
   * Returns the integer value of messageIdent for the last retrieved
   * message.
   *
   * @return float typecase from an unsigned int for the message ident.
   */
  DLLIMPORT float getMessageIdent();

  /**
   * Returns the contents of the last message as a float.  If this
   * messageIdent is not a numeric type it returns -5555.5555.
   *
   * @return float version of the converted message contents, or -5555.555 if the message ident is not numeric.
   */
  DLLIMPORT float getMessageContentsNumber();

  /**
   * Returns a pointer to the last message's contents as a c string.  This string is guarunteed to be a valid null
   * terminated string.  Though it may be an empty string.
   *
   * @return char* to the c_str contents of this message.  It is guarunteed to be a null terminated string, though it may be empty.
   */
  DLLIMPORT const char* getMessageContentsChar();
}


#endif /* LD_NETWORKGML_H */
