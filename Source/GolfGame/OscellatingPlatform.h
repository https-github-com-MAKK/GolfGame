// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OscellatingPlatform.generated.h"

UCLASS()
class GOLFGAME_API AOscellatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	AOscellatingPlatform();

protected:
	void BeginPlay() override;

public:	
	void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		int PauseTime = 120; //Length of time platform pauses at the top or bottom of its path
	
	UPROPERTY(EditAnywhere)
		float PathHeight = 150.0f; //the height of the platform's path

	UPROPERTY(EditAnywhere)
		float Speed = 0.5f; //speed of platform

	int Direction; //indicates whether the platform is moving up or down;
	bool Paused; //the state of the platform is paused
	int CurTime; //how much time has elapsed since the pause began
	float MaxZ; //the calculated max Z value of the platform in the game
	float OriginalZ; //original location of platform

};
