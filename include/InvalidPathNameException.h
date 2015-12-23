/* Josh Bavari
   InvalidPathNameException.h
*/

#ifndef LD_INSUFFICIENTPOWEREXCEPTION_H
#define LD_INSUFFICIENTPOWEREXCEPTION_H 1
#include "LDException.h"

namespace LightningDev
{
          /** Thrown when FileSystem tries to save or load games or modules
            * where pathname contained invalid characters.
            */
          class InvalidPathNameException : public LDException
          {
                public:
                InvalidPathNameException( const char* message ) : LDException(message) {}
          };
          
}

#endif // LD_INSUFFICIENTPOWEREXCEPTION_H
