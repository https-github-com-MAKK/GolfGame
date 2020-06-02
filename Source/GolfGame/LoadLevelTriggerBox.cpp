/*LoadLevelTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Trigger box that loads the designated next level when overlapped by the referenced ActorToCheck.
 */
#include "LoadLevelTriggerBox.h"
#include "Kismet/GameplayStatics.h"

//Loads the level specified by LevelToLoad
void ALoadLevelTriggerBox::LevelLoad() {
    UGameplayStatics::OpenLevel(this, LevelToLoad);
}

//Sets the delay time to load the level
void ALoadLevelTriggerBox::SetTimeDelay(float TimeDelay)
{
    if (TimeDelay >= 0)
    {
        LevelLoadTimeDelay = TimeDelay;
    }
}

//Gets the level load delay time
float ALoadLevelTriggerBox::GetTimeDelay()
{
    return LevelLoadTimeDelay;
}

/*When the ActorToCheck overlaps this trigger box, it sets IsCharacterInTrigger to true and loads the level
*designated level. 
*/
void ALoadLevelTriggerBox::OverlapBeginAction()
{
    IsCharacterInTrigger = true;
    if (IsNotBlueprint) {
        FPlatformProcess::Sleep(LevelLoadTimeDelay);
        UGameplayStatics::OpenLevel(this, LevelToLoad);
    }
}


void ALoadLevelTriggerBox::OverlapEndAction()
{
	
}