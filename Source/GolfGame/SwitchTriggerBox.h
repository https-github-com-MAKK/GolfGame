// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "Switch.h"
#include "SwitchTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API ASwitchTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		TArray<ASwitch*> Switches;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float OffEverySec;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float OnEverySec;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOff;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		bool CanOnlyBeTriggeredOnce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		int ReapeatNum;
		UWorld* World;
		FTimerHandle TimerHandleSwitchOn;
		FTimerHandle TimerHandleSwitchOff;
		int CallCount;
		bool HasPreviouslyBeenTriggeredBegin;
		bool HasPreviouslyBeenTriggeredEnd;
public:

	ASwitchTriggerBox();
	void SwitchOff();
	void SwitchOn();
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
};
