/**\brief Enum class, used in various other classes.
 *Authors: Andrew Sales, Kaylene Petrin
 */

#pragma once

/**\brief Enumerators for the Light status: On, Off, Flicker, Dim, or Do nothing */
UENUM()
enum class LightStatus: uint8
{
	LightsTurnOn    UMETA(DisplayName = "TurnOnLights"),
	LightsTurnOff    UMETA(DisplayName = "TurnOffLights"),
	LightsFlicker   UMETA(DisplayName = "FlickerLights"),
	LightsDim  UMETA(DisplayName = "DimLights"),
	LightsDoNothing  UMETA(DisplayName = "DoNothing")
};


/**\brief Enumerators for the Actor status: On, Off, Flicker, or Do nothing*/
UENUM()
enum class ActorHideShowStatus: uint8
{
	ActorsShow   UMETA(DisplayName = "ShowActors"),
	ActorsHide   UMETA(DisplayName = "HideActors"),
	ActorsFlicker   UMETA(DisplayName = "FlickerActors"),
	ActorsDoNothing  UMETA(DisplayName = "DoNothing")
	
};

//
/**\brief Enum visible in UE4 editor representing the direction a Platform_Moving is to move.*/
UENUM()
enum class EMovementType
{
	UpDown UMETA(DisplayName = "Up and Down"),
	LeftRight UMETA(DisplayName = "Left and Right"),
	ForwardBack UMETA(DisplayName = "Forward and Backwards")
};
