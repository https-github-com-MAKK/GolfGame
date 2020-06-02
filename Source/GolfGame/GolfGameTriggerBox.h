// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameTriggerBox.generated.h"


UCLASS(Abstract)
class GOLFGAME_API AGolfGameTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	//Reference to the Actor that must be set to determine if said Actor is overlapping this class or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* ActorToCheck;
	//Sets whether to draw the debug box or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GolfGameTriggerBox)
		bool ShowDrawDebugBox=true;

public:
	AGolfGameTriggerBox();
	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
		virtual void OverlapEndAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapEndAction,);
		virtual void OverlapBeginAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapBeginAction,);
};
