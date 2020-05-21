// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "GolfGameTriggerBox.h"
#include "MusicChangeTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AMusicChangeTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AMusicChangeTriggerBox();

	UPROPERTY(EditAnywhere, Category =Music)
		class USoundBase* Music;

	UPROPERTY(EditAnywhere, Category = Music)
		class AGolfGameCharacter* PlayerForAudio;

	UFUNCTION()
		virtual void OverlapBeginAction() override;
		virtual void OverlapEndAction() override;
};
