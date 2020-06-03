#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameTriggerBox.generated.h"


UCLASS(Abstract)
class GOLFGAME_API AGolfGameTriggerBox : public ATriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

protected:
	
	//Event for when he game begins to play, draws the debug box if ShowDrawDebugBox is true
	virtual void BeginPlay() override;
	
	//Reference to the Actor that must be set to determine if said Actor is overlapping this class or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* ActorToCheck;
	
	//Sets whether to draw the debug box or not
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GolfGameTriggerBox)
		bool ShowDrawDebugBox=true;

public:

	/*Binds the function OnOverlapBegin to the delegate OnActorBeginOverlap and the function
	 *OnOverlapEnd to the delegate OnActorEndOverlap
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	AGolfGameTriggerBox();
	
	/*Checks to see if the Actor beginning to overlap is the Actor referenced in ActorToCheck
	 *the function to call is handled in the subclass
	 *Parameters:
	 *AActor* OverlappedActor required param in FActorBeginOverlapSignature delegate
	 *AActor* OtherActor the actor that overlaps this trigger box
	 *Returns:
	 *void
	 */
	
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	
	/*Checks to see if the Actor ending the overlap is the Actor referenced in ActorToCheck
	 *the function to call is handled in the subclass
	 *Parameters:
	 *AActor* OverlappedActor required param in FActorBeginOverlapSignature delegate
	 *AActor* OtherActor the actor that has stopped overlapping this trigger box
	 *Returns:
	 *void
	 */
	
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
	/*Virtual function that must be implemented in the subclass, is called when the ActorToCheck overlaps
	 *this trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
		virtual void OverlapEndAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapEndAction,);
	
	/*Virtual function that must be implemented in subclass, is called when the ActorToCheck stops
	 *overlapping this trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
		virtual void OverlapBeginAction() PURE_VIRTUAL(AGolfGameTriggerBox::OverlapBeginAction,);
};
