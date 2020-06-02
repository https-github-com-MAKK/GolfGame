// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitch.h"



#include "Engine/Engine.h"

ALightSwitch::ALightSwitch()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}
void ALightSwitch::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
}

void ALightSwitch::TurnOffLights()
{
	HideShowLights(false);
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
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("hide/show lights"));
	int num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetActorHiddenInGame(Show);
		}
	}
	AreLightsHidden = Show;
}

void ALightSwitch::ActionOn()
{

	GetMethodToCall(static_cast<uint8>(On));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action on"));

}
void ALightSwitch::ActionOff()
{
	GetMethodToCall(static_cast<uint8>(Off));
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("switch action off"));

}

void ALightSwitch::GetMethodToCall(uint8 Status)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("get method"));
	FTimerHandle TimerHandle;
	LightStatus Stat = static_cast<LightStatus>(Status);
	switch (Stat)
	{
	case LightStatus::LightsTurnOn:
		HideShowLights(false);
		break;
	case LightStatus::LightsTurnOff:
		HideShowLights(true);
		break;
	case LightStatus::LightsFlicker:
		HideShowLights(false); //show lights if they're off
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitch::FlickerLights, FlickerRate, true, 0.0f);
		//FlickerLights();
		break;
	case LightStatus::LightsDim:
		DimLights(Dim);
		break;
	default:
		break;
	}
}

uint8 ALightSwitch::GetActionOff()
{
	return static_cast<uint8>(Off);

}
uint8 ALightSwitch::GetActionOn()
{
	return static_cast<uint8>(On);

}

void ALightSwitch::SetActionOn(uint8 Status)
{
	On = static_cast<LightStatus>(Status);

}
void ALightSwitch::SetActionOff(uint8 Status)
{
	Off = static_cast<LightStatus>(Status);

}
