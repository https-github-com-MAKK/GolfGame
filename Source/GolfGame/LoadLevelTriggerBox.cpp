/*LoadLevelTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Abstract trigger box that loads the designated next level
 *when overlapped by the referenced ActorToCheck.
 */

#include "LoadLevelTriggerBox.h"
#include "Kismet/GameplayStatics.h"

void ALoadLevelTriggerBox::LevelLoad() {
    UGameplayStatics::OpenLevel(this, LevelToLoad);
}

void ALoadLevelTriggerBox::OverlapBeginAction()
{
    IsCharacterInTrigger = true;
}

void ALoadLevelTriggerBox::OverlapEndAction()
{
	
}