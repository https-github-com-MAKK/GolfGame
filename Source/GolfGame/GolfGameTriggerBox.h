#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameTriggerBox.generated.h"
/**\brief Abstract trigger box that calls a method when a specific actor
*begins or stops overlapping this trigger box.*/

UCLASS(Abstract)
class GOLFGAME_API AGolfGameTriggerBox : public ATriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

protected:
	
	/**\brief Reference to the Actor that must be set to determine if said Actor is overlapping this class or not.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* ActorToCheck;

public:

	/**\brief Binds the function OnOverlapBegin to the delegate OnActorBeginOverlap and the function
	 *OnOverlapEnd to the delegate OnActorEndOverlap.
	 */
	
	AGolfGameTriggerBox();
	
	/**\brief Checks to see if the Actor beginning to overlap is the Actor referenced in ActorToCheck
	 *the function to call is handled in the subclass.
	 *\param OverlappedActor required param in FActorBeginOverlapSignature delegate.
	 *\param OtherActor the actor that overlaps this trigger box.
	 */
	
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	/**\brief Checks to see if the Actor ending the overlap is the Actor referenced in ActorToCheck
	 *the function to call is handled in the subclass
	 *\param OverlappedActor required param in FActorBeginOverlapSignature delegate.
	 *\param OtherActor the actor that has stopped overlapping this trigger box.
	 */
	
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
	/**\brief Virtual function that must be implemented in the subclass, is called when the ActorToCheck overlaps
	 *this trigger box.
	 */
	
		virtual void OverlapEndAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapEndAction,);
	
	 /**\brief Virtual function that must be implemented in subclass, is called when the ActorToCheck stops
	 *overlapping this trigger box.
	 */
		virtual void OverlapBeginAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapBeginAction,);
};
