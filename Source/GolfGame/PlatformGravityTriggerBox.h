// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "PlatformGravityTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlatformGravityTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// constructor sets default values for this actor's properties
	APlatformGravityTriggerBox();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	// specific actor for overlap
	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	UPROPERTY(EditAnywhere)
		float GravityInsideTriggerBox = -100.0;

private:

	float OriginalWorldGravity;
	
};
