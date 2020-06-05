#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "Sound/SoundBase.h"
#include "GolfGameTriggerBox.h"
#include "ChangeDialogueTriggerBox.generated.h"
/**
*\brief When the player begins overlapping the ChangeDialogueTriggerBox, a new
*Sound Base is loaded into the audio component in the GolfGameCharacter and played.
*A delay can be set from the UE4 editor to postpone the playing of the new dialogue
*for a set number of seconds. The Sound Base will only be played once, then the
*DialoguePlayed boolean is set to true.
*/
UCLASS()
class GOLFGAME_API AChangeDialogueTriggerBox : public AGolfGameTriggerBox
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

protected:

	/**\brief Called when the game starts or when spawned.*/
	virtual void BeginPlay() override;

	/**\brief Loads and plays dialogue when overlap begins*/
	virtual void OverlapBeginAction() override;

	/**\brief Overlap ends. Timer is cleared.*/
	virtual void OverlapEndAction() override;

	/**\brief Timer for delaying the loading and playing of a new dialogue cue.*/
	FTimerHandle TimerHandle;

	/**\brief Amount of time in seconds for the dialogue to be delayed before loading and playing.
	 * Amount of time is specified in the UE4 editor.
	 */
	UPROPERTY(EditAnywhere, Category = Dialogue)
		float TimeToDelayDialogue;

public:

	/**\brief Sets DialoguePlayed to false.*/
	AChangeDialogueTriggerBox();

	//
	/**\brief New Sound Base to be loaded to player and player's audio component for dialogue. Sound Base
	 * is selected in the UE4 editor.
	 */
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;

	/**\brief Player selected for which to play the Sound Base for. Player is selected in the UE4 editor.*/
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class AGolfGameCharacter* PlayerForAudio;

	/**\brief Play dialogue for player.*/
	void DialoguePlay();

	
private:

	/**\brief Set to true when the dialogue is played, only plays once.*/
	bool DialoguePlayed;

};
