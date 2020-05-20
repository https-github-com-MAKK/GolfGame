// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Switch.h"
#include "Engine/Light.h"
#include "GolfGameEnums.h"
#include "LightSwitch.generated.h"

/**
 *
 */
UCLASS()
class GOLFGAME_API ALightSwitch: public ASwitch
{
	GENERATED_BODY()
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus On;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus Off;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerBrighten;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerDim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float Dim;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<ALight*> Lights;
	UPROPERTY(BlueprintReadWrite, Category = Lights)
		bool AreLightsHidden;
	UPROPERTY(BlueprintReadWrite, Category = Lights)
		bool AreLightsDimmed;
	UPROPERTY()
		UWorld* World;
	UFUNCTION()
		void TurnOffLights();
	void TurnOnLights();
	void FlickerLights();
	void DimLights(float DimVar);
	void HideShowLights(bool Show);

public:

	ALightSwitch();
	virtual void ActionOn() override;
	virtual void ActionOff() override;
	virtual void GetMethodToCall(uint8 Status) override;
	virtual uint8 GetActionOff() override;
	virtual void SetActionOn(uint8 Status) override;
	virtual void SetActionOff(uint8 Status) override;
	virtual uint8 GetActionOn() override;
};
