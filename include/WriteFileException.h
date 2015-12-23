/* Josh Bavari
   WriteFileException
*/

#ifndef LD_WRITEFILEEXCEPTION_H
#define LD_WRITEFILEEXCEPTION_H 1
#include "LDException.h"
#include <string>

namespace LightningDev
{
          /** Thrown when there is an error writing a file to the disk. */
          class WriteFileException : public LDException
          {
                public:
                WriteFileException( const char* message ) : LDException(message) {}
          };
}

#endif // LD_WRITEFILEEXCEPTION_H
