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

	// Sets default values for this character's properties
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

	//Reference to the in-game ball for picking up, throwing, dropping, summoning, and teleporting to
	UPROPERTY(EditAnywhere, Category = Projectile)
		class ABall* Ball;

	//Audio component attached to the player to play dialogue cues
	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* DialoguePlayer;

	//Audio component attached to the player to play music cues
	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* MusicPlayer;

	//current sound base for music
	UPROPERTY(EditAnywhere)
		class USoundBase* CurrentMusicCue;

	//current dialogue cue for when the ball cannot be summoned
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* CannotSummonBallCue;


protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;

public:	
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(EditAnywhere)
		float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(EditAnywhere)
		float BaseLookUpRate;

	UPROPERTY(EditAnywhere)
		float BaseSpeed;

	UPROPERTY(EditAnywhere)
		float RunningSpeed;

	UPROPERTY(EditAnywhere)
		FVector CameraPosition;

	//current sound cue for when the player cannot be teleported to
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundBase* NeedToTeleportBallCue;


protected:
	/** Handles moving forward/backward */
	void MoveForward(float Value);
	/** Handles movement, left and right */
	void MoveRight(float Value);

	void GrabOrRelease();

	void MouseDown();

	void Walk();

	void Sprint();

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
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

	void Teleport();
	
	void SummonBall();

public:
	//Returns FirstPersonCameraComponent subobject
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	//Plays current dialogue cue for the player in the audio component for dialogue
	void PlayDialogueCue();

	//Plays the current music cue for the player in the audio component for music
	void PlayMusicCue();

	//intended to adjust volume up when dialogue cue has ended, not used
	void AdjustMusicVolumeUp();

	//inteded to adjust volume down when dialogue cue starts, not used
	void AdjustMusicVolumeDown();

	//swaps out old dialogue cue for new cue when overlapping a dialogue change trigger box
	UFUNCTION()
		void ChangeDialogueCue(USoundBase* NewDialogue);

	//swaps out old music cue for new cue when overlapping music cue change trigger box
	UFUNCTION()
		void ChangeMusicCue(USoundBase* NewMusic);

private: 

	//current sound cue for dialogue
	UPROPERTY()
		class USoundBase* CurrentDialogueCue;

};
