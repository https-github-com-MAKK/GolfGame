// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AGoalTriggerBox::AGoalTriggerBox()
{
   
    OnActorBeginOverlap.AddDynamic(this, &AGoalTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AGoalTriggerBox::OnOverlapEnd);
}


void AGoalTriggerBox::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void AGoalTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == Ball) {
        IsBallInGoal = true;
    	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));

    }
}

void AGoalTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this)&& OtherActor == Ball) {
        IsBallInGoal = false;
    	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));


    }
}