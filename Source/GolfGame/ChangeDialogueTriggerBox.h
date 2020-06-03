// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "Sound/SoundBase.h"
#include "GolfGameTriggerBox.h"
#include "ChangeDialogueTriggerBox.generated.h"


UENUM()
enum class ETriggeringActor
{
	TriggeredByBall UMETA(DisplayName = "Ball"),
	TriggeredByPlayer UMETA(DisplayName = "Player")
};

UCLASS()
class GOLFGAME_API AChangeDialogueTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
	FTimerHandle TimerHandle;
	UPROPERTY(EditAnywhere, Category = Dialogue)
		float TimeToDelayDialogue;

public:

	AChangeDialogueTriggerBox();
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class AGolfGameCharacter* PlayerForAudio;
	void DialoguePlay();
private:

	bool DialoguePlayed;

};
