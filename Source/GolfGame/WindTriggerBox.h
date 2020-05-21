

#pragma once

#include "TimerManager.h"
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "WindTriggerBox.generated.h"


UCLASS()
class GOLFGAME_API AWindTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void AddForce();

	FTimerHandle InputADelayManager;

public:

	virtual void Tick();

	// constructor sets default values for this actor's properties
	AWindTriggerBox();

	// overlap begin function
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;

	UPROPERTY(EditAnywhere)
		int force = 1000;
private:
	bool WindOn;

	FVector cameraForward;

	FTimerHandle loopHandle;

	UStaticMeshComponent* meshRootComp;
};
