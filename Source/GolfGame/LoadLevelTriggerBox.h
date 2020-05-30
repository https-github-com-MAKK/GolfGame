// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "LoadLevelTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API ALoadLevelTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:
	ALoadLevelTriggerBox();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsNotBlueprint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RollCredits;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LevelLoadTimeDelay;
	UFUNCTION(BlueprintCallable, Category = LevelChange)
		void LevelLoad();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelToLoad;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsCharacterInTrigger;

public:
	UFUNCTION(BlueprintCallable, Category = LevelChange)
	void SetTimeDelay(float TimeDelay);
	float GetTimeDelay();
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
};

