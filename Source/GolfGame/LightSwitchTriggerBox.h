// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Light.h"
#include "LightSwitchTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class GOLFGAME_API ALightSwitchTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float flickerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float flickerRate2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float Brightness;

UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float Brightness2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* MyCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> Lights;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> LightsToFlicker;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		//TArray<ALight*> LightsToDim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<ALight*> LightsToFlicker2;
	UPROPERTY(BlueprintReadWrite, Category = Lights)
		bool AreLightsHidden;
	UPROPERTY(BlueprintReadWrite, Category = Lights)
		bool AreLightsDimmed;
	
	UPROPERTY()
	UWorld* World;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		int Time;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		int LightLoopTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		int LightStableTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		int LightFlickerTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		int LightOffTime;
	UPROPERTY()
		int LastCalled;
	UFUNCTION()
	void TurnOffLights();
	void TurnOnLights();
	void FlickerLights();
	void FlickerLights2();
	void DimLights(TArray<ALight*> LightsToDim, float Brightness);
	void HideShowActors(TArray<AActor *> ActorsToHideShow, bool Show );
public:

	ALightSwitchTriggerBox();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

};
