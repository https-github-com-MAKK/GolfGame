
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Platform_Assist_Lift.generated.h"

UCLASS()
class GOLFGAME_API APlatform_Assist_Lift : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatform_Assist_Lift();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//for assist lift static mesh only
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//factor for which the platform will move up and down
	UPROPERTY(EditAnywhere)
		float ScaleFactor = 50.0;

};
