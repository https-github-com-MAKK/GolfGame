#pragma once
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "Switch.h"
#include "SwitchTriggerBox.generated.h"
/**\brief Trigger box that turns a list of switches on/off.
 *\details Triggerbox for any subclass that extends Switch.Holds an array of switches and
 * when overlapped will flip the switches in the array on, when overlap ends flips the switches off.
 */
UCLASS()
class GOLFGAME_API ASwitchTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()
	
private:
	
	/**\brief Indicates if this trigger box has been previously overlapped by ActorToCheck.*/
	bool HasPreviouslyBeenTriggeredBegin;

	/**\brief Indicates if this trigger box has been previously stopped being overlapped by ActorToCheck.*/
	bool HasPreviouslyBeenTriggeredEnd;

	/**\brief Helper method for OverlapBeginAction that creates the timer for SwitchOn().*/
	void OverlapBeginActionHelper();
	
protected:

	/**\brief The Timer handle for the Switch On Timer.*/
	FTimerHandle TimerHandleSwitchOn;

	/**\brief The Timer handle for the Switch Off Timer.*/
	FTimerHandle TimerHandleSwitchOff;
	
	/**\brief Array of switches to turn on or off.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		TArray<ASwitch*> Switches;

	/**\brief The value of the time to wait before turning on the switch after overlap begins.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOn;

	/**\brief The value of the time to wait before turning off the switch after overlap ends.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOff;

	/**\brief Indicates if this trigger box can only be triggered once or not.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		bool CanOnlyBeTriggeredOnce;

	/**\brief Indicates that the OverlapEndAction will be disabled and instead the off switch
	 *will execute, with the delay determined by DelayTimeOff,
	 *right after SwitchOn finishes executing.  
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		bool DisableOverlapEnd;
public:
	
	/**\brief Iterates through the switches array and turns each switch off.*/
	
	void SwitchOff();

	/**\brief Iterates through the switches array and turns each switch on.*/
	void SwitchOn();

	/**\brief Determines if this method can only be called once, has already been triggered
	 *or if OverlapEndAction has been disabled.  Then calls OverlapBeginActionHelper
	 *to create the time that calls the SwitchOn method to turn on all switches.
	 */
	
	virtual void OverlapBeginAction() override;

	/**\brief Determines if this method can only be called once or has previously been called.
	 *Creates the timer that calls the SwitchOff method to turn off all switches.
	 *the SwitchOn method.
	 */
	
	virtual void OverlapEndAction() override;
};
