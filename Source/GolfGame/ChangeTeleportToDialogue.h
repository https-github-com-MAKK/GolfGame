
#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "GolfGameCharacter.h"
#include "ChangeTeleportToDialogue.generated.h"

/**\brief Loads in new dialogue cue for when the player cannot teleport to the ball.*/

UCLASS()
class GOLFGAME_API AChangeTeleportToDialogue : public AGolfGameTriggerBox
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine*/
	GENERATED_BODY()

public:

	/**\brief New dialogue cue to be loaded into the player's audio component for dialogue.*/
	UPROPERTY(EditAnywhere, Category = Audio)
		class USoundBase* Dialogue;

	UPROPERTY(EditAnywhere)
		class AGolfGameCharacter* Player;
	
	/**\brief Loads new dialogue cue into player when overlap begins.*/
	virtual void OverlapBeginAction() override;

	/**\brief Overlap ends. */
	virtual void OverlapEndAction() override;
};
