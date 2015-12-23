/* -*-c++-*- */
#ifndef LD_LAUNCHER_H
#define LD_LAUNCHER_H 1

#include "Ammunition.h"
#include "Fireable.h"

namespace LightningDev
{
  /**
   * This should be the base class for anything that holds 'ammo' and fires ammo.
   */
  class Launcher : public Fireable,
		   public Weapon
  {
  private:
    /** Maximum number of ammoUnits this launcher may carry */
    const unsigned int capacity;

    /** Ammunition ownded by this */
    std::vector<Ammunition> owned;

    /** Ammunition in space, these should refer to the ammunition in owned  */
    std::vector<Ammunition&> inSpace;

    /** The number of ammunition items this launcher launches at once.
    unsigned int launchSetSize;
  public:
    /**
     * Loads the launcher with number of missileType missiles.  Missiles are in queue, so the
     * first loaded are the first fired.
     *
     * @param ammoType const Ammunition& instance of missile which is being loaded.
     * @param number unsigned int this is the number of missiles which will be loaded.
     * @throw OutOfDomainException if number exceeds capacity.
     */
    void load(const Ammunition& ammoType, unsigned int number);

    /**
     * Removes all ammunition from the launcher.
     */
    void unload();
    
    /**
     * Returns the capacity of this launcher.
     *
     * @return unsigned int capacity of this launcher.
     */
    unsigned int getCapacity();

    /**
     * Launches an item of ammuntion.  This creates a reference to
     * it in the inSpace vector.
     */
    void launch();

    /**
     * Destroys an item of ammunition.  This removes the ammunition from
     * owned and inSpace vectors.
     */
    void destroyAmmo(unsigned int offset);

    /**
     * Returns a reference to an item of ammunition.  offset is the
     * offset of the ammunition in the inSpace vector.
     */
    Ammunition& getAmmunition(unsigned int offset);

    /**
     * Returns the amount of ammunition available for launch.
     */
    unsigned int getAmmoAmount();

    /**
     * Returns the amount of ammunition inSpace.
     */
    unsigned int getAmmoInSpace();

    /**
     * Returns the number of amunition items this launcher launches at once.
     *
     * @return unsigned int the number of missiles this launcher launches at once.
     */
    unsigned int getLaunchSetSize() const;

  };
};

#endif /* LD_LAUNCHER_H */
