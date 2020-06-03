// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "GolfGameTriggerBox.h"
#include "GoalTriggerBox.generated.h"


UCLASS()
class GOLFGAME_API AGoalTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

private:
	//Reference for the in game ball
	ABall* Ball;

protected:

	//Reference to DoorTarget to open or close if necessary
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorTarget;

	//Reference to a door light
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* DoorLight;

	//Reference to a goal light
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* GoalLight;

	//Indicates if the ball is in the goal or not
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsBallInGoal;

	/*Calls super BeginPlay() and casts ActorToCheck to Ball reference
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	virtual void BeginPlay() override;

public:

	/*Disables the ability to teleport and summon the ball when the ball is
	 *overlapping this trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	virtual void OverlapBeginAction() override;

	/*Enables the ability to teleport and summon the ball when the ball is
	 *no longer overlapping this trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void OverlapEndAction() override;

	/*Returns true if the Ball is in the goal trigger box, returns false otherwise.
	 *Parameters:
	 *None
	 *Returns:
	 *bool the value of whether or not the ball is overlapping this trigger box
	 */
	
	bool GetIsBallInGoal();

	/*Returns true if the Ball is in the goal trigger box, returns false otherwise.
	 *Parameters:
	 *None
	 *Returns:
	 *bool the value of whether or not the ball is overlapping this trigger box
	 */

	 /*Sets the value of IsBallInGoal to the value in BallInGoal
	  *Parameters:
	  *bool BallInGoal the new value to set IsBallInGoal to
	  *Returns:
	  *void
	  */
	void SetIsBallInGoal(bool BallInGoal);

};
