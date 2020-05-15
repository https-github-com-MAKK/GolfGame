// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "NoTelelportingTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API ANoTelelportingTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()
private:
	ABall* Ball;
protected:
	virtual void BeginPlay() override;
public:

	ANoTelelportingTriggerBox();
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInNoTeleportationZone;
};
