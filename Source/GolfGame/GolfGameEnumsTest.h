#pragma once

UENUM()
enum class LightStatusTest : uint8
{
	LightsDoNothing  UMETA(DisplayName = "DoNothing"),
	LightsTurnOn    UMETA(DisplayName = "TurnOnLights"),
	LightsTurnOff    UMETA(DisplayName = "TurnOffLights"),
	LightsFlicker   UMETA(DisplayName = "FlickerLights"),
	LightsDim  UMETA(DisplayName = "DimLights")
};

UENUM()
enum class ActorHideShowStatusTest : uint8
{
	ActorsDoNothing  UMETA(DisplayName = "DoNothing"),
	ActorsShow   UMETA(DisplayName = "ShowActors"),
	ActorsHide   UMETA(DisplayName = "HideActors"),
	ActorsFlicker   UMETA(DisplayName = "FlickerActors"),
};