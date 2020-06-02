// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "PlayOnceSoundTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlayOnceSoundTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = Audio)
		class USoundBase* Sound;

	UPROPERTY(EditAnywhere, Category = Audio)
		class AGolfGameCharacter* Player;

	UFUNCTION()
		virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;

private:

	bool HasSoundPlayed = false;
	
};
