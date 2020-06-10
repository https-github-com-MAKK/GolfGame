
#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ElevatorPlatform.h"
#include "ElevatorTrigger.generated.h"

/**\brief Class responsible for communicating to the ElevatorPlatform whether the player character is present.*/

UCLASS()
class GOLFGAME_API AElevatorTrigger : public ATriggerBox
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

protected:
	/**\brief Called when the game starts or when spawned.*/
	virtual void BeginPlay() override;

public:
	/**\brief The class constructor. Uses helper macros to enable the trigger box to use the functions OnOverlapBegin and OnOverlapEnd,
	 * which make the box execute certain actions whenever an object overlaps or stops overlapping with the box. 
	 */
	AElevatorTrigger();

	/**\ Called every frame.
	 *\param DeltaTime The elapsed time since the last tick.*/
	virtual void Tick(float DeltaTime) override;

	/**\brief Checks whether the overlapped character is the player character, whether the ElevatorPlatform is active, and then tells the platform to move up.
	*\param OverlappedActor A reference to this trigger box, which is being overlapped.
	\param OtherActor A reference to the actor that overlapped the trigger box.
	*/
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	/**\brief Checks whether the overlapped character is the player character, whether the ElevatorPlatform is active, and then tells the platform to move down.
	*\param OverlappedActor A reference to this trigger box, which is being overlapped.
	\param OtherActor A reference to the actor that overlapped the trigger box.
	*/
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	/**\brief The associated ElevatorPlatform with which the ElevatorTrigger communicates.*/
	UPROPERTY(EditAnywhere)
		class AElevatorPlatform* ElevatorPlatform;
	
};
