/*GolfGameTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1 (05/15/2020)
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


