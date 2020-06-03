/*MusicChangeTriggerBox.cpp
 *Author: Andrew Sales
 *Description: Changes current music cue in the player's audio component for music and player new music cue
 */


#include "MusicChangeTriggerBox.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


AMusicChangeTriggerBox::AMusicChangeTriggerBox()
{

}

void AMusicChangeTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}


void AMusicChangeTriggerBox::OverlapBeginAction()
{
	if(Music != nullptr && PlayerForAudio != nullptr && !MusicStarted)
	{
		PlayerForAudio->ChangeMusicCue(Music);
		MusicStarted = true;
	}
}

void AMusicChangeTriggerBox::OverlapEndAction()
{
	
}
