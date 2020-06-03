/*SwitchTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Triggerbox for any subclass that extends Switch.  Holds an array of switches and
 *when overlapped will flip the switches in the array on, when overlap ends flips the switches off.
 */
#include "SwitchTriggerBox.h"
#include "Engine/Engine.h"

void ASwitchTriggerBox::SwitchOff()
{
	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOff();
	}
	GetWorld()->GetTimerManager().ClearTimer(TimerHandleSwitchOff);
}

void ASwitchTriggerBox::SwitchOn()
{
	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOn();
	}
	GetWorld()->GetTimerManager().ClearTimer(TimerHandleSwitchOn);
}

void ASwitchTriggerBox::OverlapBeginAction()
{
	if (DisableOverlapEnd && CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredBegin)
	{
		HasPreviouslyBeenTriggeredBegin = true;
		OverlapBeginActionHelper();
		OverlapEndAction();
	}
	else if ((!DisableOverlapEnd && CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredBegin) || (!CanOnlyBeTriggeredOnce))
	{
		OverlapBeginActionHelper();
	}
}

void ASwitchTriggerBox::OverlapBeginActionHelper()
{
	GetWorld()->GetTimerManager().SetTimer(TimerHandleSwitchOn, this, &ASwitchTriggerBox::SwitchOn, 5, true, DelayTimeOn);
}

void ASwitchTriggerBox::OverlapEndAction()
{
	if ((CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredEnd) || (!CanOnlyBeTriggeredOnce))
	{
		GetWorld()->GetTimerManager().SetTimer(TimerHandleSwitchOff, this, &ASwitchTriggerBox::SwitchOff, 5, true, DelayTimeOff + DelayTimeOn);
		HasPreviouslyBeenTriggeredEnd = true;
	}
}
