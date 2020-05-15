#pragma once
UENUM()
enum LightStatus
{
	LightsDoNothing  UMETA(DisplayName = "DoNothing"),
	LightsTurnOn    UMETA(DisplayName = "TurnOnLights"),
	LightsTurnOff    UMETA(DisplayName = "TurnOffLights"),
	LightsFlicker   UMETA(DisplayName = "FlickerLights"),
	LightsDim  UMETA(DisplayName = "DimLights")
};

UENUM()
enum ActorHideShowStatus
{
	ActorsDoNothing  UMETA(DisplayName = "DoNothing"),
	ActorsShow   UMETA(DisplayName = "ShowActors"),
	ActorsHide   UMETA(DisplayName = "HideActors"),
	ActorsFlicker   UMETA(DisplayName = "FlickerActors"),
};