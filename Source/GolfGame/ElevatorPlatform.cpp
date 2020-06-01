// Fill out your copyright notice in the Description page of Project Settings.

#include "ElevatorPlatform.h"

// Sets default values
AElevatorPlatform::AElevatorPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	ElevatorActive = false;
	MoveUp = false;
	MoveDown = false;
	TargetZ = 700.0f;
	Speed = 0.5f;

}

// Called when the game starts or when spawned
void AElevatorPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginalZ = GetActorLocation().Z;
	
}

// Called every frame
void AElevatorPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (MoveUp) {
		FVector UpLocation = GetActorLocation();
		FVector TriggerUpLocation = Trigger->GetActorLocation();
		UpLocation.Z += Speed;
		TriggerUpLocation.Z += Speed;
		SetActorLocation(UpLocation);
		Trigger->SetActorLocation(TriggerUpLocation);
		if (UpLocation.Z > TargetZ - Speed)
		{
			MoveUp = false;
		}
	}
	else if (MoveDown) {
		FVector DownLocation = GetActorLocation();
		FVector TriggerDownLocation = Trigger->GetActorLocation();
		DownLocation.Z -= Speed;
		TriggerDownLocation.Z -= Speed;
		SetActorLocation(DownLocation);
		Trigger->SetActorLocation(TriggerDownLocation);
		if (DownLocation.Z == OriginalZ)
		{
			MoveDown = false;
		}
	}

}

