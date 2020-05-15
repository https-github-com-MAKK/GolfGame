// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AGoalTriggerBox::AGoalTriggerBox()
{

}
void AGoalTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    if (ActorToCheck == NULL) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ctor null"));
    }
    Ball = dynamic_cast<ABall*>(ActorToCheck);
    if (Ball == NULL) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Null bitch"));
    }
}

void AGoalTriggerBox::OverlapBeginAction()
{
    if (ActorToCheck == NULL) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ctor null action"));
    }else
    {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ctor ok action"));

    	
    }
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin action goal trigger"));
    if (Ball) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("begin if"));
        IsBallInGoal = true;
    }
}


void AGoalTriggerBox::OverlapEndAction()
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end action goal trigger"));
    if (Ball) {
        IsBallInGoal = false;
    }
}

