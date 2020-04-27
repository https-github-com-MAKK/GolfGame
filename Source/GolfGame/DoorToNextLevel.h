// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "DoorToNextLevel.generated.h" 

UCLASS()
class GOLFGAME_API ADoorToNextLevel : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorToNextLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OpenDoor(float dt);

	UFUNCTION()
		void CloseDoor(float dt);

	class UStaticMeshComponent* Door;

	// declare sphere comp
	UPROPERTY(VisibleAnywhere, Category = "BoxComp")
		class UBoxComponent* BoxComp;

	UFUNCTION()
		void ToggleDoor(FVector ForwardVector);

	bool Opening;
	bool Closing;
	bool isClosed;

	float DotP;
	float MaxDegree;
	float AddRotation;
	float PosNeg;
	float DoorCurrentRotation;
};