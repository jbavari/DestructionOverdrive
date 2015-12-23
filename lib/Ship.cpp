#include Ship.h

namespace LightningDev
{
    Ship::Ship()
    {
        name = "";
        shipID = 0;
        ownerId = 0;
        shipType = Scout;
        mass = 0;
        weaponBays = 0;
        weapons.clear();
        reactorBays = 0;
        reactors.clear();
        thrusterBays = 0;
        thrusters.clear();
        highCapacityBays = 0;
        highCapacities.clear();
    }

    Ship::Ship( ShipType ShipType )
    {
        name = "";
        shipID = 0;
        ownerId = 0;
        shipType = ShipType;

        // This switch needs to use the database and find out what each ships attributes should be.
        switch( shipType )
        {
          Scout:
            mass = 100;
            weaponBays = 3;
            reactorBays = 1;
            thrusterBays = 2;
            highCapacityBays = 2;
            break;
          Cruiser:
            mass = 1000;
            weaponBays = 5;
            reactorBays = 2;
            thrusterBays = 2;
            highCapacityBays = 3;
            break;
          BattleCruiser:
            mass = 10000;
            weaponBays = 7;
            reactorBays = 3;
            thrusterBays = 4;
            highCapacityBays = 4;
            break;
          Battleship:
            mass = 100000;
            weaponBays = 10;
            reactorBays = 2;
            thrusterBays = 4;
            highCapacityBays = 5;
            break;
          Dreadnought:
            mass = 1000000;
            weaponBays = 15;
            reactorBays = 3;
            thrusterBays = 4;
            highCapacityBays = 6;
            break;
          Carrier:
            mass = 1500000;
            weaponBays = 5;
            reactorBays = 3;
            thrusterBays = 4;
            highCapacityBays = 8;
            break;
          Default:
            mass = 0;
            weaponBays = 0;
            reactorBays = 0;
            thrusterBays = 0;
            highCapacityBays = 0;
            shipType = Scout;
            break;
        };

        weapons.clear();
        reactors.clear();
        thrusters.clear();
        highCapacities.clear();

    }


    Ship::Ship( unsigned int shipId, unsigned int ownerId )
    {
        name = "";
        shipID = shipId;
        ownerId = ownerId;
        shipType = Scout;
        mass = 0;
        weaponBays = 0;
        weapons.clear();
        reactorBays = 0;
        reactors.clear();
        thrusterBays = 0;
        thrusters.clear();
        highCapacityBays = 0;
        highCapacities.clear();
    }

    const string& Ship::getName() const
    {
        return name;
    }



    unsigned int Ship::getShipID()
    {
        return shipID;
    }

    void Ship::setShipID( unsigned int shipId )
    {
        shipID = shipId;
    }

    void Ship::setName( string SetupName )
    {
        name = SetupName;
    }

    unsigned int Ship::getOwner() const
    {
        return ownerId;
    }

    void Ship::setOwner( unsigned int OwnerId )
    {
        ownerId = OwnerId;
    }

    void Ship::setShipType( const ShipType ShipType )
    {
        shipType = ShipType;
    }

    double Ship::getMass() const
    {
        return mass;
    }

    vector<Weapon*>::const_iterator Ship::getWeapons()
    {
        return weapons;
    }

    vector<Reactor*>::const_iterator Ship::getReactors()
    {
        return reactors;
    }

    vector<Thrustor*>::const_iterator Ship::getThrusters()
    {
        return thrusters;
    }

    vector<HighCapacity*>::const_iterator Ship::getHighCaps()
    {
        return highCapacities;
    }

    void Ship::addWeapon( const Weapon& weapon )
    {
        // I'm not for sure what else can keep this module from not being able to be added to a ship.
        //    IE: Amount of power?
        if( weapons.size() < weaponBays )
            weapons.push_back( weapon );
    }


    void Ship::addReactor( const Reactor& reactor )
    {
        // I'm not for sure what else can keep this module from not being able to be added to a ship.
        //    IE: Amount of power?
        if( reactors.size() < reactorBays )
            reactors.push_back( reactor );
    }

    void Ship::addThruster( const Thrustor& thrustor )
    {
        // I'm not for sure what else can keep this module from not being able to be added to a ship.
        //    IE: Amount of power?
        if( thrusters.size() < thrusterBays )
            thrusters.push_back( thrustor );
    }

    void Ship::addHighCap( const HighCapacity& highCapacity )
    {
        // I'm not for sure what else can keep this module from not being able to be added to a ship.
        //    IE: Amount of power?
        if( highCapacityBays.size() < highCapacityBays )
            highCapacityBays.push_back( highCapacity );
    }

    bool Ship::testShip( unsigned int shipId, unsigned int ownerId )
    {
        if( shipID == shipId && ownerID == ownerId )
            return true;
        return false;
    }
};
