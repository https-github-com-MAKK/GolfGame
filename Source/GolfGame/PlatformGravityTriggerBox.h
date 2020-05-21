// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "PlatformGravityTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlatformGravityTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// constructor sets default values for this actor's properties
	APlatformGravityTriggerBox();

	UPROPERTY(EditAnywhere)
		float GravityInsideTriggerBox = -100.0;
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;

private:

	float OriginalWorldGravity;
	
};
