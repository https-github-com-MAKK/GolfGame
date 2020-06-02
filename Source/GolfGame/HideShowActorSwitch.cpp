// Fill out your copyright notice in the Description page of Project Settings.


#include "HideShowActorSwitch.h"
#include "GolfGameEnums.h"
#include "Engine/Engine.h"

// Sets default values
AHideShowActorSwitch::AHideShowActorSwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void AHideShowActorSwitch::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	LastCalled = 0;
	
}

// Called every frame
void AHideShowActorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AHideShowActorSwitch::FlickerInAndOut()
{

	bool NewBoolean;
	int32 num = ActorsToShowHide.Num();

	Time = World->GetTimeSeconds() - LastCalled;
	//FlickerTime = World->GetTimeSeconds() - LastCalled;

	if (Time % CurrentRunTime==0 && World->GetTimeSeconds() != 0)
	{
		LastCalled = World->GetTimeSeconds();
		IncrementFlickerIndex();
	}
	
	if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsFlicker)){	
			if (AreActorsHidden == true)
			{
				HideOrShowActors(false);
				NewBoolean = false;
			}
			else
			{
				HideOrShowActors(true);
				NewBoolean = true;
			}
	}
	else if (FlickerPattern[FlickerIndex] == (ActorHideShowStatus::ActorsHide))
	{
		HideOrShowActors(true);
		NewBoolean = true;	

	}
	else 
	{
			HideOrShowActors(false);
			NewBoolean = false;
	}
	AreActorsHidden = NewBoolean;
		
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
void AHideShowActorSwitch::HideOrShowActors(bool Show)
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
		HideOrShowActors(false);
		break;
	case ActorHideShowStatus::ActorsHide:
		HideOrShowActors(true);
		break;
	case ActorHideShowStatus::ActorsFlicker:
		HideOrShowActors(false); //show lights if they're off
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
