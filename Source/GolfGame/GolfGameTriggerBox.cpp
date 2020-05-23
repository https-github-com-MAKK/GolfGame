// Fill out your copyright notice in the Description page of Project Settings.


#include "GolfGameTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"

AGolfGameTriggerBox::AGolfGameTriggerBox()
{

    OnActorBeginOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapBegin);
    OnActorEndOverlap.AddDynamic(this, &AGolfGameTriggerBox::OnOverlapEnd);
}


void AGolfGameTriggerBox::BeginPlay()
{
    Super::BeginPlay();
    if (ShowDrawDebugBox == true)
    {
        DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);
    }
   
}

void AGolfGameTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
        OverlapBeginAction();
       GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));

    }
}

void AGolfGameTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
    if (OtherActor && (OtherActor != this) && OtherActor == ActorToCheck) {
       OverlapEndAction();
    	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
    }
}


