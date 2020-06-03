
#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "GolfGameCharacter.h"
#include "ChangeTeleportToDialogue.generated.h"

UCLASS()
class GOLFGAME_API AChangeTeleportToDialogue : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:

	AChangeTeleportToDialogue(){};

	//New dialogue cue to be loaded into the player's audio component for dialogue
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;

	UPROPERTY(EditAnywhere)
		AGolfGameCharacter* Player;

	/*Loads new dialogue cue into player when overlap begins
	*Parameters:
	*None
	*Returns:
	*void
	*/
	virtual void OverlapBeginAction() override;

	/*overlap ends
	*Parameters:
	*None
	*Returns:
	*void
	*/
	virtual void OverlapEndAction() override;
};
