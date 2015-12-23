#include <string.h>
#include "LDException.h"

namespace LightningDev
{
  LDException::LDException(const char* newMessage)
  {
    strncpy(message, newMessage, sizeof(message)-1);
  }
  
  const char* LDException::what() const throw()
  {
    return message;
  }
}
