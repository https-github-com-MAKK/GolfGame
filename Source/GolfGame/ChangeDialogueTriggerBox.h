// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "Sound/SoundBase.h"
#include "ChangeDialogueTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AChangeDialogueTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AChangeDialogueTriggerBox();
	
	UPROPERTY(EditAnywhere)
		class USoundBase* Dialogue;

	UPROPERTY(EditAnywhere)
		class AGolfGameCharacter* Player;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

private:

	bool DialoguePlayed;
	
};
