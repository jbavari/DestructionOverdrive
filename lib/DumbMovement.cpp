#include "DumbMovement.h"


namespace LightningDev
{ 
  DumbMovement::DumbMovement(Network& newNetwork)
      :Movement(newNetwork)
  {}
  

  void 
  DumbMovement::kup()
  {
    network.sendMessageAll(new Message(network.getPlayerId(), 16, "-10" ));
  }
  
  void 
  DumbMovement::kdown()
  {
    network.sendMessageAll(new Message(network.getPlayerId(), 16, "10" ));
  }
  
  void 
  DumbMovement::kleft()
  {
    network.sendMessageAll(new Message(network.getPlayerId(), 15, "-10" ));
  }
  
  void 
  DumbMovement::kright()
  {
    network.sendMessageAll(new Message(network.getPlayerId(), 15, "10" ));
  }
  

  void 
  DumbMovement::incThrust()
  {
  }
  
  void 
  DumbMovement::decThrust()
  {
  }
  
//   void 
//   DumbMovement::warp(WarpDrive& warpDriveUsed)
//   {
//     /* Dumb Movement doesn't know about a warp drive */
//   }
  
} /* end namespace LightningDev */


