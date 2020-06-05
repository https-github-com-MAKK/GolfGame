/*PlatformGravityTriggerBox.cpp
 *Author: Andrew Sales
 *Revision: 1 (03/14/2020)
 *Revision: 2 (05/15/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Pushed code up to super class
 *Description: Upon a specific actor overlapping the triggerbox, the world gravity is set to a specified new gravity.
 *The original gravity is then reset upon leaving the trigger box.
 */

#include "PlatformGravityTriggerBox.h"
#include "GameFramework/WorldSettings.h"

void APlatformGravityTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	OriginalWorldGravity = GetWorldSettings()->GetGravityZ();
    GravityInsideTriggerBox = -100.0;
}

void APlatformGravityTriggerBox::OverlapBeginAction()
{
    GetWorldSettings()->bGlobalGravitySet = true;
    GetWorldSettings()->GlobalGravityZ = GravityInsideTriggerBox; 
}

void APlatformGravityTriggerBox::OverlapEndAction()
{
    GetWorldSettings()->bGlobalGravitySet = false;
    GetWorldSettings()->GlobalGravityZ = OriginalWorldGravity;
}