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
    if (ActorToCheck == NULL) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ctor null"));
    }
    Ball = dynamic_cast<ABall*>(ActorToCheck);
    if (Ball == NULL) {
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Null bitch"));
    }
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


