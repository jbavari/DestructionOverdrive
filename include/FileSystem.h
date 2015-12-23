#ifndef LD_FILE_H
#define LD_FILE_H 1

#include <string>
#include <fstream>
#include <boost/signals.hpp>
#include "InvalidPathNameException.h"
#include "WriteFileException.h"
#include "LoadFileException.h"
#include "Module.h"

namespace LightningDev
{
          /** This class encloses the operations needed to load or save game 
            * states. It uses the Module class. It contains the
            * methods saveGame, loadGame, saveModule, and loadModule. This class
            * can throw InvalidPathNameException.
            */ 
          class FileSystem 
          {                        
                public:
                /** Default constructor, does nothing. */
                FileSystem();
                       
                /** saveGame writes to a file to the given pathname.
                  * @return bool returns true if the game is successfully saved.
                  * @param gameSaveName string the full pathname to save the 
                  * current game.
                  * @throws InvalidPathNameException in the event pathname is 
                  * invalid.
                  * @throws WriteFileException in the event that the method
                  * failed to write to the disk.
                  */
                void saveGame( std::string gameSaveName);
                                
                /** loadGame loads a game from the given pathname specified.
                  * @return bool returns true if the given file is successfully 
                  * loaded.
                  * @param gameLoadName string contains the pathname of the game 
                  * state file.
                  * @throws InvalidPathNameException in the event pathname is 
                  * invalid.
                  * @throws LoadFileException in the event that the file doesn't 
                  * exist.
                  */
                void loadGame( std::string gameLoadName );
                
                /** saveModule saves the module file to the disk with the given
                  * pathname.
                  * @return bool returns true if the module is successfully saved.
                  * @param moduleSaveName string contains the pathname to store 
                  * the given module.
                  * @param saveModule Module is the module that contains all the information
                  * about the module.
                  * @throws InvalidPathNameException in the event pathname is 
                  * invalid.
                  * @throws WriteFileException in the event that the method could
                  * not write to the disk.
                  */
                void saveModule( std::string moduleSaveName, Module saveModule );
                
                /** loadModule loads the module file from the disk that is stored 
                  * at the given moduleLoadName. 
                  * @return bool returns true if the module is successfully loaded.
                  * @param moduleLoadName string contains the pathname to the 
                  * module file.
                  * @throws InvalidPathNameException in the event pathname is 
                  * invalid.
                  * @throws LoadFileException in the event that the file doesn't
                  * exist.
                  */
                void loadModule( std::string moduleLoadName );
          };
}
#endif
