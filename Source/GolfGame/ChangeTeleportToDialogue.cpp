/*ChangeTeleportToDialogue.cpp
 *Author: Andrew Sales
 *Description: Loads in new dialogue cue for when the player cannot teleport to the ball.
 */

#include "ChangeTeleportToDialogue.h"
#include "GolfGameCharacter.h"

void AChangeTeleportToDialogue::OverlapBeginAction()
{
   
	AGolfGameCharacter* Player = dynamic_cast<AGolfGameCharacter*>(ActorToCheck);
    Player->NeedToTeleportBallCue = Dialogue;
    
}

void AChangeTeleportToDialogue::OverlapEndAction()
{
    
}