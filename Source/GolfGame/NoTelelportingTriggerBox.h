#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "NoTelelportingTriggerBox.generated.h"

UCLASS()
class GOLFGAME_API ANoTelelportingTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()
	
private:
	
	//Reference to the ball in the game
	ABall* Ball;
	
protected:

	/*Calls super BeginPlay() and casts ActorToCheck to Ball reference
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void BeginPlay() override;
public:
	
	/*Disables the ability to teleport to the ball when the ball overlaps this trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void OverlapBeginAction() override;
	
	 /*Enables the ability to teleport to the ball when the ball no longer overlaps this trigger box
	  *Parameters:
	  *None
	  *Returns:
	  *void
	  */
	
	virtual void OverlapEndAction() override;
};
