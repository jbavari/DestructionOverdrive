/* Josh Bavari
   FileSystem.cpp
   current as of 3:06 saturday 3rd.
*/

#ifndef LD_FILESYSTEM_CPP
#define LD_FILESYSTEM_CPP 1

#include "FileSystem.h"
#include <ctype.h>
#include <fstream>
#include <iostream>
using std::ifstream;
using std::ofstream;


namespace LightningDev
{
  FileSystem::FileSystem() { }
  
  void FileSystem::saveGame( std::string gameSaveName )
  {
       
         if ( gameSaveName == "" )
            throw InvalidPathNameException("Blank string given for save game path.");
         
  
         ofstream fileWriter( gameSaveName.c_str(), std::ios::out );
         
         // If the fileWriter has a problem, return false.
         if ( !fileWriter )
              throw WriteFileException("Error opening file for save game file in saveGame.");

         // Use signal to get the xml data to write, store in a string, write to disk.
         std::string fileContents = "....";  
         // Write to the file.
         fileWriter << fileContents;

         // Close the file.
         fileWriter.close(); 
  }
  
  void FileSystem::loadGame( std::string gameLoadName )          
  {
         if ( gameLoadName == "" )
            throw InvalidPathNameException("Blank string given for load game path.");
         
         ifstream fileReader( gameLoadName.c_str(), std::ios::in );
         if ( !fileReader )
            throw LoadFileException("Error opening the file in loadGame.");
         
         //Now give the xml to the classes as they come.
         
         fileReader.close();
         
  }
  
  void FileSystem::saveModule( std::string moduleSaveName, Module saveModule )
  {
       if ( moduleSaveName == "" )
          throw InvalidPathNameException("Blank string given for save module path.");
       
       ofstream fileWriter( moduleSaveName.c_str(), std::ios::out );
       
       if ( !fileWriter )
          throw WriteFileException("Error opening file for writing in saveModule.");
          
          // Now go get all the xml data from module from a signal and write to disk.
          std::string fileContents = "..";          
          fileWriter << fileContents;          


          fileWriter.close();
  }
  
  void FileSystem::loadModule( std::string moduleLoadName )
  {
       if ( moduleLoadName == "" )
          throw InvalidPathNameException("Blank string given for load module save path.");          
       
       ifstream fileReader( moduleLoadName.c_str(), std::ios::in );
       
       if ( !fileReader )
          throw LoadFileException("Error opening file for loading module in loadModule");
          
       // Now we get the xml for the module, and send it to the module instantion.

  }       


}

#endif /* LD_FILESYSTEM_CPP */
