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

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("time : %d"), Time));

	if (Time % ActorFlickerLoopTime == 0 && World->GetTimeSeconds() != 0)
	{
		LastCalled = World->GetTimeSeconds();

	}

	if (Time < 2 || (Time < 8 && Time >= 7) || (Time < 12 && Time >= 11) || Time <= 15 && Time >= 14)
	{
		for (int i = 0; i < num; i++) {
			if (AreActorsHidden == true)
			{
				ActorsToShowHide[i]->SetActorHiddenInGame(false);
				NewBoolean = false;
			}
			else
			{
				ActorsToShowHide[i]->SetActorHiddenInGame(true);
				NewBoolean = true;

			}
			//SetActorHiddenInGame(false);
		}
	}
	else if (Time == 12 || Time == 13)
	{
		for (int i = 0; i < num; i++) {
			ActorsToShowHide[i]->SetActorHiddenInGame(true);
			NewBoolean = true;
		}

	}
	else
	{
		for (int i = 0; i < num; i++) {
			ActorsToShowHide[i]->SetActorHiddenInGame(false);
			NewBoolean = false;
		}
	}
	AreActorsHidden = NewBoolean;

}
void AHideShowActorSwitch::HideOrShowActors(bool Show)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("hide/show Actors"));
	int num = ActorsToShowHide.Num();
	for (int i = 0; i < num; i++) {
		if (ActorsToShowHide[i] != NULL) {
			ActorsToShowHide[i]->SetActorHiddenInGame(Show);
		}
	}
	AreActorsHidden = Show;
}

void AHideShowActorSwitch::GetMethodToCall(TEnumAsByte<ActorHideShowStatus> Status)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("get method"));
	FTimerHandle TimerHandle;
	switch (Status)
	{
	case ActorsShow:
		HideOrShowActors(false);
		break;
	case ActorsHide:
		HideOrShowActors(true);
		break;
	case ActorsFlicker:
		HideOrShowActors(false); //show lights if they're off
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AHideShowActorSwitch::FlickerInAndOut, FlickerRate, true, 0.0f);
		break;
	default:
		break;
	}
}
void AHideShowActorSwitch::HideShowActionOn()
{

	GetMethodToCall(On);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action on"));

}
void AHideShowActorSwitch::HideShowActionOff()
{
	GetMethodToCall(Off);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action off"));

}
void AHideShowActorSwitch::SetActorActionOn(TEnumAsByte<ActorHideShowStatus>  Status)
{
	On = Status;
}
void AHideShowActorSwitch::SetActorActionOff(TEnumAsByte<ActorHideShowStatus>   Status)
{
	Off = Status;
}

TEnumAsByte<ActorHideShowStatus> AHideShowActorSwitch::GetActorActionOn()
{
	return On;
}
TEnumAsByte<ActorHideShowStatus> AHideShowActorSwitch::GetActorActionOff()
{
	return Off;
}