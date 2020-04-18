#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GrabThrowComponent.generated.h"

class UCameraComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOLFGAME_API UGrabThrowComponent final : public UActorComponent
{

	GENERATED_BODY()


private:
	// Physics handle destination > Visible
	UPROPERTY(EditAnywhere)
		FVector HandleLocation;

	// Type of object that can be picked up
	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> PhysicsObjectType;

	// Actors to ignore
	UPROPERTY(EditAnywhere)
		TArray<AActor*> ActorsToIgnore;

	// Cached reference to the hit component
	UPROPERTY(EditAnywhere)
		UPrimitiveComponent* HitComponent;

	// Grab Sound
	UPROPERTY(EditAnywhere)
		class USoundBase* GrabSound;

	// Grab Sound
	UPROPERTY(EditAnywhere)
		class USoundBase* ThrowSound;

	// Grab Sound
	UPROPERTY(EditAnywhere)
		class USoundBase* ReleaseSound;

private:
	// Check if object being held > Visible
	UPROPERTY(EditAnywhere)
		bool bObjectHeld;

	// Check if physics handle active > Visible
	UPROPERTY(EditAnywhere)
		bool bPhysicsHandleActive;

private:
	// Min distance to allow pickup
	UPROPERTY(EditAnywhere)
		float MinGrabDist = 500.0f;

	// Max distance to allow pickup
	UPROPERTY(EditAnywhere)
		float MaxGrabDist = 1000.0f;

	// Distance between player and pickup > Visible
	UPROPERTY(EditAnywhere)
		float PlayerObjectDist = 1.0f;

	// Throwing force
	UPROPERTY(EditAnywhere)
		float ThrowingForce = 1000.0f;

	// Snap distance
	UPROPERTY(EditAnywhere)
		float SnapDistance = 200.0f;
public:
	// Sets default values for this component's properties
	UGrabThrowComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool Grab(UObject* WorldContextObject, class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent);
	bool Throw(class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent, bool MouseDown);
	bool Release(class UPhysicsHandleComponent* Ph, bool bThrow);

	void TraceHandleLocation(class UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent);

	FORCEINLINE bool GetIsObjectHeld() const { return bObjectHeld; }
};