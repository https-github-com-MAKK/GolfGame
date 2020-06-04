#pragma once
#include "CoreMinimal.h"
#include "Switch.h"
#include "Engine/Light.h"
#include "GolfGameEnums.h"
#include "LightSwitch.generated.h"
/**\brief Switches a list of lights on and off.
*\details A light switch that contains an array of lights and preforms an action
* when turned off or on.The actions that can be preformed include : hide, show, flicker, dim lights,
* or do nothing.When turned off or on, the array is iterated overand the defined "On" or "Off"
* action is preformed on all lights in the array.
*/
UCLASS()
class GOLFGAME_API ALightSwitch: public ASwitch
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:
		/**\brief Indicates if the lights are currently hidden (off) or not.*/
		bool AreLightsHidden;

		/**\brief Indicates if the lights are currently dimmed or not.*/
		bool AreLightsDimmed;

		/**\brief Gets the method to call when this switch is switched on or off.
		 *\details The method to call is determined by the Status UEnum.  The method will
		 *either call Flicker(), HideLights(bool Show), or DimLights(float DimVar)
		 *depending on the UEnum passed.
		 *\param Status the GolfGameEnum that determines what method to call.
		 */
	
		virtual void GetMethodToCall(uint8 Status) override;
	
protected:

	/**\brief Indicates what action to preform when this class is switched on: hide, show,
	 *flicker, dim lights, or do nothing.*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus On;

	/**\brief Indicates what action to preform when this class is switched off: hide, show,
	 *flicker, dim lights, or do nothing.*/

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		LightStatus Off;

	/**\brief Indicates the rate at which the lights will flicker.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerRate;

	/**\brief The max value to increase the light brightness to when flickering.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerBrighten;

	/**\brief The min value to decrease the light brightness to when flickering.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float FlickerDim;

	/**\brief The value of the light brightness to decrease the lights to.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		float Dim;

	/**\brief The array of lights for this light switch.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<ALight*> Lights;

	/**\brief Flickers the lights. 
	 *\details FlickerLights() will
	 *switch between changing the light intensity to FlickerBrighten
	 *and FlickerDim at a rate based on the FlickerRate.
	 */

	void FlickerLights();

	/**\brief Dims the lights to the light intensity based on the variable DimVar.
	 *\param DimVar the new light intensity to set the lights to.
	 */
	
	void DimLights(float DimVar);

	/**\brief Hides the lights in the Lights array if Show is true, otherwise shows
	 *the Lights.
	 *\param Show will hide the Lights if true, will show Lights if false.
	 */

	void HideLights(bool Show);

public:

	/**\brief The action that will be preformed when this switch is switched on,
	 *determined by the "On" variable.
	 */
	
	virtual void ActionOn() override;

	/**\brief The action that will be preformed when this switch is switched off,
	 *determined by the "Off" variable.
	 */
	
	virtual void ActionOff() override;
	
	/**\brief Returns the "Off" variable
	 *\returns uint8 value of the "Off" variable
	 */

	virtual uint8 GetActionOff() override;

	/**\brief Returns the "On" variable
	 *\returns uint8 value of the "On" variable.
	 */

	virtual uint8 GetActionOn() override;

	/**\brief Sets the "On" variable
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "On" variable.
	 */

	virtual void SetActionOn(uint8 Status) override;

	/**\brief Sets the "Off" variable
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "Off" variable.
	 */

	virtual void SetActionOff(uint8 Status) override;
};
