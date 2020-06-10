#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "GolfGameTriggerBox.h"
#include "GoalTriggerBox.generated.h"

/**\brief  A trigger box that indicates if the Ball is in this trigger box or not.
 *\details Goal trigger box that stops the ball from being summoned or teleported
 *to when overlapped, and allows the ball to be summoned or teleported to when the ball
 *stops overlapping this trigger box.
 *
 */
UCLASS()
class GOLFGAME_API AGoalTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:
	/**\brief  Reference for the in game ball.*/
	ABall* Ball;

protected:

	/**\brief  Reference to DoorTarget to open or close if necessary.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorTarget;

	/**\brief  Reference to a door light.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorLight;

	/**\brief  Reference to a goal light.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* GoalLight;

	/**\brief  Indicates if the ball is in the goal or not.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInGoal;

	/**\brief Calls super BeginPlay() and casts ActorToCheck (from super GolfGameTriggerBox) to Ball reference.*/

	virtual void BeginPlay() override;

public:

	/**\brief Disables the ability to teleport and summon the ball when the ball is
	 *no longer overlapping this trigger box.*/
	virtual void OverlapBeginAction() override;

	/**\brief Enables the ability to teleport and summon the ball when the ball is
	 *no longer overlapping this trigger box.
	 */
	
	virtual void OverlapEndAction() override;

	/**\brief Returns true if the Ball is in the goal trigger box, returns false otherwise.
	 *\returns bool the value of whether or not the ball is overlapping this trigger box
	 */
	
	bool GetIsBallInGoal();

	/**\brief Sets the value of IsBallInGoal to the value in BallInGoal
	  *\param BallInGoal the new value to set IsBallInGoal to
	  */
	
	void SetIsBallInGoal(bool BallInGoal);

};
