#pragma once
#include "CoreMinimal.h"
#include "Ball.h"
#include "GameFramework/Character.h"
#include "GrabThrowComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundBase.h"
#include "Components/ShapeComponent.h"
#include "GolfGameCharacter.generated.h"


class UInputComponent;
UCLASS(config=Game)
class AGolfGameCharacter final : public ACharacter
{
	GENERATED_BODY()

public:

	/**\brief Sets default values for this character's properties*/
	AGolfGameCharacter();
	
	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FirstPersonCameraComponent;

	//Grabber class
	UPROPERTY(EditAnywhere, Category = "Custom")
		class UGrabThrowComponent* GrabberClass;

	//PhysicsHandle class
	UPROPERTY(EditAnywhere, Category = "Custom")
		class UPhysicsHandleComponent* PhysicsHandle;
	
	UPROPERTY(EditAnywhere, Category = "Custom")
		class USphereComponent* BallSummonLocation;

	UPROPERTY(EditAnywhere, Category = "Custom")
		uint32 bMouseDown : 1;

	UPROPERTY(EditAnywhere, Category = "Custom")
		uint32 bMouseUp : 1;

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

	UPROPERTY(EditAnywhere)
		float BaseSpeed;

	UPROPERTY(EditAnywhere)
		float RunningSpeed;

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


	void MoveForward(float Value);


	void MoveRight(float Value);

	void GrabOrRelease();

	void MouseDown();

	void Walk();

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
	void Tick(float DeltaTime) override;
	
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	/**\brief Attempts to set the player's location to the ball's location.
	 */
	
	void Teleport();

	/**\brief Attempts to set the ball's location to the player's location and has the player hold the ball
	 *if successful.
	 */
	
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
