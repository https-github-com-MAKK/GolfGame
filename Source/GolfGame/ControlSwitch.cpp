// Fill out your copyright notice in the Description page of Project Settings.


#include "ControlSwitch.h"
#include "Materials/MaterialExpressionDeltaTime.h"

// Sets default values
AControlSwitch::AControlSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshOn"));
}

// Called when the game starts or when spawned
void AControlSwitch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AControlSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

