// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PhysicsVolume.h"
#include "PlatformPhysicsVolume.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlatformPhysicsVolume : public APhysicsVolume
{
	GENERATED_BODY()

private:

	const float OriginalTerminalVelocity = 4000;
	
protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	
		APlatformPhysicsVolume();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	// specific actor for overlap
	UPROPERTY(EditAnywhere)
		class AActor* SpecificActor;

	//alter terminal velocity for ball actor while inside the volume
	UPROPERTY(EditAnywhere)
		float Gravity;
};
