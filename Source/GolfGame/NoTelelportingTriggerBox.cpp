/*NoTeleportingTriggerBox.cpp
 *Author: Kaylene Petrin
 *Description: Trigger box that prevents the player from teleporting to the area this trigger box
 *covers when the ball is inside the trigger box.
 */
#pragma once
#include "NoTelelportingTriggerBox.h"
#include "CoreMinimal.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Engine.h"



//Attempts to cast the ActorToCheck reference to a ball
void ANoTelelportingTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    Ball = dynamic_cast<ABall*>(ActorToCheck);
}

//Sets the balls teleportation to ability to false when the ball overlaps this trigger box
void ANoTelelportingTriggerBox::OverlapBeginAction()
{
    if (Ball) {
           Ball->SetCanBeTeleportedTo(false);
    }
}
//Sets the balls teleportation to ability to true when the ball no longer overlaps this trigger box
void ANoTelelportingTriggerBox::OverlapEndAction()
{
    if (Ball) {
        Ball->SetCanBeTeleportedTo(true);
    }
}


