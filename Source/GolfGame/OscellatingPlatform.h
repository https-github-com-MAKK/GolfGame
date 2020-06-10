
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OscellatingPlatform.generated.h"

/**\brief Class creates a platform that moves back and forth on the x, y, or z axis. 
 * The associated static mesh, amount of pause time on either end of the path, the length of the path, speed of movement, 
 * initial direction, and axis of movement can all be set inside the Unreal editor.
 */

UCLASS()
class GOLFGAME_API AOscellatingPlatform : public AActor
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()
	
public:	
	/**\brief The constructor of the class, which activates the actor's ability to tick, 
	creates a static mesh, and initializes all variables.
	*/
	AOscellatingPlatform();

protected:
	/**\brief Called when the game starts or when spawned. 
	 * Stores the values of the vector of the original location and calculates the max using those values. 
	 */
	void BeginPlay() override;

public:	
	/**\brief Called every frame.*/
	void Tick(float DeltaTime) override;

	/**\brief Visible mesh representing the actor. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Mesh;

	/**\brief The time that the platform doesn't move when it reaches either end of its path. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		int PauseTime; //Length of time platform pauses at the ends of its path
	
	/**\brief The length of the platform's path. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		float PathHeight; //the length of the platform's path

	/**\brief The speed at which the platform moves. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		float Speed; //speed of platform

	/**\brief The initial direction that the platform will be moving along its path. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		int Direction; //indicates direction of platform movement

	/**\brief the axis along which the platform moves. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		FString Axis; //axis of movement

	/**\brief Whether the platform is currently paused.*/
	bool Paused;

	/**\brief The length of time left for the platform to be paused.*/
	int CurTime;

	/**\brief The values comprising the vector of the platform's original location, and its calculated maximum values.*/
	float MaxX, MaxY, MaxZ, OriginalX, OriginalY, OriginalZ;
};
