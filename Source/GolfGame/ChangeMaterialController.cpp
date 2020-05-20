// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMaterialController.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AChangeMaterialController::AChangeMaterialController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	MyBoxComponent->SetupAttachment(RootComponent);

	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AChangeMaterialController::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AChangeMaterialController::BeginPlay()
{
	Super::BeginPlay();

	//DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::Green, true, -1, 0, 10);

	MyMesh->SetMaterial(0, OffMaterial);
	CanBeHit = true;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AChangeMaterialController::SetCanBeHit, 1.0f, true, 5.0f);

}

// Called every frame
void AChangeMaterialController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeMaterialController::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweetResult)
{
	if(CanBeHit)
	{
		if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (CurrentSwitchState == Off) && (OtherActor == Ball))
		{
			MyMesh->SetMaterial(0, OnMaterial);
			CurrentSwitchState = On;
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Switch On"));
			
		}
		else if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (CurrentSwitchState == On) && (OtherActor == Ball))
		{
			MyMesh->SetMaterial(0, OffMaterial);
			CurrentSwitchState = Off;
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Switch Off"));
			
		}
		TogglePlatformMovement();
		ToggleSpotlight();
		CyclePlatformMovingAudio();
		CanBeHit = false;
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Orange, TEXT("Must wait"));
	}
			
}

void AChangeMaterialController::TogglePlatformMovement()
{
	if(AssociatedPlatform != nullptr)
	{
		if(AssociatedPlatform->IsPlatFormMoving)
		{
			AssociatedPlatform->IsPlatFormMoving = false;
		}
		else
		{
			AssociatedPlatform->IsPlatFormMoving = true;
		}
	}
}

void AChangeMaterialController::ToggleSpotlight()
{
	if(AssociatedRectlight != nullptr)
	{
		if(CurrentSpotlightState == Off)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("Light On"));
			CurrentSpotlightState = On;
		}
		else
		{	
			GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("Light Off"));
			CurrentSpotlightState = Off;
		}
		AssociatedRectlight->RectLightComponent->ToggleVisibility();
	}
}

void AChangeMaterialController::SetCanBeHit()
{
	CanBeHit = true;
}

void AChangeMaterialController::CyclePlatformMovingAudio()
{
	//AssociatedPlatform->ToggleMovingAudio();
	/*if(CurrentMovingAudio == On)
	{
		//AssociatedPlatform->PlatformMovingAudio->FadeOut(2, 0, EAudioFaderCurve::Linear);
		AssociatedPlatform->PlatformMovingAudio->Stop();
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("Platform audio stopped"));
		CurrentMovingAudio = Off;
	}
	else
	{
		//AssociatedPlatform->PlatformMovingAudio->FadeIn(2, 1,0, EAudioFaderCurve::Linear);
		AssociatedPlatform->PlatformMovingAudio->Play();
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("Platform audio started"));
		CurrentMovingAudio = On;
	}*/
}




