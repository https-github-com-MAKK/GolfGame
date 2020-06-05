
#pragma once

#include "CoreMinimal.h"
#include "Ball.h"
#include "GolfGameTriggerBox.h"
#include "PlatformGravityTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlatformGravityTriggerBox : public AGolfGameTriggerBox
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

protected:

	// 
	/**\brief Called when the game starts or when spawned. Stored world gravity in OriginalWorldGravity.*/
	virtual void BeginPlay() override;

public:

	/**\brief New world gravity upon entering the trigger box.*/
	UPROPERTY(EditAnywhere)
		float GravityInsideTriggerBox;

	/**\brief New world gravity set when specific actor enter trigger box.*/
	virtual void OverlapBeginAction() override;

	/**\brief World gravity returned to original value upon leaving trigger box.*/
	virtual void OverlapEndAction() override;

private:

	/**\brief Original world gravity stored before overlap.*/
	float OriginalWorldGravity;
	
};
