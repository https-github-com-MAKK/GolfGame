// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "GolfGameTriggerBox.h"
#include "GoalTrigger.generated.h"



UCLASS()
class GOLFGAME_API AGoalTrigger : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		ABall* Ball;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* GoalLight;

public:

	AGoalTrigger();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInGoal;
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
};
