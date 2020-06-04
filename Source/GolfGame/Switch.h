
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.generated.h"

/**\brief Abstract class that switches actors on / off.
*\details Ue4 interfaces do not work well, so an abstract class was used*/
UCLASS(Abstract)

class GOLFGAME_API ASwitch : public AActor
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

public:	


	/**\brief Gets the method to call when this switch is switched on or off.
	 *The method to call is determined by the Status.
	 *\param Status the GolfGameEnum that determines what method to call
	 */
	
	virtual void GetMethodToCall(uint8 Status) PURE_VIRTUAL(ASwitch::GetMethodToCall, );
	
	/**\brief The action that will be preformed when this switch is switched on,
	*determined by the "On" variable. */

	virtual void ActionOn() PURE_VIRTUAL(ASwitch::ActionOn, );

	/**\brief The action that will be preformed when this switch is switched off,
	 *determined by the "Off" variable.
	 */
	
	 virtual void ActionOff() PURE_VIRTUAL(ASwitch::ActionOff, );

	 /**\brief Returns the "Off" variable.
	  *\returns uint8 value of the "Off" variable.
	  */

	virtual uint8 GetActionOff() PURE_VIRTUAL(ASwitch::GetActionOff, return 0;);

	/**\brief Returns the "On" variable.
	 *\returns uint8 value of the "On" variable.
	 */

	virtual uint8 GetActionOn() PURE_VIRTUAL(ASwitch::GetActionOn, return 0;);

	/**\brief Sets the "On" variable.
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "On" variable.
	 */

	virtual void SetActionOn(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOn, );

	/**\brief Sets the "Off" variable.
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "Off" variable.
	 */
	
	virtual void SetActionOff(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOff, );

};
