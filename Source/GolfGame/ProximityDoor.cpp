// Fill out your copyright notice in the Description page of Project Settings.

#include "ProximityDoor.h"
#include "Components/BoxComponent.h"


// Sets default values
AProximityDoor::AProximityDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Trigger"));

}

// Called when the game starts or when spawned
void AProximityDoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProximityDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

