/*GolfGameTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Abstract trigger box that calls a method when a specific actor
 *beigns or stops overlapping this triggerbox
 */

#include "GolfGameTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

//Intializes the methods to be called upon overlap begin and end

AGolfGameTriggerBox::AGolfGameTriggerBox()
{
    OnActorBeginOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapEnd);
}

//Event for when he game begins to play, draws the debug box if ShowDrawDebugBox is true
void AGolfGameTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    if (ShowDrawDebugBox == true)
    {
        DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
    }
   
}

/*Checks to see if the Actor beginning to overlap is the Actor referenced in ActorToCheck
*the function to call is handled in the subclass
 */
void AGolfGameTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
        OverlapBeginAction();
       GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));

    }
}

/*Checks to see if the Actor ending the overlap is the Actor referenced in ActorToCheck
*the function to call is handled in the subclass
 */
void AGolfGameTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
       OverlapEndAction();
    	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
    }
}


