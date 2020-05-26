#include "GolfGameCharacter.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/InputSettings.h"
#include "Ball.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values
AGolfGameCharacter::AGolfGameCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	BaseSpeed = 700.0f; 
	RunningSpeed = 1200.0f;
	Walk();

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	CameraPosition = FVector(-39.56f, 1.75f, 64.f);
	//CameraPosition = FVector(50.f, 5.f, 100.f);
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(CameraPosition); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	GrabberClass = CreateDefaultSubobject<UGrabThrowComponent>(TEXT("GrabberClass"));
	BallSummonLocation = CreateDefaultSubobject<USphereComponent>(TEXT("Ball Teleportation Position"));
	BallSummonLocation->SetupAttachment(GetCapsuleComponent());
	BallSummonLocation->SetRelativeLocation(FVector(150.0f, 1.75f, 44.f));

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("PhysicsHandle"));

	DialoguePlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("Dialogue Player"));
	DialoguePlayer->SetAutoActivate(false);
	
	MusicPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("Music Player"));
	
}

// Called when the game starts or when spawned
void AGolfGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGolfGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GrabberClass != nullptr)
	{
		GrabberClass->TraceHandleLocation(PhysicsHandle, FirstPersonCameraComponent);
	}

}

// Called to bind functionality to input
void AGolfGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	check(PlayerInputComponent);

	// Bind jump events
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// Ball interaction events
	PlayerInputComponent->BindAction("Grab", IE_Released, this, &AGolfGameCharacter::GrabOrRelease);
	PlayerInputComponent->BindAction("MouseDown", IE_Released, this, &AGolfGameCharacter::MouseDown);

	PlayerInputComponent->BindAction("Teleport", IE_Pressed, this, &AGolfGameCharacter::Teleport);
	PlayerInputComponent->BindAction("SummonBall", IE_Released, this, &AGolfGameCharacter::SummonBall);

	
	// Bind movement events
	PlayerInputComponent->BindAxis("MoveForward", this, &AGolfGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGolfGameCharacter::MoveRight);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AGolfGameCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released , this, &AGolfGameCharacter::Walk);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AGolfGameCharacter::LookUpAtRate);

}

void AGolfGameCharacter::GrabOrRelease()
{
	if (GrabberClass != nullptr)
	{
		switch (GrabberClass->GetIsObjectHeld())
		{
		case true:
			if (PhysicsHandle != nullptr) GrabberClass->Release(PhysicsHandle, false);
			break;

		case false:
			if (PhysicsHandle != nullptr && FirstPersonCameraComponent != nullptr) 
				GrabberClass->Grab(this, PhysicsHandle, FirstPersonCameraComponent);
			break;
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("grab or release"));

}

void AGolfGameCharacter::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
}

void AGolfGameCharacter::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}


void AGolfGameCharacter::MouseDown()
{
	if (GrabberClass != nullptr && PhysicsHandle != nullptr && FirstPersonCameraComponent != nullptr && GrabberClass->GetIsObjectHeld())
		GrabberClass->Throw(PhysicsHandle, FirstPersonCameraComponent);
}

void AGolfGameCharacter::MoveForward(const float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AGolfGameCharacter::MoveRight(const float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AGolfGameCharacter::TurnAtRate(const float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AGolfGameCharacter::LookUpAtRate(const float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AGolfGameCharacter::Teleport()
{
	if (Ball != nullptr && Ball->GetCanBeTeleportedTo() && Ball->GetHasBeenSummonedOnce()) {
		FVector ballLocation = Ball->GetActorLocation();
		SetActorLocation(ballLocation, false);
	}
	else
	{
		if(NeedToTeleportBallCue != nullptr)
		{
			DialoguePlayer->SetSound(NeedToTeleportBallCue);
			DialoguePlayer->Play();
		}
	}

}

void AGolfGameCharacter::SummonBall()
{
	
	if (Ball != nullptr) {
		GrabberClass->TeleportBall(Ball, BallSummonLocation->GetComponentLocation(), PhysicsHandle);
		Ball->SetHasBeenSummonedOnce(true);
	}

	if(!Ball->GetCanBallBeSummoned())
	{
		if(CannotSummonBallCue != nullptr)
		{
			DialoguePlayer->SetSound(CannotSummonBallCue);
			DialoguePlayer->Play();
		}
	}
	
}

void AGolfGameCharacter::PlayDialogueCue()
{
	DialoguePlayer->Play();
}

void AGolfGameCharacter::PlayMusicCue()
{
	MusicPlayer->Play();
}

void AGolfGameCharacter::AdjustMusicVolumeUp()
{
	MusicPlayer->AdjustVolume(1, 1, EAudioFaderCurve::Linear);
}

void AGolfGameCharacter::AdjustMusicVolumeDown()
{
	MusicPlayer->AdjustVolume(1, 0, EAudioFaderCurve::Linear);
}

void AGolfGameCharacter::ChangeDialogueCue(USoundBase* NewDialogue)
{
	if(NewDialogue != nullptr)
	{
		CurrentDialogueCue = NewDialogue;
		DialoguePlayer->SetSound(CurrentDialogueCue);
		PlayDialogueCue();
	}
}

void AGolfGameCharacter::ChangeMusicCue(USoundBase* NewMusic)
{
	if (NewMusic != nullptr)
	{
		CurrentDialogueCue = NewMusic;
		MusicPlayer->SetSound(CurrentDialogueCue);
		PlayMusicCue();
	}
}
