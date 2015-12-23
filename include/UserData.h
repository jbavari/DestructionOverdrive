/* -*-c++-*- */
#ifndef LD_USERDATA_H
#define LD_USERDATA_H 1

#include <vector>
#include <string>
#include "Ship.h"

using namespace std;

namespace LightningDev
{
  /**
     This is the base user class.  This class will be used for each user that
     logs into the game holding their IP and other useful information.
  */
  class UserData : virtual public XmlSerialization
  {
  private:
    string name;
    string factionName;
    int ID;
    string IP;  // Keep in format: xxx.xxx.xxx.xxx

    /*   Make this the key that the user will see to load a ship from a saved file of ships for this user.
         This maybe moved to some other place or expanded here.
     */
    vector<string> ShipSetupNames;

    Ship *ship;
    double cash;

  public:
    /**
       Make a new blank user.
    */
    UserData();
    /**
       Makes a new user with it's ID, from the networks handshake, set to an int.
       @param ID This is int is intended to be the ID the networks handshake has given to this user.
    */
    UserData( int Id );
    
    /**
       This will return the name saved with this user.
       @return string Returns the name saved for this user.
    */
    string getName();

    /**
       This will return the faction name saved with this user.
       @return string Returns the faction name saved for this user.
    */
    string getFactionName();

    /**
       This will return the ID saved with this user.  This ID should be unique and created by the networks handshake.
       @return int Returns the unique ID that was saved with this user.
    */
    int getID();

    /**
       This function will return a string to represent the IP address of this user.
       @return string This is the IP that has been saved with this user.
    */
    string getIP();

    /**
       This will return a vector of strings holding file locations for each saved ship this user has saved.
       @return vector<string> A vector of file locations as strings.
    */
    vector<string> getSavedSetups();

    /**
       This will return a pointer to the ship this user is currently flying or setting up.
       @return SBaseShip* This is a pointer to a class in ShipDesign.h that is the current setup this user is flying or editing.
    */
    Ship* getCurrentShip();

    /**
       This will return the amount of cash this user currently has.
       @return double The amount of cash this user currently has.
    */
    double getCash();

    /**
       This is used to set the name of this user.
       @param Name This will set the name of this user.
    */
    void setName( string Name );

    /**
       This is used to set the faction name of this user.
       @param FactionName This will set the name of this user.
    */
    void setFactionName( string FactionName );

    /**
       This is used to set the ID of this user.  This is 
       used as the primary key of this user and should only be set 
       once and never change.

       @param ID This is a unique ID created by the networks handshake.
    */
    void setID( int Id );

    /**
       This sets a string that is the IP of this user.
       @param IP This string will be used for setting the IP address of this.  This IP should be given from the networks handshake.
    */
    void setIP( string Ip );
    
    /**
       This will set the amount of cash this user has.
       @param Cash The amount of cash this user has.
    */
    void setCash( double Cash );
    
  };

};

#endif /* LD_USERDATA_H */
