// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeMaterialController.h"
#include "DrawDebugHelpers.h"
#include "Components/BoxComponent.h"

// Sets default values
AChangeMaterialController::AChangeMaterialController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MyMesh"));
	RootComponent = MyMesh;

	MyBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("MyBoxComponent"));
	MyBoxComponent->InitBoxExtent(FVector(100, 100, 100));
	MyBoxComponent->SetCollisionProfileName("Trigger");
	MyBoxComponent->SetupAttachment(RootComponent);

	OnMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OnMaterial"));
	OffMaterial = CreateDefaultSubobject<UMaterial>(TEXT("OffMaterial"));

	MyBoxComponent->OnComponentBeginOverlap.AddDynamic(this, &AChangeMaterialController::OnOverlapBegin);
	
}

// Called when the game starts or when spawned
void AChangeMaterialController::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), FVector(100, 100, 100), FColor::Green, true, -1, 0, 10);

	MyMesh->SetMaterial(0, OffMaterial);
	
}

// Called every frame
void AChangeMaterialController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChangeMaterialController::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweetResult)
{
	if((CurrentState == 0))
	{
		MyMesh->SetMaterial(0, OnMaterial);
		
	}
	if((CurrentState == 1))
	{
		MyMesh->SetMaterial(0, OffMaterial);
		
	}
			
}

void AChangeMaterialController::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweetResult)
{
	if(CurrentState == 1)
	{
		CurrentState = 0;
	}
	else
	{
		CurrentState = 1;
	}
}


