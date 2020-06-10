/*ElevatorTrigger.cpp
 *Author: Katherine Bozin
 *Description: The trigger responsible for communicating to the ElevatorPlatform whether the player character is present.
 */
#include "ElevatorTrigger.h"
#include "ElevatorPlatform.h"

AElevatorTrigger::AElevatorTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &AElevatorTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AElevatorTrigger::OnOverlapEnd);
}

void AElevatorTrigger::BeginPlay()
{
	Super::BeginPlay();
}

void AElevatorTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AElevatorTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		if (ElevatorPlatform->ElevatorActive) {
			FString ActorName = *OtherActor->GetName();
			if (ActorName.Equals("GolfGameCharacter_1")){
				ElevatorPlatform->MoveUp = true;
				ElevatorPlatform->MoveDown = false;
			}
			
		}
	}
}

void AElevatorTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this)) {
		if (ElevatorPlatform->ElevatorActive) {
			FString ActorName = *OtherActor->GetName();
			if (ActorName.Equals("GolfGameCharacter_1")) {
				ElevatorPlatform->MoveDown = true;
				ElevatorPlatform->MoveUp = false;
			}
		}
	}
}
