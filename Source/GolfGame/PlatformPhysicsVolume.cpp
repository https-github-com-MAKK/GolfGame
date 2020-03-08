// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformPhysicsVolume.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Misc/App.h"

APlatformPhysicsVolume::APlatformPhysicsVolume()
{
    //Register Events
    Gravity = 1;
    OnActorBeginOverlap.AddDynamic(this, &APlatformPhysicsVolume::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APlatformPhysicsVolume::OnOverlapEnd);
}

void APlatformPhysicsVolume::BeginPlay()
{
    Super::BeginPlay();
    DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}

void APlatformPhysicsVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && OtherActor)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OverlappedActor->GetName()));

            this->BlueprintOverlapBegin(OtherActor);
        }
    }
}

void APlatformPhysicsVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && OtherActor == SpecificActor)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));
        }
    }
}
