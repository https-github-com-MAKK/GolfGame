// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Ball.generated.h"

UCLASS()
class GOLFGAME_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	void AddForce();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//default the ball cannot be telported to in beginning
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= BallOptions)
		bool CanTeleportToInBeginning;
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool CanBeTeleportedTo;
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool HasBeenSummoned;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* VisualMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial* BallMaterial;

	UFUNCTION()
		bool GetCanBeTeleportedTo();
		void SetCanBeTeleportedTo(bool CanTeleportTo);
		bool GetHasBeenSummonedOnce();
		void SetHasBeenSummonedOnce(bool HasSummoned);
};
