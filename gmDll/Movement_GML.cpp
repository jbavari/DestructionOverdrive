#include "Movement_GML.h"
#include "dllEntry.h"

extern "C"
{
  DLLIMPORT char* 
  kup()
  {
    LightningDev::movement.kup();
    return 0;
  }

  DLLIMPORT char* 
  kdown()
  {
    LightningDev::movement.kdown();
    return 0;
  }

  DLLIMPORT char* 
  kleft()
  {
    LightningDev::movement.kleft();
    return 0;
  }


  DLLIMPORT char* 
  kright()
  {
    LightningDev::movement.kright();
    return 0;
  }

  DLLIMPORT char* 
  incThrust()
  {
    LightningDev::movement.incThrust();
    return 0;
  }

  DLLIMPORT char* 
  decThrust()
  {
    LightningDev::movement.decThrust();
    return 0;
  }
}
