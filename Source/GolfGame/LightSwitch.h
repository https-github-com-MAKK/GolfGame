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
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:
		//Indicates if the lights are currently hidden (off) or not
		bool AreLightsHidden;

		//Indicates if the lights are currently dimmed or not
		bool AreLightsDimmed;

		/*Gets the method to call when this switch is switched on or off.
		 *The method to call is determined by the Status UEnum.
		 *Parameters:
		 *uint8 Status the GolfGameEnum that determines what method to call
		 *Returns:
		 *void
		 */

		virtual void GetMethodToCall(uint8 Status) override;
	
protected:

	/*Indicates what action to preform when this class is switched on: hide, show,
	 *flicker, or dime lights
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus On;

	/*Indicates what action to preform when this class is switched off: hide, show,
	 *flicker, or dime lights
	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus Off;

	//Indicates the rate at which the lights will flicker
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerRate;

	//The max value to increase the light brightness to when flickering
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerBrighten;

	//The min value to decrease the light brightness to when flickering
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerDim;

	//The value of the light brightness to decrease the lights to 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float Dim;

	//The array of lights for this light switch
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<ALight*> Lights;

	
	void FlickerLights();
	void DimLights(float DimVar);
	void HideLights(bool Show);

public:

	/*The action that will be preformed when this switch is switched on,
	 *determined by the "On" variable.
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void ActionOn() override;

	/*The action that will be preformed when this switch is switched off,
	 *determined by the "Off" variable.
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void ActionOff() override;
	
	/*Returns the "Off" variable
	 *Parameters:
	 *None
	 *Returns:
	 *uint8 value of the "Off" variable
	 */

	virtual uint8 GetActionOff() override;

	/*Returns the "On" variable
	 *Parameters:
	 *None
	 *Returns:
	 *uint8 value of the "On" variable
	 */

	virtual uint8 GetActionOn() override;

	/*Sets the "On" variable
	 *Parameters:
	 *uint8 Status the GolfGameEnum that will be the new value
	 *of the "On" variable
	 *Returns:
	 *void
	 */

	virtual void SetActionOn(uint8 Status) override;

	/*Sets the "Off" variable
	 *Parameters:
	 *uint8 Status the GolfGameEnum that will be the new value
	 *of the "Off" variable
	 *Returns:
	 *void
	 */
	virtual void SetActionOff(uint8 Status) override;
};
