// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AGolfGameTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* ActorToCheck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GolfGameTriggerBox)
		bool ShowDrawDebugBox=true;

public:
	AGolfGameTriggerBox();
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
		virtual void OverlapEndAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapEndAction,);
		virtual void OverlapBeginAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapBeginAction,);
};
