/*PlatformGravityTriggerBox.cpp
 *Author: Andrew Sales
 *Description: Upon a specific actor overlapping the triggerbox, the world gravity is set to a specified new gravity.
 *The original gravity is then reset upon leaving the trigger box.
 */

#include "PlatformGravityTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "GameFramework/WorldSettings.h"

APlatformGravityTriggerBox::APlatformGravityTriggerBox()
{

}

void APlatformGravityTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	 OriginalWorldGravity = GetWorldSettings()->GetGravityZ();
}

void APlatformGravityTriggerBox::OverlapBeginAction() {


        //GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OverlappedActor->GetName()));

        GetWorldSettings()->bGlobalGravitySet = true;
        GetWorldSettings()->GlobalGravityZ = GravityInsideTriggerBox;

        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Current gravity = %f"), GetWorldSettings()->GetGravityZ()));

  
}

void APlatformGravityTriggerBox::OverlapEndAction() {

        GetWorldSettings()->bGlobalGravitySet = false;
        GetWorldSettings()->GlobalGravityZ = OriginalWorldGravity;

}