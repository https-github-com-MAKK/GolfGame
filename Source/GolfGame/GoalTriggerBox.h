// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TestBall.h"
#include "Components/LightComponent.h"
#include "GoalTriggerBox.generated.h"


UCLASS()
class GOLFGAME_API AGoalTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =References)
		ATestBall* Ball;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = References)
		AActor* DoorTarget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorLight;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* GoalLight;
	
public:

	AGoalTriggerBox();
	
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInGoal;
	
};
