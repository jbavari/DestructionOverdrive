/* -*-c++-*- */
#ifndef LD_FIGHTERBAY_H
#define LD_FIGHTERBAY_H 1

#include "PassiveModule.h"
#include "Fighter.h"
#include <vector>

namespace LightningDev
{
  /**
   * Represents a fighter bay module.  Fighter bays launch and coordinate
   * unmanned fighters.
   */
  class FighterBay : public PassiveModule,
		     public Launcher
  {
  private:
    /** Number of fighters which are fired at once */
    usigned int launchSetSize;
  public:
    /** Launches a single SET of fighters */
    void fire();
  };
};

#endif /* LD_FIGHTERBAY_H */
