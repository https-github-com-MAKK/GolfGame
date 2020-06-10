/*WindTriggerBox.ccp
 *Author: Max Iniguex
 *Revision: 1 (04/20/2020)
 *Description: A trigger box that once the ball enteres the overlap area, a force is added directly to the ball every .1 seconds
 *resulting in a wind like mechanic
 */
#include "WindTriggerBox.h"
#include "PlatformGravityTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Sound/SoundCue.h"
#include <Ball.h>
#include "GameFramework/WorldSettings.h"
#include "GameFramework/Pawn.h"
#include "Components/BoxComponent.h"
#include "Sound/AmbientSound.h"


AWindTriggerBox::AWindTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AWindTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AWindTriggerBox::OnOverlapEnd);
}

void AWindTriggerBox::BeginPlay() 
{
	//if (WindCue!=nullptr) { WindCueComponent->SetSound(WindCue); }
	IsUsable = false;
	Super::BeginPlay();

}

void AWindTriggerBox::OnOverlapBegin(class AActor* OverlappedActor,  class AActor* OtherActor) 
{

	 cameraForward = GetActorForwardVector();
	 if (OtherActor && OtherActor != this && OtherActor == Ball && !WindOn && ((IsTriggered && IsUsable) || (!IsTriggered && !IsUsable)))
	 {
		 AddForce(OverlappedActor, OtherActor);
	 }

}

void AWindTriggerBox::AddForce( class AActor* OverlappedActor, class AActor* OtherActor)
{
	//if (WindCueComponent!=nullptr) { WindCueComponent->Play(); }
	WindOn = true;
	meshRootComp = Cast<UStaticMeshComponent>(OtherActor->GetRootComponent());
	UE_LOG(LogTemp, Log, TEXT("Force added against actor"));

	GetWorld()->GetTimerManager().SetTimer(InputADelayManager, this, &AWindTriggerBox::Tick, .1F, true);

}

void AWindTriggerBox::Tick()
{

	meshRootComp->AddForce(cameraForward * force * meshRootComp->GetMass());
	
}

void AWindTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (GetWorld()->GetTimerManager().IsTimerActive(InputADelayManager)) 
	{
		GetWorld()->GetTimerManager().ClearTimer(InputADelayManager);
		WindOn = false;
		UE_LOG(LogTemp, Log, TEXT("Force stopped against actor"));

	}
}
