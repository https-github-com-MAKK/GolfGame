// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformGravityTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include <TestBall.h>
#include "GameFramework/WorldSettings.h"

APlatformGravityTriggerBox::APlatformGravityTriggerBox()
{
    //Register Events
    OnActorBeginOverlap.AddDynamic(this, &APlatformGravityTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &APlatformGravityTriggerBox::OnOverlapEnd);

	
}

void APlatformGravityTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
    this->BlueprintTest();
    WorldGravity = GetWorldSettings()->GetGravityZ();
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %f"), WorldGravity));
}

void APlatformGravityTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && OtherActor == SpecificActor)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Begin"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("Overlapping Actor = %s"), *OverlappedActor->GetName()));

            GetWorldSettings()->bGlobalGravitySet = true;
            GetWorldSettings()->GlobalGravityZ = -100;
        }
    }
}

void APlatformGravityTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && OtherActor != this && OtherActor == SpecificActor)
    {
        if (GEngine)
        {
            GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Overlap Ended"));
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("%s has left the Trigger Box"), *OtherActor->GetName()));

            //GetWorldSettings()->bGlobalGravitySet = WorldGravity;
            GetWorldSettings()->bGlobalGravitySet = false;
        }
    }
}