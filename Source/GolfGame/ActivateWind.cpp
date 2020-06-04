// Fill out your copyright notice in the Description page of Project Settings.


#include "ActivateWind.h"
// Fill out your copyright notice in the Description page of Project Settings.

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

	if (!OnAtStart) {
		CurrentSwitchState = Off;
	}

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AActivateWind::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AActivateWind::BeginPlay()
{
	Super::BeginPlay();

	//DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::Green, true, -1, 0, 10);

	MyMesh->SetMaterial(0, OffMaterial);

	if (AssociatedWindBox == nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("Platform/wind switch not setup"));
	}

	CanBeHit = true;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AActivateWind::SetCanBeHit, 1.0f, true, 5.0f);

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

		}
		
		ToggleSpotlight();
		CanBeHit = false;
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




