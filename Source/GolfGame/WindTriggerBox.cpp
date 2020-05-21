
#include "WindTriggerBox.h"
#include "PlatformGravityTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include <Ball.h>
#include "GameFramework/WorldSettings.h"
#include "GameFramework/Pawn.h"


AWindTriggerBox::AWindTriggerBox()
{

}

void AWindTriggerBox::BeginPlay() 
{
	Super::BeginPlay();

}

void AWindTriggerBox::OverlapBeginAction()
{
	 cameraForward = GetActorForwardVector();
	 if (WindOn == false)
	 {
		 AddForce();
	 }
}

void AWindTriggerBox::AddForce()
{
	

	WindOn = true;
	ABall * Ball =  dynamic_cast<ABall*>(ActorToCheck);
	meshRootComp = Cast<UStaticMeshComponent>(Ball->GetRootComponent());
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ForceAdded"));

	GetWorld()->GetTimerManager().SetTimer(InputADelayManager, this, &AWindTriggerBox::Tick, .1F, true);

}

void AWindTriggerBox::Tick()
{
	meshRootComp->AddForce(cameraForward * force * meshRootComp->GetMass());	
}

void AWindTriggerBox::OverlapEndAction()
{
	if (GetWorld()->GetTimerManager().IsTimerActive(InputADelayManager)) 
	{
		GetWorld()->GetTimerManager().ClearTimer(InputADelayManager);
		GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, TEXT("ForceStopped"));

	}
}
