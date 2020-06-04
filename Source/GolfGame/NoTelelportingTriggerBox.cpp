/*NoTeleportingTriggerBox.cpp
 *Author: Kaylene Petrin 
 *Revision: 1 (05/15/2020)
 *Description: Trigger box that prevents the player from teleporting to the area this trigger box
 *covers when the ball is overlapping this trigger box 
 */

#pragma once
#include "NoTelelportingTriggerBox.h"
#include "CoreMinimal.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Engine.h"

void ANoTelelportingTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    Ball = dynamic_cast<ABall*>(ActorToCheck);
}

void ANoTelelportingTriggerBox::OverlapBeginAction()
{
    if (Ball) {
           Ball->SetCanBeTeleportedTo(false);
    }
}

void ANoTelelportingTriggerBox::OverlapEndAction()
{
    if (Ball) {
        Ball->SetCanBeTeleportedTo(true);
    }
}


