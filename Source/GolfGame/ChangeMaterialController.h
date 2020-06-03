// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
#include "Platform_Moving.h"
#include "Ball.h"
#include "Engine/RectLight.h"
#include "ElevatorPlatform.h"
#include "Components/RectLightComponent.h"
#include "Components/AudioComponent.h"
#include "ChangeMaterialController.generated.h"


UCLASS()
class GOLFGAME_API AChangeMaterialController : public AActor
{
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	AChangeMaterialController();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Visible mesh representing the actor
	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	//Green material should be selected, represents the switch in the on state
	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	//Red material should be selected, represents the switch in the off state
	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	//Box component for the overlapping section of the switch, where the ball will make contact and toggle switch properties
	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	//Toggles properties when ball overlaps the actor
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	//Represents the moving platform whose movement is toggled on or off
	UPROPERTY(EditAnywhere)
		class APlatform_Moving* AssociatedPlatform;

	//The ball that impact the switch to turn it on or off
	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	//Selected light source to toggle visibility
	UPROPERTY(EditAnywhere)
		class ARectLight* AssociatedRectlight;

	//Selected elevator to toggle active or inactive 
	UPROPERTY(EditAnywhere)
		class AElevatorPlatform* AssociatedElevator;
	
	
private:

	//Toggles a moving platform's movement to on or off
	void TogglePlatformMovement();

	//Toggles visibility of selected light source
	void ToggleSpotlight();

	//Toggles a selected elevator to active or inactive
	void ToggleElevator();

	//sets CanBeHit variable to true
	void SetCanBeHit();

	//Intended to toggle audio component sound on or off, unfinished
	void CyclePlatformMovingAudio();

	//enum for switches to internally represent whether they are in an on or off state
	enum SwitchState { On, Off };

	//all associated actors are set to off at start
	SwitchState CurrentSwitchState = Off;
	SwitchState CurrentSpotlightState = Off;
	SwitchState CurrentMovingAudio = Off;

	//Whether the switch can currently be hit by the ball to toggle associated actors
	bool CanBeHit;

	//Timer for when the switch can be hit by the ball
	FTimerHandle MemberTimerHandle;
	
};
