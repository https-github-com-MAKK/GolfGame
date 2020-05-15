// Fill out your copyright notice in the Description page of Project Settings.


#include "GoalTrigger.h"

#include "Engine/Engine.h"

AGoalTrigger::AGoalTrigger()
{


}


void AGoalTrigger::OverlapBeginAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin action light trigger"));
    IsBallInGoal = true;
}


void AGoalTrigger::OverlapEndAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end action light trigger"));
    IsBallInGoal = false;

}


