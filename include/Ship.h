#ifndef LD_SHIPDESIGN_H
#define LD_SHIPDESIGN_H 1

#include <vector>
#include <string>
#include "Module.h"
#include "DamageType.h"
#include "CombatUnit.h"
#include "XmlSerialization.h"

using namespace std;

namespace LightningDev
{

  enum ShipType 
    { 
      Scout, 
      Cruiser, 
      BattleCruiser, 
      Battleship,
      Dreadnought, 
      Carrier 
    };


  /**
   * This class abstracts a ship.  A ship is a highly customized game
   * unit under direct player control.
   */
  class Ship : public CombatUnit,
               virtual public XmlSerialization
  {
  private:
    /** Name of this ship */
    string name;

    /** ID of this ship.
        This along with ownerID makes the primary key for this database.
    */
    unsigned int shipID;

    /** ID of the player who owns this ship.
        This along with ownerID makes the primary key for this database.
    */
    unsigned int ownerId;

    /** Type of ship this is */
    ShipType shipType;

    /** Computed mass of this ship, must be greater than zero. */
    double mass;

    /** Number of weapon bays */
    unsigned int weaponBays;

    /** Stores weapon modules */
    vector<Module*> weapons;

    /** Number of reactor bays */
    unsigned int reactorBays;

    /** Stores the reactor modules */
    vector<Module*> reactors;

    /** number of thuster bays */
    unsigned int thrusterBays;

    /** Stores the thrusters */
    vector<Module*> thrusters;

    /** Number of High Capacity Bays */
    unsigned int highCapacityBays;

    /** Stores the high capacity modules */
    vector<Module*> highCapacities;

  public:
    /**
       Contructor that makes a blank ship.  This defaults to a scout ship.
    */
    Ship();

    /**
       Contructor that makes a ship of type ShipType.
       @param ShipType This is of enum type ShipType and should be set to what this ship should craeted as.
    */
    Ship( ShipType ShipType );

    /**
       Contructor that makes a ship with shipID and ownerID settings.  shipID and ownerID are used at the primary key.  This defaults to a scout ship.
       @param shipID This is a unsigned int used as half of the primary key.
       @param ownerID This is a unsigned int used as half of the primary key.
    */
    Ship( unsigned int shipId, unsigned int ownerId );

    /**
       This returns a constant string reference to the name given to
       this ship.  It is not valid after this is destroyed.
       @return string The name that was given to this setup.
    */
    const string& getName() const;

    /**
       This will set the name of this setup used for saving and loading this setup.
       @param SetupName This string will set the stored value for this ship setup.
    */
    void setName( string SetupName );

    /**
       Get the ID of this ship. This along with ownerID makes the primary key for this database.
       @return int Returns the ID of this ship.
    */
    unsigned int getShipID() const;

    /**
       Set the ID for this ship. This along with ownerID makes the primary key for this database.
       @param OwnerId This is a int that is from the handshake network link.
    */
    void setShipID( unsigned int shipId );

    /**
       Get the owner of the ship's in game ID. This along with shipID makes the primary key for this database.
       @return int Returns the internal int that is the ID of the owner of this ship.
    */
    unsigned int getOwner() const;

    /**
       Set the owner of the ship's in game ID. This along with shipID makes the primary key for this database.
       @param OwnerId This is a int that is from the handshake network link.
    */
    void setOwner( unsigned int OwnerId );

    /**
       Sets the type of ship the current ship is. Calling this function will reset the current
       ships modules and all other aspects of this ship.
       @param shipType_IN This is the type of ship to set this class to.
    */
    void setShipType( const ShipType ShipType );

    /**
       Returns the mass of the ship.
       @return double The mass of the ship is returned.
    */
    double getMass() const;



    /**
       This allows access to the vector that holds the weapons modules for this ship.
       @return vector<Module*> A vector of Module* that stores the weapons installed on this ship.
    */
    vector<Module*>::const_iterator getWeapons();

    /**
       This allows access to the vector that holds the reactor modules for this ship.
       @return vector<Module*> A vector of Module* that stores the reactors installed on this ship.
    */
    vector<Module*>::const_iterator getReactors();

    /**
       This allows access to the vector that holds the thrusters modules for this ship.
       @return vector<Module*> A vector of Module* that stores the thrusters installed on this ship.
    */
    vector<Module*>::const_iterator getThrusters();

    /**
       This allows access to the vector that holds the high capacity modules for this ship.
       @return vector<Module*> A vector of Module* that stores the high capacity modules that are installed.
    */
    vector<Module*>::const_iterator getHighCaps();

    /**
     * Adds a weapon to this ship.
     *
     * @param weapon const Weapon& to the weapon to add.
     * @throw InsufficientBaysException if there is not an appropriate bay available.
     */
    void addWeapon( const Module& weapon );


    /**
     * Adds a reactor to this ship.
     *
     * @param reactor const Weapon& to the weapon to add.
     * @throw InsufficientBaysException if there is not an appropriate bay available.
     */
    void addReactor( const Module& reactor );

    /**
     * Adds a thrustor to this ship.
     *
     * @param thrustor const Weapon& to the weapon to add.
     * @throw InsufficientBaysException if there is not an appropriate bay available.
     */
    void addThruster( const Module& thrustor );

    /**
     * Adds a HighCapacity module to this ship.
     *
     * @param highCapacity const Weapon& to the weapon to add.
     * @throw InsufficientBaysException if there is not an appropriate bay available.
     */
    void addHighCap( const Module& highCapacity );

    /**
        This test if this ship has the correct shipID and the ownerID.
       @param shipID This is a unsigned int used as half of the primary key.
       @param ownerID This is a unsigned int used as half of the primary key.
    */
    bool testShip( unsigned int shipId, unsigned int ownerId );
  };


}


#endif /* LD_SHIPDESIGN_H */
