/*PlayOnceSoundTriggerBox.cpp
 *Author: Andrew Sales
 *Description: Played a specific audio cue at the located specific one time when entering trigger box.
 *The sound cannot be played again.
 */


#include "PlayOnceSoundTriggerBox.h"
#include "Kismet/GameplayStatics.h"

void APlayOnceSoundTriggerBox::OverlapBeginAction()
{
	if (Sound != nullptr && !HasSoundPlayed)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sound, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
		HasSoundPlayed = true;
	}
}

void APlayOnceSoundTriggerBox::OverlapEndAction()
{

}