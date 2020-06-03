
#pragma once

#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "PlayOnceSoundTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API APlayOnceSoundTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

public:

	//Sound to be played one time
	UPROPERTY(EditAnywhere, Category = Audio)
		class USoundBase* Sound;

	//sound cue is played for player when specific actor enters trigger box
	UFUNCTION()
		virtual void OverlapBeginAction() override;
		virtual void OverlapEndAction() override;

private:

	//has the sound played once
	bool HasSoundPlayed = false;
	
};
