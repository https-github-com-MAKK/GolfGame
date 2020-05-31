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
		int PauseTime; //Length of time platform pauses at the ends of its path
	
	UPROPERTY(EditAnywhere)
		float PathHeight; //the length of the platform's path

	UPROPERTY(EditAnywhere)
		float Speed; //speed of platform

	UPROPERTY(EditAnywhere)
		int Direction; //indicates direction of platform movement

	UPROPERTY(EditAnywhere)
		FString Axis; //axis of movement

	bool Paused; //the state of the platform is paused
	int CurTime; //how much time has elapsed since the pause began
	float MaxX; //the calculated max X value of the platform in the game
	float MaxY; //the calculated max Y value of the platform in the game
	float MaxZ; //the calculated max Z value of the platform in the game
	float OriginalX; //original X location of platform
	float OriginalY; //original Y location of platform
	float OriginalZ; //original Z location of platform
};
