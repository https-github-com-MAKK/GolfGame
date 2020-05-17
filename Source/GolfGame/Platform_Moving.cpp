// Fill out your copyright notice in the Description page of Project Settings.
#include "Platform_Moving.h"
#include "Components/AudioComponent.h"
#include  "PlatformAudioComponent.h"
#include "Engine/Engine.h"
#include "Components/BoxComponent.h"


// Sets default values
APlatform_Moving::APlatform_Moving()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = VisualMesh; 
	//VisualMesh->SetupAttachment(RootComponent);
	
	PlatformMovingAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("SoundPlayer"));
	PlatformMovingAudio->bAutoActivate = false;
	PlatformMovingAudio->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	PlatformMovingAudio->Mobility = EComponentMobility::Movable;
	PlatformMovingAudio->SetupAttachment(RootComponent);

	/*
	 *
	 *AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComponent0"));

	AudioComponent->bAutoActivate = true;
	AudioComponent->bStopWhenOwnerDestroyed = true;
	AudioComponent->bShouldRemainActiveIfDropped = true;
	AudioComponent->Mobility = EComponentMobility::Movable;

	RootComponent = AudioComponent;

	bReplicates = false;
	SetHidden(true);
	SetCanBeDamaged(false);
	 * 
	 */
	
}

// Called when the game starts or when spawned
void APlatform_Moving::BeginPlay()
{
	Super::BeginPlay();

	Random = rand() % 100000;
	//PlatformMovingAudio->SetSound(MovingSound);
	
}

// Called every frame
void APlatform_Moving::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPlatFormMoving)
	{
		FVector NewLocation = GetActorLocation();
		float RunningTime = GetGameTimeSinceCreation() + Random;
		float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));

		if (Movement == EMovementType::UpDown)
		{
			NewLocation.Z += DeltaHeight * ScaleFactor;
		}
		else if (Movement == EMovementType::LeftRight)
		{
			NewLocation.Y += DeltaHeight * ScaleFactor;
		}
		else if (Movement == EMovementType::ForwardBack)
		{
			NewLocation.X += DeltaHeight * ScaleFactor;
		}

		SetActorLocation(NewLocation);

	}

}

void APlatform_Moving::ToggleMovingAudio()
{
	if(IsPlatFormMoving)
	{
		//PlatformMovingAudio->StopMovingAudio();
	}
	else
	{
		//PlatformMovingAudio->PlayMovingAudio();
	}
}



