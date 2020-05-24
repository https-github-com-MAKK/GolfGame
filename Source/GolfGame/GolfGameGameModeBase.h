// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GolfGameGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API AGolfGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGolfGameGameModeBase();
	void EndGame();
	void LevelComplete();
	void LoadNextLevel();

private:
	void BeginPlay() override;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		TArray<FString> Levels;

	APlayerController* Controller;
	int32 CurrentLevel;
	FString NextLevel;

	void CheckLevel();
};
