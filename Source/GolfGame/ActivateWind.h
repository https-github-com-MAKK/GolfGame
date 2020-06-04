// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
#include "Ball.h"
#include "Engine/RectLight.h"
#include "Components/RectLightComponent.h"
#include "ActivateWind.generated.h"


UCLASS()
class GOLFGAME_API AActivateWind : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AActivateWind();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	UPROPERTY(EditAnywhere)
		bool OnAtStart=true;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere)
		class AWindTriggerBox* AssociatedWindBox;

	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	UPROPERTY(EditAnywhere)
		class ARectLight* AssociatedRectlight;

	FTimerHandle MemberTimerHandle;

private:

	/*
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void ToggleWind();

	/*
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void ToggleSpotlight();

	/*
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void SetCanBeHit();

	enum SwitchState { On, Off };
	SwitchState CurrentSwitchState = Off;
	SwitchState CurrentSpotlightState = Off;

	bool CanBeHit;

};
