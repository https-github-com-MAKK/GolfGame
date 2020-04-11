// Fill out your copyright notice in the Description page of Project Settings.
#include "Platform_Moving.h"
#include "Engine/Engine.h"


// Sets default values
APlatform_Moving::APlatform_Moving()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);
	VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	
}

// Called when the game starts or when spawned
void APlatform_Moving::BeginPlay()
{
	Super::BeginPlay();

	if(!ControllerSwitch)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Red, TEXT("Controller not assigned"));
	}
	
}

// Called every frame
void APlatform_Moving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(testAction)
	{
		FVector NewLocation = GetActorLocation();
		float RunningTime = GetGameTimeSinceCreation();
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
		NewLocation.Z += DeltaHeight * ScaleFactor;       
		SetActorLocation(NewLocation);
	}
	
}

