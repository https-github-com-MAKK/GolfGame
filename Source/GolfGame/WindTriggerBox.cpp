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
	Super::BeginPlay();

}

void AWindTriggerBox::OnOverlapBegin(class AActor* OverlappedActor,  class AActor* OtherActor) 
{
		

	 cameraForward = GetActorForwardVector();
	 if (OtherActor && OtherActor != this && OtherActor == Ball && WindOn == false)
	 {
	
		 AddForce(OverlappedActor, OtherActor);

		 
	 }
}

void AWindTriggerBox::AddForce( class AActor* OverlappedActor, class AActor* OtherActor)
{
	

	WindOn = true;
	MeshRootComp = Cast<UStaticMeshComponent>(OtherActor->GetRootComponent());
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("SpotLight On"));
	GetWorld()->GetTimerManager().SetTimer(InputADelayManager, this, &AWindTriggerBox::Tick, .1F, true);

}

void AWindTriggerBox::Tick()
{
	MeshRootComp->AddForce(cameraForward * 50000 * MeshRootComp->GetMass());
	//GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ForceAdded"));
	
}

void AWindTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	
}
