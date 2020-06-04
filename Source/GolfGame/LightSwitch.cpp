/*HideShowActorSwitch.cpp
 *Author: Kaylene Petrin
 *Revision: 1 (05/15/2020)
 *Revision: 2 (05/18/2020)
 *Rev. Author: Kaylene Petrin
 *Rev. Comments: Pushed code to super class Switch
 *Description: A light switch that contains an array of lights and preforms an action
 *when turned off or on. The actions that can be preformed include: hide, show, flicker, dim lights,
 *or do nothing. When turned off or on, the array is iterated over and the defined "On" or "Off"
 *action is preformed on all lights in the array.
 */
#include "LightSwitch.h"
#include "Engine/Engine.h"


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

	if (AreLightsDimmed == true) {
		DimLights(FlickerBrighten);
		AreLightsDimmed = false;
	}
	else
	{
		DimLights(FlickerDim);
		AreLightsDimmed = true;
	}
	
}

void ALightSwitch::HideLights(bool Show)
{
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
}

void ALightSwitch::ActionOff()
{
	GetMethodToCall(static_cast<uint8>(Off));
}

void ALightSwitch::GetMethodToCall(uint8 Status)
{
	FTimerHandle TimerHandle;
	LightStatus Stat = static_cast<LightStatus>(Status);
	switch (Stat)
	{
	case LightStatus::LightsTurnOn:
		HideLights(false);
		break;
	case LightStatus::LightsTurnOff:
		HideLights(true);
		break;
	case LightStatus::LightsFlicker:
		HideLights(false); //show lights if they're off
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitch::FlickerLights, FlickerRate, true, 0.0f);
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
