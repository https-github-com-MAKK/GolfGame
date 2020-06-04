#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.h"
#include "HideShowActorSwitch.generated.h"
/**\brief Switches a list of actors on and off.
 *\details An actor switch that contains an array of actors and preforms an action
 *when turned off or on. The actions that can be preformed include: hide, show, flicker actors,
 *or do nothing. When turned off or on, the array is iterated over and the defined "On" or "Off"
 *action is preformed on all actors in the array.
*/

UCLASS()
class GOLFGAME_API AHideShowActorSwitch : public ASwitch
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:

	/** \brief Indicates how long the current index of the FlickerPattern should run.*/
	int CurrentRunTime;

	/** \brief Indicates if this is the first time the FlickerInAndOut method has been called.*/
	bool FirstTimeFlickerCalled;

	/**\brief Indicates if the index of FlickerPattern has already been incremented during the
	 *indexes run time.
	 */
	bool HasBeenIncremented;

	/**\brief The index of the FlickerPattern.*/
	int FlickerIndex;

	/**\brief The last time the world time was called, used to determine
	 *the Timer time and reset it.
	 */
	int LastCalled;

	/**\brief Indicates how long the current FlickerPattern index
	 *has been running.
	 */
	int Timer;

	/**\brief Indicates whether the actors are hidden or not.*/
	bool AreActorsHidden;

	/**\brief Increments the index of the FlickerPattern array.*/
	void IncrementFlickerIndex();

	/**\brief Sets CurrentRunTime based on the FlickerIndex value.*/
	void SetCurrentRunTime();

	/**\brief Gets the method to call when this switch is switched on or off.
	 *The method to call is determined by the Status.
	 *\param Status the GolfGameEnum that determines what method to call.
	 */
	virtual void GetMethodToCall(uint8 Status) override;

protected:

	/**\brief Indicates what action to preform when this class is switched on: hide, show,
	 *or flicker actors.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus On;

	/**\brief Indicates what action to preform when this class is switched off: hide, show,
	 *or flicker actors.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus Off;

	/**\brief Holds a list of actors to be switch on and off.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<AActor*> ActorsToShowHide;

	/**\brief An array that holds the pattern that will be flickered.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<ActorHideShowStatus> FlickerPattern;

	/**\brief Indicates the time the actor will spend hidden when flickering in and out.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeHidden;

	/**\brief Indicates the time the actor will spend shown when flickering in and out.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeShown;

	/**\brief Indicates the time the actor will spend flickering when flickering in and out.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float TimeFlickering;

	/**\brief Indicates how often the FlickerInAndOut method will be called.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float FlickerRate;

	/**\brief Hides the actors in the ActorsToShowHide array if Show is true, otherwise shows
	 *the actors.
	 *\param Show will hide actors if true, will show if false.
	 */

	void HideActors(bool Show);

	/**\brief Iterates over the FlickerPattern array at a rate based on the FlickerRate variable. */
	void FlickerInAndOut();

	/**\brief Called when the game starts or when spawned, initializes some fields.*/
	virtual void BeginPlay() override;

public:


	/**\brief The action that will be preformed when this switch is switched on,
	 *determined by the "On" variable. */

	virtual void ActionOn() override;

	/**\brief The action that will be preformed when this switch is switched off,
	 *determined by the "Off" variable.
	 */
	virtual void ActionOff() override;

	/**\brief Returns the "Off" variable.
	 *\returns uint8 value of the "Off" variable.
	 */

	virtual uint8 GetActionOff() override;

	/**\brief Returns the "On" variable.
	 *\returns uint8 value of the "On" variable.
	 */

	virtual uint8 GetActionOn() override;

	/**\brief Sets the "On" variable.
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "On" variable.
	 */

	virtual void SetActionOn(uint8 Status) override;

	/**\brief Sets the "Off" variable.
	 *\param Status the GolfGameEnum that will be the new value
	 *of the "Off" variable.
	 */
	virtual void SetActionOff(uint8 Status) override;

};


