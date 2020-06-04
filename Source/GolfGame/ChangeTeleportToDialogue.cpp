/*ChangeTeleportToDialogue.cpp
 *Author: Andrew Sales
 *Revision: 1(05/28/2020)
 *Revision: 2 (06/31/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Added code to OverlapBeginAction() to check if Player is null
 *Description: Loads in new dialogue cue for when the player cannot teleport to the ball.
 */

#include "ChangeTeleportToDialogue.h"
#include "GolfGameCharacter.h"

void AChangeTeleportToDialogue::OverlapBeginAction()
{
	AGolfGameCharacter* Player = dynamic_cast<AGolfGameCharacter*>(ActorToCheck);
    if (Player != NULL) {
        Player->NeedToTeleportBallCue = Dialogue;
    }   
}

void AChangeTeleportToDialogue::OverlapEndAction()
{
    
}