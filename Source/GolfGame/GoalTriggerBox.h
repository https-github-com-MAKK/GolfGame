// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "GolfGameTriggerBox.h"
#include "GoalTriggerBox.generated.h"


UCLASS()
class GOLFGAME_API AGoalTriggerBox : public AGolfGameTriggerBox
{
GENERATED_BODY()
private:
	ABall* Ball;
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* GoalLight;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInGoal;

public:

	AGoalTriggerBox();
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
	bool GetIsBallInGoal();
	void SetIsBallInGoal(bool BallInGoal);

};
