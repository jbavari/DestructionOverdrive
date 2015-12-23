/* Replace "dll.h" with the name of your header */
#include "dllEntry.h"
#include <windows.h>
#include "Network.h"
#include "DumbMovement.h"

namespace LightningDev
{
  Network network;
  DumbMovement movement(network);
}

/**
 * Stuff for the network code.
 */
unsigned int net_mIdent;
std::string net_contents;

BOOL APIENTRY DllMain (HINSTANCE hInst     /* Library instance handle. */ ,
                       DWORD reason        /* Reason this function is being called. */ ,
                       LPVOID reserved     /* Not used. */ )
{
    switch (reason)
    {
      case DLL_PROCESS_ATTACH:
        break;

      case DLL_PROCESS_DETACH:
        break;

      case DLL_THREAD_ATTACH:
        break;

      case DLL_THREAD_DETACH:
        break;
    }

    /* Returns TRUE on success, FALSE on failure */
    return TRUE;
}
