// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "ChangeTeleportToDialogue.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AChangeTeleportToDialogue : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:

	AChangeTeleportToDialogue(){};

	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;
	
	virtual void OverlapBeginAction() override;
	
	virtual void OverlapEndAction() override;
};
