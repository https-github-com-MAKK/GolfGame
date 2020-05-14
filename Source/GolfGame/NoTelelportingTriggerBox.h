// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "NoTelelportingTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API ANoTelelportingTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		ABall* Ball;
	//default is true
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		bool IsBallInBoxToStart;
public:

	ANoTelelportingTriggerBox();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInNoTeleportationZone;
};
