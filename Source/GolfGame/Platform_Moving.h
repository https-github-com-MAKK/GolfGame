
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Platform_Moving.generated.h"

//Enum visible in UE4 editor representing the direction the platform is to move
UENUM()
enum class EMovementType
{
	UpDown UMETA(DisplayName = "Up and Down"),
	LeftRight UMETA(DisplayName = "Left and Right"),
	ForwardBack UMETA(DisplayName = "Forward and Backwards")
};

UCLASS()
class GOLFGAME_API APlatform_Moving : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatform_Moving();

	//static mesh representing the moving platform
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//factor for which the platform is to move from its starting location
	UPROPERTY(EditAnywhere)
		float ScaleFactor = 50.0;

	//Is the platform currently in motion
	bool IsPlatFormMoving = false;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//type of movement for the platform from above enum
	UPROPERTY(EditAnywhere)
		EMovementType Movement = EMovementType::UpDown;

	//audio component for moving platform, plays sound when platform is moving, not used
	UPROPERTY(EditAnywhere, Category = Sound)
		class UAudioComponent* PlatformMovingAudio;

	//sound played when the platform is in motion
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* MovingSound;
	
protected:
	
	virtual void BeginPlay() override;

private:

	//Random integer representing the time since creation so that all platforms do not move
	//at the same pace
	int Random;

};
