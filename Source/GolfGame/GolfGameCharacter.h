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

	UPROPERTY(EditAnywhere)
		UGrabThrowComponent* GrabberClass;

	//PhysicsHandle class
	UPROPERTY(EditAnywhere)
		UPhysicsHandleComponent* PhysicsHandle;

	
public:
	// Sets default values for this character's properties
	AGolfGameCharacter();

	UPROPERTY(EditAnywhere, Category = "Custom")
		class UGrabThrowComponent* GrabberClass;

	//PhysicsHandle class
	UPROPERTY(EditAnywhere, Category = "Custom")
		class UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY(EditAnywhere, Category = "Custom")
		uint32 bMouseDown : 1;

	UPROPERTY(EditAnywhere, Category = "Custom")
		uint32 bMouseUp : 1;

	UPROPERTY(EditAnywhere, Category = Projectile)
		class ABall* Ball;

	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* DialoguePlayer;

	UPROPERTY(VisibleAnywhere)
		class UAudioComponent* MusicPlayer;

	UPROPERTY(EditAnywhere)
		class USoundBase* CurrentMusicCue;

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

	
	void PlayDialogueCue();
	void PlayMusicCue();
	void AdjustMusicVolumeUp();
	void AdjustMusicVolumeDown();

	UFUNCTION()
		void ChangeDialogueCue(USoundBase* NewDialogue);

	UFUNCTION()
		void ChangeMusicCue(USoundBase* NewMusic);

private: 
	
	UPROPERTY()
		class USoundBase* CurrentDialogueCue;

};
