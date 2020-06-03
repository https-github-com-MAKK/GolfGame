

#pragma once
#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "GolfGameCharacter.h"
#include "Sound/SoundBase.h"
#include "GolfGameTriggerBox.h"
#include "ChangeDialogueTriggerBox.generated.h"

//Enum visible for use in UE4 editor, allows user to select whether the new dialogue cue is loaded and played
//but the ball or by the player.
UENUM()
enum class ETriggeringActor
{
	TriggeredByBall UMETA(DisplayName = "Ball"),
	TriggeredByPlayer UMETA(DisplayName = "Player")
};

UCLASS()
class GOLFGAME_API AChangeDialogueTriggerBox : public AGolfGameTriggerBox
{
	GENERATED_BODY()

protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Loads and plays dialogue when overlap begins
	virtual void OverlapBeginAction() override;

	//Overlap ends
	virtual void OverlapEndAction() override;

	//Timer for delaying the loading and playing of a new dialogue cue
	FTimerHandle TimerHandle;

	//Amount of time in seconds for the dialogue to be delayed before loading and playing
	UPROPERTY(EditAnywhere, Category = Dialogue)
		float TimeToDelayDialogue;

public:

	AChangeDialogueTriggerBox();

	//new dialogue cue to be loaded to player and played
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class USoundBase* Dialogue;

	//player selected for which to play the dialogue cue for
	UPROPERTY(EditAnywhere, Category = Dialogue)
		class AGolfGameCharacter* PlayerForAudio;

	/*function to play dialogue for player
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	void DialoguePlay();

	
private:

	//set to true when the dialogue is played, only plays once
	bool DialoguePlayed;

};
