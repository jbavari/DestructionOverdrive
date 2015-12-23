/* -*-c++-*- */
#ifndef LD_DUMBMOVEMENT_H
#define LD_DUMBMOVEMENT_H 1

#include "Movement.h"

namespace LightningDev
{
  class DumbMovement : public Movement
    {
    private:
    public:
      DumbMovement(Network& newNetwork);
      void kup();
      void kdown();
      void kleft();
      void kright();
      void incThrust();
      void decThrust();
      //      void warp(WarpDrive& warpDriveUsed);
    };
} /* end namespace LightningDev */

#endif /* LD_DUMBMOVEMENT_H */
