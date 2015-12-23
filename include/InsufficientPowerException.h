/* -*-c++-*- */
#ifndef LD_INSUFFICIENTPOWEREXCEPTION_H
#define LD_INSUFFICIENTPOWEREXCEPTION_H 1

#include "LDException.h"

namespace LightningDev
{
  /**
   * Thrown when there is insufficient power to perform an action.
   */
  class InsufficientPowerException : virtual LDException
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
    InsufficientPowerException(const char* newMessage="OutOfDomainException") :LDException(newMessage){};
  };
}

#endif /* LD_INSUFFICIENTPOWEREXCEPTION_H */
