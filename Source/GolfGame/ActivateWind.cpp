/*ActivateWind.cpp
 *Author: Max Iniguez
 *Revision: 1 (05/25/2020)
 *Description: This trigger is used to turn on and off the boolean in the wind trigger box that turns on and off 
 *the wind mechanic
 */
#include "ActivateWind.h"
#include "WindTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h"

// Sets default values
AActivateWind::AActivateWind()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	//MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));

	if (!OnAtStart) 
	{
		CurrentSwitchState = Off;
	}

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AActivateWind::OnOverlapBegin);

	ToggleTwoWindTriggerBoxes = false;

}

// Called when the game starts or when spawned
void AActivateWind::BeginPlay()
{
	Super::BeginPlay();

	MyMesh->SetMaterial(0, OffMaterial);

	CanBeHit = true;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AActivateWind::SetCanBeHit, 1.0f, true, 5.0f);

	if (WindSoundLeft && WindSoundRight)
	{
		WindSoundRight->Stop();
		WindSoundLeft->Play();
	}

}

// Called every frame
void AActivateWind::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActivateWind::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweetResult)
{
	if (CanBeHit)
	{
		if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (CurrentSwitchState == Off) && (OtherActor == Ball))
		{
			MyMesh->SetMaterial(0, OnMaterial);
			CurrentSwitchState = On;
			ToggleWind();

		}
		else if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (CurrentSwitchState == On) && (OtherActor == Ball))
		{
			MyMesh->SetMaterial(0, OffMaterial);
			CurrentSwitchState = Off;
			ToggleWindOff();
		}
		ToggleWindSound();
		ToggleSpotlight();
		CanBeHit = false;
	}

}
void AActivateWind::ToggleWindOff() 
{
	if (AssociatedWindBox != nullptr)
	{
		AssociatedWindBox->IsUsable = false;
	}
}


void AActivateWind::ToggleWind()
{
	if (AssociatedWindBox != nullptr)
	{
		AssociatedWindBox->IsUsable = true;
	} 
}

void AActivateWind::ToggleSpotlight()
{
	if (AssociatedRectlight != nullptr)
	{
		if (CurrentSpotlightState == Off)
		{
			CurrentSpotlightState = On;
		}
		else
		{
			CurrentSpotlightState = Off;
		}
		AssociatedRectlight->RectLightComponent->ToggleVisibility();
	}
}

void AActivateWind::SetCanBeHit()
{
	CanBeHit = true;
}

void AActivateWind::ToggleWindSound()
{
	if(WindSoundLeft && WindSoundRight)
	{
		const float FadeInDuration = 1.5f;
		const float FadeOutDuration = 0.5f;
		const float VolumeOn = 1.0f;
		const float VolumeOff = 0.0f;

		if (CurrentWindSoundRight == Off && CurrentWindSoundLeft == On)
		{
			CurrentWindSoundRight = On;
			CurrentWindSoundLeft = Off;
			WindSoundRight->FadeIn(FadeInDuration, VolumeOn);
			WindSoundLeft->FadeOut(FadeOutDuration, VolumeOff);
		}
		else
		{
			CurrentWindSoundRight = Off;
			CurrentWindSoundLeft = On;
			WindSoundRight->FadeOut(FadeOutDuration, VolumeOff);
			WindSoundLeft->FadeIn(FadeInDuration, VolumeOn);
		}
	}

}




