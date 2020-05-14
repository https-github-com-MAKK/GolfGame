// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "NoTelelportingTriggerBox.h"


#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"


ANoTelelportingTriggerBox::ANoTelelportingTriggerBox()
{

    OnActorBeginOverlap.AddDynamic(this, &ANoTelelportingTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &ANoTelelportingTriggerBox::OnOverlapEnd);
}


void ANoTelelportingTriggerBox::BeginPlay()
{
    Super::BeginPlay();

    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void ANoTelelportingTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{

   if(OtherActor && (OtherActor != this) && OtherActor == Ball) {
        Ball->SetCanBeTeleportedTo(false);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Inside no teleport box"));

    }
}

void ANoTelelportingTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == Ball) {
        Ball->SetCanBeTeleportedTo(true);
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));


    }
}