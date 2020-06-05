
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
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

public:

	/**\brief Sound to be played one time.*/
	UPROPERTY(EditAnywhere, Category = Audio)
		class USoundBase* Sound;

	/**\brief Sound cue is played for player when specific actor enters trigger box*/
	UFUNCTION()
		virtual void OverlapBeginAction() override;

	/**\brief Overlaps of specific actor ends.*/
	UFUNCTION()
		virtual void OverlapEndAction() override;

private:

	//
	/**\brief Set to true when sound has played.*/
	bool HasSoundPlayed = false;
	
};
