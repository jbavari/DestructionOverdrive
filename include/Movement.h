/* -*-c++-*- */
#ifndef LD_MOVEMENT_H
#define LD_MOVEMENT_H 1
#include "Network.h"
#include "WarpDrive.h"
namespace LightningDev
{
  /**
   * Abstracts the movement of the ship.  Any keys are not
   * thouse the user presses, but the key names in the context of
   * this library.
   */
  class Movement
    {
    protected:
      Network& network;
    public:
      Movement(Network& theNetwork):network(theNetwork){};

      virtual ~Movement(){};
      
      /**
       * Causes the ship to react as if the up key had been pressed.
       */
      virtual void kup() = 0;
      /**
       * Causes the ship to react as if the down key had been pressed.
       */
      virtual void kdown() = 0;
      /**
       * Causes the ship to react as if the left key had been pressed.
       */
      virtual void kleft() = 0;
      /**
       * Causes the ship to react as if the right key had been pressed.
       */
      virtual void kright() = 0;
      /**
       * Causes the ship to react as if the increase thrust key had been pressed.
       */
      virtual void incThrust() = 0;
      /**
       * Causes the ship to react as if the reduce thrust key had been pressed.
       */
      virtual void decThrust() = 0;
      /**
       * Causes the ship to react as if the warp drive had been fired.
       */
      //virtual void warp(WarpDrive& warpDriveUsed) = 0;
    };
} /* end namespace LightningDev */
#endif /* LD_MOVEMENT_H */
