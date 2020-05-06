// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "MusicChangeTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AMusicChangeTriggerBox : public ATriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	AMusicChangeTriggerBox();

	UPROPERTY(EditAnywhere)
		class USoundBase* Music;

	UPROPERTY(EditAnywhere)
		class AGolfGameCharacter* Player;

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
