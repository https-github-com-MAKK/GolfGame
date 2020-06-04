#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "NoTelelportingTriggerBox.generated.h"
/**\brief Disables the player from teleporting to the in game ball when it is in this trigger box.
 *\details Trigger box that prevents the player from teleporting to the area this trigger box
 *covers when the ball is overlapping this trigger box. Enables teleportation when the ball is no
 *longer overlapping.
*/
UCLASS()
class GOLFGAME_API ANoTelelportingTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()
	
private:
	
	/**\brief Reference to the ball in the game*/
	ABall* Ball;
	
protected:

	/**\brief Calls super BeginPlay() and casts ActorToCheck (from super GolfGameTriggerBox)
	 *to Ball reference.
	 */
	
	virtual void BeginPlay() override;
	
public:
	
	/**\brief Disables the ability to teleport to the ball when the ball overlaps this trigger box.
	 */
	
	virtual void OverlapBeginAction() override;
	
	/**\brief Enables the ability to teleport to the ball when the ball no longer overlaps this trigger box.
	  */
	
	virtual void OverlapEndAction() override;
};
