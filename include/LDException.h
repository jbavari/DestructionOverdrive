/* -*-c++-*- */
#ifndef LD_LDEXCEPTION_H
#define LD_LDEXCEPTION_H 1

#include <exception>

namespace LightningDev
{
  /**
   * Standard template for Exceptions used by LightningDev. It will provide a
   * constructor when you pass a string, it will copy the string to member variable
   * message. It will also display the message.
   */
  class LDException : virtual std::exception
  {
  private:
    /** Holds a copy of the message */
    char message[1024];
  public:
    /**
     * Primary constructor.
     *
     * Copies newMessage into message, truncating if necessary to prevent
     * overflow of the array.
     *
     * @param message const char* to a message to be delivered.
     */
    LDException(const char* newMessage="LDException");

    /**
     * Returns a pointer to an intellegable message for the 
     * cause of the exception.
     *
     * @return const char* to a meangingful message which caused the exception.
     */
    const char* what() const throw();
  };
}

#endif /* LD_LDEXCEPTION_H */
