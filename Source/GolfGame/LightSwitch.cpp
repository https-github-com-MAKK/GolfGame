// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"


#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "GolfGameEnums.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ALightSwitch::ALightSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}

// Called when the game starts or when spawned
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
}

void ALightSwitch::TurnOffLights()
{
	HideShowLights(true);
}

void ALightSwitch::TurnOnLights()
{
	HideShowLights(false);
}

void ALightSwitch::DimLights(float DimVar)
{
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetBrightness(DimVar);
		}
	}
}

void ALightSwitch::FlickerLights()
{
	bool NewBoolean;
	int32 num = Lights.Num();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Flickering lights 2"));
	if (AreLightsDimmed == true) {
		DimLights(FlickerBrighten);
		NewBoolean = false;
	}
	else
	{
		DimLights(FlickerDim);
		NewBoolean = true;
	}
	AreLightsDimmed = NewBoolean;
}

void ALightSwitch::HideShowLights(bool Show)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("hide/show lights"));
	int num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetActorHiddenInGame(Show);
		}
	}
	AreLightsHidden = Show;
}

void ALightSwitch::LightActionOn()
{

	GetMethodToCall(On);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action on"));

}
void ALightSwitch::LightActionOff()
{
	GetMethodToCall(Off);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action off"));

}

void ALightSwitch::GetMethodToCall(TEnumAsByte<LightStatus>  Status)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("get method"));
	FTimerHandle TimerHandle;
	switch(Status)
	{
		case LightsTurnOn:
			HideShowLights(false);
			break;
		case LightsTurnOff:
			HideShowLights(true);
			break;
		case LightsFlicker:
			HideShowLights(false); //show lights if they're off
			GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitch::FlickerLights, FlickerRate, true, 0.0f);
			//FlickerLights();
			break;
		case LightsDim:
			DimLights(Dim);
			break;
		default:
			break;
	}
}

void ALightSwitch::SetLightActionOn(TEnumAsByte<LightStatus> Status)
{
	On = Status;
}
void ALightSwitch::SetLightActionOff(TEnumAsByte<LightStatus>  Status)
{
	Off = Status;
}

TEnumAsByte<LightStatus> ALightSwitch::GetLightActionOn()
{
	return On;
}
TEnumAsByte<LightStatus> ALightSwitch::GetLightActionOff()
{
	return Off;
}