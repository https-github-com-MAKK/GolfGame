// Fill out your copyright notice in the Description page of Project Settings.


#include "TestBall.h"

// Sets default values
ATestBall::ATestBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//VisualMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("VisualRepresentation"));
}

// Called when the game starts or when spawned
void ATestBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

