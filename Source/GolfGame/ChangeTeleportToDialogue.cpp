/*ChangeTeleportToDialogue.cpp
 *Author: Andrew Sales
 *Description: Loads in new dialogue cue for when the player cannot teleport to the ball.
 */

#include "ChangeTeleportToDialogue.h"


void AChangeTeleportToDialogue::OverlapBeginAction()
{
   if(Player != nullptr && Dialogue != nullptr)
   {
       Player->NeedToTeleportBallCue = Dialogue;
   }
    
}

void AChangeTeleportToDialogue::OverlapEndAction()
{
    
}