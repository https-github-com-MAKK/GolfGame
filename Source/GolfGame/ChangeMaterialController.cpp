/*ChangeMaterialController.cpp
 *Author: Andrew Sales
 *Description: Class controls the functionality behind the in-game switches. Toggles movement of associated elevator or moving
 *platform, switches material of the controller to represent whether it is on or off, and toggles visiblity of an associated
 *light source. The switch can only be hit once per second by the ball as to not have false positive hits.
 */


#include "ChangeMaterialController.h"
#include "ElevatorPlatform.h"
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
			UE_LOG(LogTemp, Log, TEXT("Switch on"));
			
		}
		else if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (CurrentSwitchState == On) && (OtherActor == Ball))
		{
			MyMesh->SetMaterial(0, OffMaterial);
			CurrentSwitchState = Off;
			UE_LOG(LogTemp, Log, TEXT("Switch off"));
			
		}
		TogglePlatformMovement();
		ToggleSpotlight();
		ToggleElevator();
		CyclePlatformMovingAudio();
		CanBeHit = false;
		UE_LOG(LogTemp, Log, TEXT("Cannot hit switch yet"));
	}
			
}



void AChangeMaterialController::TogglePlatformMovement()
{
	if(AssociatedPlatform)
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
	if(AssociatedRectlight)
	{
		if(CurrentSpotlightState == Off)
		{
			UE_LOG(LogTemp, Log, TEXT("Light on"));
			CurrentSpotlightState = On;
		}
		else
		{	
			UE_LOG(LogTemp, Log, TEXT("Light off"));
			CurrentSpotlightState = Off;
		}
		AssociatedRectlight->RectLightComponent->ToggleVisibility();
	}
}

void AChangeMaterialController::ToggleElevator()
{
	if (AssociatedElevator)
	{
		if (AssociatedElevator->ElevatorActive)
		{
			AssociatedElevator->ElevatorActive = false;
			UE_LOG(LogTemp, Warning, TEXT("Elevator Deactivated"));
		}
		else
		{
			AssociatedElevator->ElevatorActive = true;
			UE_LOG(LogTemp, Warning, TEXT("Elevator Activated"));
		}
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




