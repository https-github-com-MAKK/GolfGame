// Fill out your copyright notice in the Description page of Project Settings.


#pragma once
#include "NoTelelportingTriggerBox.h"
#include "CoreMinimal.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Engine.h"


ANoTelelportingTriggerBox::ANoTelelportingTriggerBox()
{
    

}

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


