#pragma once
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "Switch.h"
#include "SwitchTriggerBox.generated.h"


UCLASS()
class GOLFGAME_API ASwitchTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()
	
private:
	
	//Indicates if this trigger box has been previously overlapped by ActorToCheck
	bool HasPreviouslyBeenTriggeredBegin;

	//Indicates if this trigger box has been previously stopped being overlapped by ActorToCheck
	bool HasPreviouslyBeenTriggeredEnd;

	//Helper method for OverlapBeginAction that creates the timer for SwitchOn
	void OverlapBeginActionHelper();
	
protected:

	//The Timer handle for the Switch On Timer
	FTimerHandle TimerHandleSwitchOn;

	//The Timer handle for the Switch Off Timer
	FTimerHandle TimerHandleSwitchOff;
	
	//Array of switches to turn on or off
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		TArray<ASwitch*> Switches;

	//The value of the time to wait before turning on the switch after overlap begins
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOn;

	//The value of the time to wait before turning off the switch after overlap ends
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		float DelayTimeOff;

	//Indicates if this trigger box can only be triggered once or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		bool CanOnlyBeTriggeredOnce;

	/*Indicates that the OverlapEndAction will be disabled and instead the off switch
	 *will execute, with the delay determined by DelayTimeOff,
	 *right after SwitchOn finishes executing.  
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Switch)
		bool DisableOverlapEnd;
public:
	
	/*Iterates through the switches array and turns each switch off
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	void SwitchOff();

	/*Iterates through the switches array and turns each switch on
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void SwitchOn();

	/*Determines if this method can only be called once, has already been triggered
	 *or if OverlapEndAction has been disabled.  Then calls OverlapBeginActionHelper
	 *to create the time that calls the SwitchOn method to turn on all switches.
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void OverlapBeginAction() override;

	/*Determines if this method can only be called once or has previously been called.
	 *Creates the timer that calls the SwitchOff method to turn off all switches.
	 *the SwitchOn method
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void OverlapEndAction() override;
};
