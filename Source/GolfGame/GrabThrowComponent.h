#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "GrabThrowComponent.generated.h"

class ABall;
class UCameraComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GOLFGAME_API UGrabThrowComponent final : public UActorComponent
{

	GENERATED_BODY()


private:
	// Physics handle destination > Visible
	UPROPERTY(EditAnywhere, Category = "Custom")
		FVector HandleLocation;

	// Type of object that can be picked up
	UPROPERTY(EditAnywhere, Category = "Custom")
		TArray<TEnumAsByte<EObjectTypeQuery>> PhysicsObjectType;

	// Actors to ignore
	UPROPERTY(EditAnywhere, Category = "Custom")
		TArray<AActor*> ActorsToIgnore;

	// Cached reference to the hit component
	UPROPERTY(EditAnywhere, Category = "Custom")
		UPrimitiveComponent* HitComponent;

	// Grab Sound
	UPROPERTY(EditAnywhere, Category = "Custom")
		class USoundBase* GrabSound;

	// Grab Sound
	UPROPERTY(EditAnywhere, Category = "Custom")
		class USoundBase* ThrowSound;

	// Grab Sound
	UPROPERTY(EditAnywhere, Category = "Custom")
		class USoundBase* ReleaseSound;

private:
	// Check if object being held > Visible
	UPROPERTY(EditAnywhere, Category = "Custom")
		bool bObjectHeld;

	// Check if physics handle active > Visible
	UPROPERTY(EditAnywhere, Category = "Custom")
		bool bPhysicsHandleActive;

private:
	// Min distance to allow pickup
	UPROPERTY(EditAnywhere, Category = "Custom")
		float MinGrabDist = 500.0f;

	// Max distance to allow pickup
	UPROPERTY(EditAnywhere, Category = "Custom")
		float MaxGrabDist = 1000.0f;

	// Distance between player and pickup > Visible
	UPROPERTY(EditAnywhere, Category = "Custom")
		float PlayerObjectDist = 1.0f;

	// Throwing force
	UPROPERTY(EditAnywhere, Category = "Custom")
		float ThrowingForce = 2000.0f;

	// Snap distance
	UPROPERTY(EditAnywhere, Category = "Custom")
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
	void TeleportBall (ABall* Ball, FVector TeleportLocation, UPhysicsHandleComponent* Ph);
	FORCEINLINE bool GetIsObjectHeld() const { return bObjectHeld; }
};