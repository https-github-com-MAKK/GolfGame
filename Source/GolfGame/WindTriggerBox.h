#pragma once

#include "TimerManager.h"
#include "CoreMinimal.h"
#include "PlatformGravityTriggerBox.h"
#include "Sound/SoundCue.h"
#include "WindTriggerBox.generated.h"


/**
 * 
 */
UCLASS()
class GOLFGAME_API AWindTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**\brief Handles the delay for the tick*/
	FTimerHandle InputADelayManager;

public:
	/**\brief Function for the timer tick and what happens in it.*/
	virtual void Tick();

	// constructor sets default values for this actor's properties
	AWindTriggerBox();

	/**\brief Function for adding the force the the ball during the tick.*/
	void AddForce(class AActor* OverlappedActor, class AActor* OtherActor);

	/**\brief Function of when the ball enters the box.*/
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	/**\brief Function of when the ball exits the box.*/
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	/**\brief The ball that impact the switch to turn it on or off. Specific ball set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class ABall* Ball;
	
	/**\brief Integer force to be added to the ball when add force is applied.*/
	UPROPERTY(EditAnywhere)
		int force = 1000;

	/**\brief Boolean to tell the trigger box whether or not wind has to be activated or not*/
	UPROPERTY(EditAnywhere)
		bool IsTriggered = false;

	/**\brief Boolean to tell the wind trigger box to turn on or not (can be accessed by a blueprint).*/
	UPROPERTY(BlueprintReadWrite)
		bool IsUsable;



private:

	/**\brief Boolean to tell the wind trigger box on whether or not the wind is currently on.*/
		bool WindOn;

		/**\brief Vector of where the wind should point.*/
		FVector cameraForward;

		/**\brief Handler for the wind tick.*/
		FTimerHandle loopHandle;

		/**\brief Mesh for inherited ball object.*/
		UStaticMeshComponent* meshRootComp;
};
