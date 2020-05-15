// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Light.h"
#include "GolfGameEnums.h"
#include "LightSwitch.generated.h"

/**
 * 
 */

UCLASS()
class GOLFGAME_API ALightSwitch : public AActor
{


	GENERATED_BODY()
	protected:

		virtual void BeginPlay() override;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
			TEnumAsByte<LightStatus>  On;
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
			TEnumAsByte<LightStatus>  Off;
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
		void GetMethodToCall(TEnumAsByte<LightStatus>  Status);
		
	public:

		ALightSwitch();
		void LightActionOn();
		void LightActionOff();
		void SetLightActionOn(TEnumAsByte<LightStatus>  Status);
		void SetLightActionOff(TEnumAsByte<LightStatus>  Status);
		TEnumAsByte<LightStatus>  GetLightActionOn();
		TEnumAsByte<LightStatus> GetLightActionOff();

	};


