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

	void AddForce(class AActor* OverlappedActor, class AActor* OtherActor);

	FTimerHandle InputADelayManager;

public:

	virtual void Tick();

	// constructor sets default values for this actor's properties
	AWindTriggerBox();

	// overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	UPROPERTY(EditAnywhere)
		int force = 1000;

	UPROPERTY(EditAnywhere)
		bool IsTriggered = false;

	UPROPERTY(BlueprintReadWrite)
		bool IsUsable;


	void SetIsUsable(bool choice)
	{
		IsUsable = choice;
	}

	bool GetIsUsable() 
	{
		return IsUsable;
	}

private:
		bool WindOn;


		FVector cameraForward;

		FTimerHandle loopHandle;

		UStaticMeshComponent* meshRootComp;
};
