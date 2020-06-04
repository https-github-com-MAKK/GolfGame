
#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "ChangeTeleportToDialogue.generated.h"

UCLASS()
class GOLFGAME_API AChangeTeleportToDialogue : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:

	//New dialogue cue to be loaded into the player's audio component for dialogue
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;

	//Loads new dialogue cue into player when overlap begins
	virtual void OverlapBeginAction() override;

	//overlap ends
	virtual void OverlapEndAction() override;
};
