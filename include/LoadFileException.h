/* Josh Bavari
   WriteFileException
*/

#ifndef LD_LOADFILEEXCEPTION_H
#define LD_LOADFILEEXCEPTION_H 1
#include "LDException.h"

namespace LightningDev
{
          /** Thrown when there is an error loading a file from the disk. */
          class LoadFileException : public LDException
          {
                public:
                       LoadFileException( const char* message ) : LDException(message) {}      
          };
}

#endif // LD_LOADFILEEXCEPTION_H
