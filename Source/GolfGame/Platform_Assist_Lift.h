
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform_Assist_Lift.generated.h"

/**\brief  */

UCLASS()
class GOLFGAME_API APlatform_Assist_Lift : public AActor
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()
	
public:
	
	/**\brief  Sets default values for this actor's properties.*/
	APlatform_Assist_Lift();

	/**\brief  Called every frame and changes the location of the lift based on delta time.*/
	virtual void Tick(float DeltaTime) override;

	/**\brief  For assist lift static mesh only.*/
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//
	/**\brief Factor for which the platform will move in a given direction.*/
	UPROPERTY(EditAnywhere)
		float ScaleFactor = 50.0;

protected:
	
	/**\brief  Called when the game starts or when spawned.*/
	virtual void BeginPlay() override;

};
