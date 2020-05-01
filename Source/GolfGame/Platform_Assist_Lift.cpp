// Fill out your copyright notice in the Description page of Project Settings.


#include "Platform_Assist_Lift.h"

// Sets default values
APlatform_Assist_Lift::APlatform_Assist_Lift()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void APlatform_Assist_Lift::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlatform_Assist_Lift::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	float RunningTime = GetGameTimeSinceCreation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * ScaleFactor;
	SetActorLocation(NewLocation);

}

