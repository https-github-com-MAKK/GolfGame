
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.generated.h"

UCLASS(Abstract)

class GOLFGAME_API ASwitch : public AActor
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

public:	


	/*Gets the method to call when this switch is switched on or off.
	 *The method to call is determined by the Status UEnum.
	 *Parameters:
	 *uint8 Status the GolfGameEnum that determines what method to call
	 *Returns:
	 *void
	 */
	
	virtual void GetMethodToCall(uint8 Status) PURE_VIRTUAL(ASwitch::GetMethodToCall, );
	
	/*The action that will be preformed when this switch is switched on,
	 *determined by the "On" variable.
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */

	virtual void ActionOn() PURE_VIRTUAL(ASwitch::ActionOn, );

	/*The action that will be preformed when this switch is switched off,
	 *determined by the "Off" variable.
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	 virtual void ActionOff() PURE_VIRTUAL(ASwitch::ActionOff, );

	/*Returns the "Off" variable
	 *Parameters:
	 *None
	 *Returns:
	 *uint8 value of the "Off" variable
	 */

	virtual uint8 GetActionOff() PURE_VIRTUAL(ASwitch::GetActionOff, return 0;);

	/*Returns the "On" variable
	 *Parameters:
	 *None
	 *Returns:
	 *uint8 value of the "On" variable
	 */

	virtual uint8 GetActionOn() PURE_VIRTUAL(ASwitch::GetActionOn, return 0;);

	/*Sets the "On" variable
	 *Parameters:
	 *uint8 Status the GolfGameEnum that will be the new value
	 *of the "On" variable
	 *Returns:
	 *void
	 */

	virtual void SetActionOn(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOn, );

	/*Sets the "Off" variable
	 *Parameters:
	 *uint8 Status the GolfGameEnum that will be the new value
	 *of the "Off" variable
	 *Returns:
	 *void
	 */
	
	virtual void SetActionOff(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOff, );



};
