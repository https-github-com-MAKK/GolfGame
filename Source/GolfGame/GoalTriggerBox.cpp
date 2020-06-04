/*GoalTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1 (05/05/2020)
 *Revision: 2 (05/15/2020)
 *Rev. Author: Kaylene Pertin
 *Rev. Comments: Refactored pushed some code up to super class: GolfGameTriggerBox 
 *Description: Goal trigger box that stops the ball from being summoned or teleported
 *to when overlapped, and allows the ball to be summoned or teleported to when the ball
 *stops overlapping this trigger box.
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