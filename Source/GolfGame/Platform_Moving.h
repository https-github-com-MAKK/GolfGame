// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform_Moving.generated.h"

UCLASS()
class GOLFGAME_API APlatform_Moving : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatform_Moving();

	//skinny or wide platform mesh
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//factor for which the platform will move up and down
	UPROPERTY(EditAnywhere)
		float ScaleFactor = 50.0;

	bool IsPlatFormMoving = false;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	//random number for platform motion, takes place of time since creation
	int Random;
	
};
