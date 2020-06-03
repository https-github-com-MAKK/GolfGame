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

	//Sound base for current music cue
	UPROPERTY(EditAnywhere, Category = Music)
		class USoundBase* Music;

	//reference to the player so that the new music cue can be loaded into the audio component for music
	UPROPERTY(EditAnywhere, Category = Music)
		class AGolfGameCharacter* PlayerForAudio;

	//upon beginning the overlap, the new music cue is loaded to the player and is played
	UFUNCTION()
		virtual void OverlapBeginAction() override;
		virtual void OverlapEndAction() override;

private:

	//represents whether the music cue has already been loaded and played
	bool MusicStarted = false;
	
};
