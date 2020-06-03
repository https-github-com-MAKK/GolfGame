/*GolfGameTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Abstract trigger box that calls a method when a specific actor
 *begins or stops overlapping this trigger box
 */

#include "GolfGameTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AGolfGameTriggerBox::AGolfGameTriggerBox()
{
    OnActorBeginOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapEnd);
}

void AGolfGameTriggerBox::BeginPlay()
{
    Super::BeginPlay();
	/*      debug box for in-game testing
    if (ShowDrawDebugBox == true)
    {
        DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
    }
   */
}


void AGolfGameTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
        OverlapBeginAction();
        UE_LOG(LogTemp, Log, TEXT("Triggerbox overlap begin"));
    }
}

void AGolfGameTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
        OverlapEndAction();
        UE_LOG(LogTemp, Log, TEXT("Triggerbox overlap end"));
    }
}


