// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TestBall.h"
#include "Components/LightComponent.h"
#include "Engine/Light.h"
#include "LightSwitchTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class GOLFGAME_API ALightSwitchTriggerBox : public ATriggerBox
{
	GENERATED_BODY()/*
public:
	// Sets default values for this actor's properties
	ALightSwitchTriggerBox();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* MyCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void TurnOffLights();
	void TurnOnLights();
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		ATestBall* Ball;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> Lights;
*/
protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* MyCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> Lights;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> LightsToFlicker;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<ALight*> LightsToDim;
	UPROPERTY(BlueprintReadWrite, Category = Lights)
		bool AreLightsHidden;
	UFUNCTION()
	void TurnOffLights();
	void TurnOnLights();
	void FlickerLights();
	void DimLights();
public:

	ALightSwitchTriggerBox();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
