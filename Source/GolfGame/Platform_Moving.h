
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "GolfGameEnums.h"
#include "Platform_Moving.generated.h"



UCLASS()
class GOLFGAME_API APlatform_Moving : public AActor
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()
	
public:	
	
	/**\brief Sets default values for this actor's properties. Sets up static mesh component.*/
	APlatform_Moving();

	/**\brief sStatic mesh representing the moving platform.*/
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//
	/**\brief Factor for which the platform is to move from its starting location.*/
	UPROPERTY(EditAnywhere)
		float ScaleFactor = 50.0;

	/**\brief Is the platform currently in motion.*/
	bool IsPlatFormMoving = false;

	/**\brief Called every frame. Sets new location of the moving platform based on delta time.*/
	virtual void Tick(float DeltaTime) override;

	/**\brief Direction of movement for the platform from above enum.*/
	UPROPERTY(EditAnywhere)
		EMovementType Movement = EMovementType::UpDown;

	/**\brief Audio component for moving platform, plays sound when platform is moving, not functional.*/
	UPROPERTY(EditAnywhere, Category = Sound)
		class UAudioComponent* PlatformMovingAudio;

	/**\brief Sound played when the platform is in motion.*/
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* MovingSound;
	
protected:

	/**\brief Sets random starting value.*/
	virtual void BeginPlay() override;

private:

	/**\brief Random integer representing the time since creation so that all platforms do not move at the same pace.*/
	int Random;

};
