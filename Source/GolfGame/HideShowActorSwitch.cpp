/*HideShowActorSwitch.cpp
 *Author: Kaylene Petrin
 *Revision: 1 (05/15/2020)
 *Revision: 2 (05/18/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Pushed code to super class Switch
 *Description: An actor switch that contains an array of actors and preforms an action
 *when turned off or on. The actions that can be preformed include: hide, show, flicker actors,
 *or do nothing. When turned off or on, the array is iterated over and the defined "On" or "Off"
 *action is preformed on all actors in the array.
 */
#include "HideShowActorSwitch.h"
#include "GolfGameEnums.h"
#include "Engine/Engine.h"

void AHideShowActorSwitch::BeginPlay()
{
	Super::BeginPlay();
	LastCalled = 0;
	FirstTimeFlickerCalled = true;
	FlickerIndex = 0;
}

void AHideShowActorSwitch::FlickerInAndOut()
{
	Timer = GetWorld()->GetTimeSeconds() - LastCalled;
	if (FirstTimeFlickerCalled)
	{
		LastCalled = GetWorld()->GetTimeSeconds();
		FirstTimeFlickerCalled = false;
	}
	if (Timer != 0)
	{
		HasBeenIncremented = false;
	}
	if (Timer == CurrentRunTime && GetWorld()->GetTimeSeconds() != 0)
	{
		if (!HasBeenIncremented) {
			IncrementFlickerIndex();
			HasBeenIncremented = true;
			LastCalled = GetWorld()->GetTimeSeconds();
		}
	}

	if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsFlicker)){
			if (AreActorsHidden == true)
			{
				HideActors(false);
				AreActorsHidden = false;
			}
			else
			{
				HideActors(true);
				AreActorsHidden = true;
			}
	}
	else if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsHide))
	{
		HideActors(true);
		AreActorsHidden = true;

	}
	else 
	{
			HideActors(false);
			AreActorsHidden = false;
	}		
}

void AHideShowActorSwitch::IncrementFlickerIndex()
{
	FlickerIndex++;
	if (FlickerIndex == FlickerPattern.Num())    
	{
		FlickerIndex = 0;
	}
	SetCurrentRunTime();
}

void AHideShowActorSwitch::SetCurrentRunTime()
{
	if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsFlicker))
	{
		CurrentRunTime = TimeFlickering;
	}
	else if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsShow))
	{
			CurrentRunTime = TimeShown;
	}
	else if(FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsHide))
	{
		CurrentRunTime = TimeHidden;
	}
}

void AHideShowActorSwitch::HideActors(bool Show)
{
	int num = ActorsToShowHide.Num();
	for (int i = 0; i < num; i++) {

		if (ActorsToShowHide[i] != NULL) {
			ActorsToShowHide[i]->SetActorHiddenInGame(Show);
		}
	}
	AreActorsHidden = Show;
}

void AHideShowActorSwitch::GetMethodToCall(uint8 Status)
{
	FTimerHandle TimerHandle;
	ActorHideShowStatus Stat = static_cast<ActorHideShowStatus>(Status);
	switch (Stat)
	{	
	case ActorHideShowStatus::ActorsShow:
		HideActors(false);
		break;
	case ActorHideShowStatus::ActorsHide:
		HideActors(true);
		break;
	case ActorHideShowStatus::ActorsFlicker:
		HideActors(false); //show lights if they're off
		SetCurrentRunTime();
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AHideShowActorSwitch::FlickerInAndOut, FlickerRate, true, 0.0f);
		break;
	default:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("default"));
		break;
	}
}

void AHideShowActorSwitch::ActionOn()
{
	GetMethodToCall(static_cast<uint8>(On));
}

void AHideShowActorSwitch::ActionOff()
{
	GetMethodToCall(static_cast<uint8>(Off));
}

uint8 AHideShowActorSwitch::GetActionOff()
{
	return static_cast<uint8>(Off);
}

uint8 AHideShowActorSwitch::GetActionOn()
{
	return static_cast<uint8>(On);
}

void AHideShowActorSwitch::SetActionOn(uint8 Status)
{
	On = static_cast<ActorHideShowStatus>(Status);
}

void AHideShowActorSwitch::SetActionOff(uint8 Status)
{
	Off = static_cast<ActorHideShowStatus>(Status);
}
