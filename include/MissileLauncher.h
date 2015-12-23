/* -*-c++-*- */
#ifndef LD_MISSILELAUNCHER_H
#define LD_MISSILELAUNCHER_H 1

#include "PassiveModule.h"
#include "Missile.h"
#include "Launcher.h"
#include <vector>

namespace LightningDev
{

  /**
   * This class abstracts a missile launcher module.  Missile lanchers carry, fire
   * and control missiles.  A missile looses guidence if the missle launcher looses power
   * while a missle is in flight.
   */
  class MissileLauncher : public PassiveModule,
			  public Launcher
  {
  private:
  public:
    /**
     * Primary Constructor.
     *
     * @param accuracy float the accuracy of this missile launcher as a number between 0 and 1.
     * @param range unsigned int the range of this launcher
     * @param capacity unsigned int the maximum number of missiles this launcher may hold.
     * @throw OutOfDomainException if accuracy is below 0 or greater than 1.
     */
    MissileLauncher(float accuracy, unsigned int range, unsigned int capacity);

    /**
     * Copy Constructor.
     *
     * @param toCopy const MissileLauncher& to the MissileLauncher to copy.
     */
    MissileLauncher(const MissileLauncher& toCopy);


    /**
     * Causes the MissileLauncher to launch a single SET of  missiles.
     */
    void fire();
  };

};

#endif /* LD_MISSILELAUNCHER_H */
