// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "Ball.generated.h"

UCLASS()
class GOLFGAME_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//default the ball cannot be telported to in beginning
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BallOptions)
		bool CanTeleportToInBeginning;
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool CanBeTeleportedTo;
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool HasBeenSummoned;
	UPROPERTY(EditAnywhere, Category = BallOptions)
		bool CanBallBeSummoned;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY()
		USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* SphereVisual;

	UPROPERTY()
		UParticleSystemComponent* SparksParticleSystem;

	UPROPERTY(VisibleAnywhere, Category = Sound)
		class UAudioComponent* CrackleSoundPlayer;

	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundCue* CrackleSound;

	UPROPERTY(EditAnywhere)
		class UMaterial* BallMaterial;

	UFUNCTION()

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		bool GetCanBeTeleportedTo();

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		void SetCanBeTeleportedTo(bool CanTeleportTo);

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		bool GetHasBeenSummonedOnce();

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		void SetHasBeenSummonedOnce(bool HasSummoned);

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		bool GetCanBallBeSummoned();

		/*
		 *Parameters:
		 *None
		 *Returns:
		 *void
		 */
		void SetCanBallBeSummoned(bool CanBeSummoned);
};
