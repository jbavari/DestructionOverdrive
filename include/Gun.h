/* -*-c++-*- */

#ifndef LD_GUN_H
#define LD_GUN_H 1

#include "PassiveModule.h"
#include "Launcher.h"
#include "Fireable.h"
#include "Weapon.h"

namespace LightningDev
{
  
  /**
   * A gun fires a slug at a target.  If the slug hits, it deals
   * damage.  Slugs come in different types.
   */
  class Gun : public PassiveModule,
	      public Launcher
  {
  private:
  public:
  };
  
};
#endif /* LD_GUN_H */
