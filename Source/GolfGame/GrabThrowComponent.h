#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GrabThrowComponent.generated.h"

/**	*\brief This class is a component of the player character that allows the character to pick up, drop, and throw objects.*/

class ABall;
class UCameraComponent;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GOLFGAME_API UGrabThrowComponent final : public UActorComponent
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()


private:
	/**	*\brief Physics handle destination.*/
	UPROPERTY(EditAnywhere)
		FVector HandleLocation;

	/**\brief Type of object that can be picked up.*/
	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> PhysicsObjectType;

	/**\brief A list of actors to ignore when attempting to grab objects.*/
	UPROPERTY(EditAnywhere)
		TArray<AActor*> ActorsToIgnore;

	/**\brief Cached reference to the hit component.*/
	UPROPERTY(EditAnywhere)
		UPrimitiveComponent* HitComponent;

	/**\brief Sound for when the object is grabbed.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* GrabSound;

	/**\brief Sound for when the object is thrown.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* ThrowSound;

	/**\brief Sound for when the object is released.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* ReleaseSound;

private:
	/**\brief Checks if object is being held.*/
	UPROPERTY(EditAnywhere)
		bool bObjectHeld;

	/**\brief Check if physics handle is active.*/
	UPROPERTY(EditAnywhere)
		bool bPhysicsHandleActive;

private:
	/**\brief Min distance to allow pickup.*/
	UPROPERTY(EditAnywhere)
		float MinGrabDist = 300.0f;

	/**\brief Max distance to allow pickup.*/
	UPROPERTY(EditAnywhere)
		float MaxGrabDist = 1500.0f;

	/**\brief Distance between player and pickup.*/
	UPROPERTY(EditAnywhere)
		float PlayerObjectDist = 1.0f;

	/**\brief The amount of force used to throw the object.*/
	UPROPERTY(EditAnywhere)
		float ThrowingForce = 1500.0f;

	/**	*\brief The distance from the character that an object will snap to when grabbed or summoned.*/
	UPROPERTY(EditAnywhere)
		float SnapDistance = 200.0f;
public:
	/**\brief Sets default values for this component's properties*/
	UGrabThrowComponent();

protected:

	// Called when the game starts
	/**\brief Called when the game starts or when spawned.*/
	virtual void BeginPlay() override;


public:
	// Called every frame
	/**\brief Called every frame.*/
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/**\ Attempts to grab an object of the appropriate type and within the appropriate distance in front of the player character.
	 *\param WorldContextObject A reference to the player character.
	 *\param Ph A reference to the player character's physics handle.
	 *\param FPCameraComponent A reference to the player character's camera component.
	*/
	bool Grab(UObject* WorldContextObject, class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent);

	/**\ Attempts to throw an object held by the player character.
	 *\param Ph A reference to the player character's physics handle.
	 *\param FPCameraComponent A reference to the player character's camera component.
	*/
	bool Throw(class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent);

	/**\ Attempts to relseae an object held by the player character.
	 *\param Ph A reference to the player character's physics handle
	 *\param bThrow a boolean signifying whether a throw has been performed
	*/
	bool Release(class UPhysicsHandleComponent* Ph, bool bThrow);

	/**\ Traces the location of the physics handle related to the position of the player character's camera.
	 *\param Ph A reference to the player character's physics handle.
	 *\param FPCameraComponent A reference to the player character's camera component.
	*/
	void TraceHandleLocation(class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent);

	/**\ Summons the ball to the player and sets the ball to grabbed by the player.
	 *\param Ball the in game ball that the player references.
	 *\param SummonLocation the location that the ball will be summoned to respective to the player
	 *and their grab position.
	 *\param Ph the players physics handle that aids in holding and moving the ball.
	 */
	void SummonGrabBall (ABall* Ball, FVector SummonLocation, UPhysicsHandleComponent* Ph);
	FORCEINLINE bool GetIsObjectHeld() const { return bObjectHeld; }
};