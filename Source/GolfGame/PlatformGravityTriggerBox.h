
#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "PlatformGravityTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlatformGravityTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// constructor sets default values for this actor's properties
	APlatformGravityTriggerBox();

	//new world gravity upon entering the trigger box
	UPROPERTY(EditAnywhere)
		float GravityInsideTriggerBox = -100.0;

	//new world gravity set when specific actor enter trigger box
	virtual void OverlapBeginAction() override;

	//world gravity returned to original value upon leaving trigger box
	virtual void OverlapEndAction() override;

private:

	//original world gravity stored before overlap
	float OriginalWorldGravity;
	
};
