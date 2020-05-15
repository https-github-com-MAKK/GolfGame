// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "GameFramework/Actor.h"
#include "HideShowActorSwitch.h"
#include "HideShowActorTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AHideShowActorTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		TArray<AHideShowActorSwitch*> ActorSwitch;
public:

	void HideShowActionBegin();
	void HideShowActionEnd();
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
};
