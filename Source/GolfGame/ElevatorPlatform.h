#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElevatorTrigger.h"
#include "ElevatorPlatform.generated.h"

/**\brief Class communicates with the ElevatorTrigger trigger box that checks for the presence of the player character and moves up when the character enters the box. 
 *If the character exits the box before it reaches the target height, it moves back down to its original position.
 *The associated static mesh, trigger box, and desired speed of movement and height of path can all be set inside the Unreal editor.
 *
 */

UCLASS()
class GOLFGAME_API AElevatorPlatform : public AActor
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	/**\brief The class's constructor, which activates the actor's tick function,  
	 * sets up the static mesh component, and initializes variables.
	 */
	AElevatorPlatform();

protected:
	// Called when the game starts or when spawned
	/**\brief Called when the game starts or when spawned.
	 *  Stores the Z value from the vector containing the initial location of the platform.
	 */
	virtual void BeginPlay() override;

public:	
	// Called every frame
	/**\ Called every frame. Checks whether the platform should be moving up or down, or if it has reached its target height.
	 *\param DeltaTime The elapsed time since the last tick.
	 */
	virtual void Tick(float DeltaTime) override;

	/**\brief Visible mesh representing the actor. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	/**\brief The trigger box responsible for detecting the presence of the player character and activating the platform's movement accordingly.*/
	UPROPERTY(EditAnywhere)
		class AElevatorTrigger* Trigger;

	/**\brief Determines the speed at which the platform can move.*/
	UPROPERTY(EditAnywhere)
		float Speed;

	/**\brief The target height that the platform can rise to.*/
	UPROPERTY(EditAnywhere)
		float TargetZ;

	/**\brief Boolean values determining whether the elevator is active, whether it should move up or down, and whether it has reached its target height.*/
	bool ElevatorActive, MoveUp, MoveDown, ReachedTarget;
	
	/**\brief The z value obtained from the original location vector of the platform at the start of the game.*/
	float OriginalZ;
};
