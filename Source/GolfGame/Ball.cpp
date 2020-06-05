/*Ball.cpp
 *Author: Andrew Sales
 *Revision: 1 (04/26/2020)
 *Revision: 2 (05/05/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Added getters and setters to the ball to see and set if the ball can
 *currently be teleported or summoned
 *Description: The main ball in the game that the player can pick up, throw, summon,
 *and teleport to
 */
#include "Ball.h"
#include "Components/SphereComponent.h"
#include "ConstructorHelpers.h"

ABall::ABall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereVisual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual Mesh"));
	RootComponent = SphereVisual;
	
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereVisualAsset(TEXT("/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere"));
    if (SphereVisualAsset.Succeeded())
    {
        SphereVisual->SetStaticMesh(SphereVisualAsset.Object);
        SphereVisual->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
        SphereVisual->SetWorldScale3D(FVector(0.8f));
    }

    // Create a particle system that we can activate or deactivate
    SparksParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("MovementParticles"));
    SparksParticleSystem->SetupAttachment(RootComponent);
    SparksParticleSystem->bAutoActivate = true;
    SparksParticleSystem->SetRelativeLocation(FVector(-20.0f, 0.0f, 20.0f));
    static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/StarterContent/Particles/P_Sparks.P_Sparks"));
    if (ParticleAsset.Succeeded())
    {
        SparksParticleSystem->SetTemplate(ParticleAsset.Object);
    }

    CrackleSoundPlayer = CreateDefaultSubobject<UAudioComponent>(TEXT("CrackleSoundComponent"));
    CrackleSoundPlayer->SetupAttachment(RootComponent);

}

void ABall::BeginPlay()
{
	Super::BeginPlay();
	CanBeTeleportedTo = CanTeleportToInBeginning;
	
}

void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABall::GetCanBeTeleportedTo()
{
	return CanBeTeleportedTo;
}

bool ABall::GetCanBallBeSummoned()
{
    return CanBallBeSummoned;
}

void ABall::SetCanBeTeleportedTo(bool CanTeleportTo)
{
	CanBeTeleportedTo = CanTeleportTo;
}

void ABall::SetCanBallBeSummoned(bool CanBeSummoned)
{
    CanBeTeleportedTo = CanBeSummoned;
}

bool ABall::GetHasBeenSummonedOnce()
{
	return CanBeTeleportedTo;
}

void ABall::SetHasBeenSummonedOnce(bool HasSummoned)
{
	CanBeTeleportedTo = HasSummoned;
}

