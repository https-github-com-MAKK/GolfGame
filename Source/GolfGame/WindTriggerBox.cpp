// Fill out your copyright notice in the Description page of Project Settings.

#include "PlatformGravityTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include <Ball.h>
#include "GameFramework/WorldSettings.h"
#include "WindTriggerBox.h"
#include "GameFramework/Pawn.h"




AWindTriggerBox::AWindTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AWindTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AWindTriggerBox::OnOverlapEnd);
}

void AWindTriggerBox::BeginPlay() 
{
	IsUsable = false;
	Super::BeginPlay();

}

void AWindTriggerBox::OnOverlapBegin(class AActor* OverlappedActor,  class AActor* OtherActor) 
{
	if(IsUsable)
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ISUSable true"));

	if (!IsUsable)
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ISUSable false"));

	if (IsTriggered)
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ISTriggered true"));

	if (!IsTriggered)
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ISTriggered true"));

	 cameraForward = GetActorForwardVector();
	 if (OtherActor && OtherActor != this && OtherActor == Ball && !WindOn && ((IsTriggered && IsUsable) || (!IsTriggered && !IsUsable)))
	 {
		 AddForce(OverlappedActor, OtherActor);
		 
	 }
	/* cameraForward = GetActorForwardVector();
	 if (OtherActor && OtherActor != this && OtherActor == Ball && !WindOn)
	 {
		 AddForce(OverlappedActor, OtherActor);

	 }*/
}

void AWindTriggerBox::AddForce( class AActor* OverlappedActor, class AActor* OtherActor)
{
	

	WindOn = true;
	meshRootComp = Cast<UStaticMeshComponent>(OtherActor->GetRootComponent());
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ForceAdded"));

	GetWorld()->GetTimerManager().SetTimer(InputADelayManager, this, &AWindTriggerBox::Tick, .1F, true);

}

void AWindTriggerBox::Tick()
{

	meshRootComp->AddForce(cameraForward * force * meshRootComp->GetMass());
	
}

void AWindTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (GetWorld()->GetTimerManager().IsTimerActive(InputADelayManager)) 
	{
		GetWorld()->GetTimerManager().ClearTimer(InputADelayManager);
		WindOn = false;
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ForceStopped"));

	}
}
