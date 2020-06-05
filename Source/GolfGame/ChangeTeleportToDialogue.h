
#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "ChangeTeleportToDialogue.generated.h"

UCLASS()
class GOLFGAME_API AChangeTeleportToDialogue : public AGolfGameTriggerBox
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine*/
	GENERATED_BODY()

public:

	//
	/**\brief New dialogue cue to be loaded into the player's audio component for dialogue.*/
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;

	/**\brief Loads new dialogue cue into player when overlap begins.*/
	virtual void OverlapBeginAction() override;

	/**\brief Overlap ends. */
	virtual void OverlapEndAction() override;
};
