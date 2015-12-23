#include "UserData.h"

namespace LightningDev
{
    UserData::UserData()
    {
      name = "";
      ID = 0;
      IP = "255.255.255.255";
      ShipSetupNames.clear();
      ship = NULL;
      cash = 0.0;
    }

    UserData::UserData( int Id )
    {
      name = "";
      ID = Id;
      IP = "255.255.255.255";
      ShipSetupNames.clear();
      ship = NULL;
      cash = 0.0;

    }

    string UserData::getName()
    {
        return name;
    }

    string UserData::getFactionName()
    {
        return factionName;
    }

    int UserData::getID()
    {
        return ID;
    }

    string UserData::getIP()
    {
        return IP;
    }

    vector<string> UserData::getSavedSetups()
    {
        return ShipSetupNames;
    }

    Ship* UserData::getCurrentShip()
    {
        return ship;
    }

    double UserData::getCash()
    {
        return cash;
    }

    void UserData::setName( string Name )
    {
        name = Name;
    }

    void UserData::setFactionName( string FactionName )
    {
        factionName = FactionName;
    }

    void UserData::setID( int Id )
    {
        ID = Id;
    }

    void UserData::setIP( string Ip )
    {
        IP = Ip;
    }

    void UserData::setCash( double Cash )
    {
        cash = Cash;
    }
};
