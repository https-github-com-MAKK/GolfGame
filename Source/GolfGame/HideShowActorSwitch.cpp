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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("world : %f"), World->GetTimeSeconds()));

	Time = World->GetTimeSeconds() - LastCalled;
	//FlickerTime = World->GetTimeSeconds() - LastCalled;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("time : %d"), Time));

	if (Time % CurrentRunTime==0 && World->GetTimeSeconds() != 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("in if statement")));
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("flickerindex %d"), FlickerIndex));

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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("hide/show Actors"));
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("get method actor %d"), Status));
	FTimerHandle TimerHandle;
	ActorHideShowStatus Stat = static_cast<ActorHideShowStatus>(Status);
	switch (Stat)
	{
		
	case ActorHideShowStatus::ActorsShow:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("show actor"));

		HideOrShowActors(false);
		break;
	case ActorHideShowStatus::ActorsHide:
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("hide actor"));

		HideOrShowActors(true);
		break;
	case ActorHideShowStatus::ActorsFlicker:
		HideOrShowActors(false); //show lights if they're off
		SetCurrentRunTime();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("flicker actor"));
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action on"));

}
void AHideShowActorSwitch::ActionOff()
{

	GetMethodToCall(static_cast<uint8>(Off));
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action off"));

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
