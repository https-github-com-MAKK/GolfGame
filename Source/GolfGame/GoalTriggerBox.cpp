/*GoalTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Goal trigger box that stops ball from being summoned or teleported
 *to when overlapped, and allows ball to be summoned or teleported when overlap ends.
 */

#include "GoalTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"


void AGoalTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    Ball = dynamic_cast<ABall*>(ActorToCheck);
}

void AGoalTriggerBox::OverlapBeginAction()
{
    if (Ball) {
        UE_LOG(LogTemp, Log, TEXT("Goal trigger overlap begin"));
        IsBallInGoal = true;
        Ball->SetCanBallBeSummoned(false);
        Ball->SetCanBeTeleportedTo(false);
    }
}


void AGoalTriggerBox::OverlapEndAction()
{
    UE_LOG(LogTemp, Log, TEXT("Goal trigger overlap end"));
    if (Ball) {
        IsBallInGoal = false;
        Ball->SetCanBallBeSummoned(true);
        Ball->SetCanBeTeleportedTo(true);
    }
}

bool AGoalTriggerBox::GetIsBallInGoal()
{
    return IsBallInGoal;
}

void AGoalTriggerBox::SetIsBallInGoal(bool BallInGoal)
{
    IsBallInGoal=BallInGoal;
}