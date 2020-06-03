#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.h"
#include "HideShowActorSwitch.generated.h"


UCLASS()
class GOLFGAME_API AHideShowActorSwitch : public ASwitch
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:

	//Indicates how long the current index of the FlickerPattern should run
	int CurrentRunTime;

	//Indicates if this is the first time the FlickerInAndOut method has been called
	bool FirstTimeFlickerCalled;

	/*Indicates if the index of FlickerPattern has already been incremented during the
	 *indexes run time
	 */
	bool HasBeenIncremented;

	//The index of the FlickerPattern
	int FlickerIndex;

	/*The last time the world time was called, used to determine
	 *the Timer time and reset it.
	 */
	int LastCalled;

	/*Indicates how long the current FlickerPattern index
	 *has been running
	 */
	int Timer;

	//Indicates whether the actors are hidden or not
	bool AreActorsHidden;
	
	/*Increments the index of the FlickerPattern array
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void IncrementFlickerIndex();
	
	/*Sets the CurrentRunTime
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void SetCurrentRunTime();

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
	 *or flicker actors
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus On;
	
	/*Indicates what action to preform when this class is switched off: hide, show,
	 *or flicker actors
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus Off;

	//Holds a list of actors to be switch on and off
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<AActor*> ActorsToShowHide;

	//An array that holds the pattern that will be flickered
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<ActorHideShowStatus> FlickerPattern;

	//Indicates the time the actor will spend hidden when flickering in and out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeHidden;
	
	//Indicates the time the actor will spend shown when flickering in and out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeShown;

	//Indicates the time the actor will spend flickering when flickering in and out
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float TimeFlickering;

	//Indicates how often the FlickerInAndOut method will be called
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float FlickerRate;

	/*Hides the actors in the ActorsToShowHide array if Show is true, otherwise shows
	 *the actors.
	 *Parameters:
	 *Show will hide actors if true, will show if false
	 *Returns:
	 *void
	 */
	
		void HideActors(bool Show);

	/*Iterates over the FlickerPattern array at a rate based on the FlickerRate variable
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
		void FlickerInAndOut();
	
	/*Called when the game starts or when spawned, initializes some fields
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
		virtual void BeginPlay() override;

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


