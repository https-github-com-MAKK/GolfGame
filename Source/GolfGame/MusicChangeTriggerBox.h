

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "GolfGameTriggerBox.h"
#include "MusicChangeTriggerBox.generated.h"

/**\brief When a specific actor begins to overlap MusicChangeTriggerBox, a selected Sound Base is
 *loaded into the audio component for music in the GolfGameCharacter and played.
 */
UCLASS()
class GOLFGAME_API AMusicChangeTriggerBox : public AGolfGameTriggerBox
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

protected:
	
	/**\brief Called when the game starts or when spawned.*/
	virtual void BeginPlay() override;

public:

	/**\brief Stock constructor.*/
	AMusicChangeTriggerBox();

	/**\brief Sound base for current music cue. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere, Category = Music)
		class USoundBase* Music;

	/**\brief Reference to the player so that the new music cue can be loaded into the audio component for music.
	 * Set in UE4 editor.
	 */
	UPROPERTY(EditAnywhere, Category = Music)
		class AGolfGameCharacter* PlayerForAudio;

	/**\brief Upon beginning the overlap, the new music cue is loaded to the player and is played.*/
	UFUNCTION()
		virtual void OverlapBeginAction() override;

	/**\brief Trigger box overlap end.*/
	UFUNCTION()
		virtual void OverlapEndAction() override;

private:

	/**\brief Represents whether the music cue has already been loaded and played*/
	bool MusicStarted = false;
	
};
