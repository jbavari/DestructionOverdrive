/* -*-c++-*- */
#ifndef LD_XMLSERIALIZATIONEXCEPTION_H
#define LD_XMLSERIALIZATIONEXCEPTION_H 1

#include "LDException.h"

namespace LightningDev
{
  /**
   * Exception thrown when a parameter is out of it's specified domain,
   * but still allowed by the domain of it's implementation type.  This is actually
   * an error, but one we're explicitly allowing for time considerations.
   */
  class XmlSerializationException : public LDException
  {
  public:
    /**
     * Primary constructor.
     *
     * Copies newMessage into message, truncating if necessary to prevent
     * overflow of the array.
     *
     * @param message const char* to a message to be delivered.
     */
    XmlSerializationException(const char* newMessage="XmlSerializationException") :LDException(newMessage){};
  };
}

#endif /* LD_XMLSERIALIZATIONEXCEPTION_H */
