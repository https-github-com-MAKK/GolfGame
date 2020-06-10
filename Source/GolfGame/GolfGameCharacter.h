#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Character.h"
#include "GrabThrowComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "GolfGameCharacter.generated.h"

/**\brief GolfGameCharacter houses all functionality for a user to operate a player in-game.
 *\detail GolfGameCharacter encapsulates a camera component for the player to view the game
 * from, a GrabThrow component to interact with the ball (pick up, drop, and throw), audio
 * components for playing in-game music and dialogue cues, the ability to summon the ball
 * and teleport to it, as well as necessary components for in-game operations.
 */

class UInputComponent;
UCLASS(config=Game)
class AGolfGameCharacter final : public ACharacter
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

public:

	/**\brief Sets default values for this character's properties*/
	AGolfGameCharacter();
	
	/**\brief First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	/**\brief Grabber class*/
	UPROPERTY(EditAnywhere, Category = "Custom")
		class UGrabThrowComponent* GrabberClass;

	/**\brief PhysicsHandle class*/
	UPROPERTY(EditAnywhere, Category = "Custom")
		class UPhysicsHandleComponent* PhysicsHandle;
	
	/**\brief The location to which the ball should be summoned. */
	UPROPERTY(EditAnywhere, Category = "Custom")
		class USphereComponent* BallSummonLocation;

	/**\brief Reference to the in-game ball for picking up, throwing, dropping, summoning, and teleporting to.*/
	UPROPERTY(EditAnywhere, Category = Projectile)
		class ABall* Ball;

	/**\brief Audio component attached to the player to play dialogue cues.*/
	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* DialoguePlayer;

	/**\brief Audio component attached to the player to play music cues.*/
	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* MusicPlayer;

	/**\brief Current sound base for music.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* CurrentMusicCue;

	/**\brief Current dialogue cue for when the ball cannot be summoned.*/
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* CannotSummonBallCue;


protected:
	/**\brief Called when the game starts or when spawned*/
	void BeginPlay() override;

public:	
	/**\brief Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere)
		float BaseTurnRate;

	/**\brief Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere)
		float BaseLookUpRate;

	/**\brief The regular walking speed of the character. */
	UPROPERTY(EditAnywhere)
		float BaseSpeed;

	/**\brief The running speed of the character. */
	UPROPERTY(EditAnywhere)
		float RunningSpeed;

	/**\brief The position of the camera relative to the golf game character. */
	UPROPERTY(EditAnywhere)
		FVector CameraPosition;

	/**\brief Current sound cue for when the player cannot be teleported to the ball. Selected in UE4 editor.*/
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* NeedToTeleportBallCue;

	/**\brief Current sound cue for when the player is teleported to the ball. Selected in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* TeleportSound;

	/**\brief Current sound cue for when the player summons the ball. Selected in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class USoundBase* SummonSound;


protected:
	/**\ Moves the character forward or backward. 
	*\param Value The value used for determining the rate at which the character moves.
	*/
	void MoveForward(float Value);

	/**\brief Moves the character to the left or the right. 
	*\param Value The value used for determining the rate at which the character moves.
	*/
	void MoveRight(float Value);

	/**\brief Based on whether the character is currently holding an object, this method tries to either pick up an object in front of the character or drop the one currently being held.*/
	void GrabOrRelease();

	/**\brief If the character is holding an object, this method tries to throw the object in the direction the character is facing. */
	void MouseDown();

	/**\brief Toggles the character's movement speed to the base walking speed. */
	void Walk();

	/**\brief Toggles the character's moving speed to the running speed. */
	void Sprint();

	/**\brief Called via input to turn at a given rate.
	 * \param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**\brief Called via input to turn look up/down at a given rate.
	 * \param Rate This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct FTouchData
	{
		FTouchData() { bIsPressed = false;  bMoved = false; FingerIndex = ETouchIndex::Touch1; Location = FVector::ZeroVector; }
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	
	//static void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	FTouchData	TouchItem;

	// APawn interface
	/**\ Called every frame.
	 *\param DeltaTime The elapsed time since the last tick.*/
	void Tick(float DeltaTime) override;
	
	/**\ Sets up the inputs usable by the character.
	*\param PlayerInputComponent The component belonging to the player character that allows the use of inputs.*/
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/**\brief Attempts to set the player's location to the ball's location.*/
	void Teleport();

	/**\brief Attempts to set the ball's location to the player's location and has the player hold the ball if successful.*/
	void SummonBall();

public:
	/**\brief Returns FirstPersonCameraComponent subobject*/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/**\brief current dialogue cue for the player in the audio component for dialogue*/
	void PlayDialogueCue();

	/**\brief Plays the current music cue for the player in the audio component for music.*/
	void PlayMusicCue();

	/**\brief Adjusts volume up when dialogue cue ends, not used.*/
	void AdjustMusicVolumeUp();

	/**\brief Adjusts volume down when dialogue cue starts, not used.*/
	void AdjustMusicVolumeDown();

	//**\brief Swaps out old dialogue cue for new cue when overlapping a dialogue change trigger box.*/
	UFUNCTION()
		void ChangeDialogueCue(USoundBase* NewDialogue);

	/**\brief Swaps out old music cue for new cue when overlapping music cue change trigger box.*/
	UFUNCTION()
		void ChangeMusicCue(USoundBase* NewMusic);

private: 

	/**\brief Current sound cue for dialogue.*/
	UPROPERTY()
		class USoundBase* CurrentDialogueCue;

};
