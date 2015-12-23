/* -*-c++-*- */
#ifndef LD_MOVEMENTGML_H
#define LD_MOVEMENTGML_H 1

#include "dllEntry.h"
#include "Movement.h"
#include "DumbMovement.h"

namespace LightningDev
{
  extern DumbMovement movement;
}

extern "C"
{
  /**
   * The up key was pressed.
   */
   DLLIMPORT char* kup();

  /**
   * The down key was pressed.
   */
  DLLIMPORT char* kdown();

  /**
   * The left key was pressed.
   */
  DLLIMPORT char* kleft();

  /**
   * The right key was pressed.
   */
  DLLIMPORT char* kright(); 

  /**
   * The incThrust key was pressed.
   */
  DLLIMPORT char* incThrust(); 


  /**
   * The decThrust key was pressed.
   */
  DLLIMPORT char*decThrust();
}

#endif /* LD_MOVEMENTGML_H */
