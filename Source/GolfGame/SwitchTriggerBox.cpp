/*SwitchTriggerBox.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Triggerbox for any subclass that extends Switch.  Holds an array of switches and
 *when overlapped will flip the switches in the array on, when overlap ends flips the switches off.
 */
#include "SwitchTriggerBox.h"
#include "Engine/Engine.h"


void ASwitchTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	CallCount = 0;
}

void ASwitchTriggerBox::SwitchOff()
{

	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOff();
	}
	if (CallCount == ReapeatNum) 
	{
		World->GetTimerManager().ClearTimer(TimerHandleSwitchOff);
	}
	CallCount++;
}

void ASwitchTriggerBox::SwitchOn()
{
	int32 size = Switches.Num();
	for (int i = 0; i < size; i++)
	{
		Switches[i]->ActionOn();
	}
	if (CallCount == ReapeatNum) 
	{
		World->GetTimerManager().ClearTimer(TimerHandleSwitchOn);
	}
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
	World->GetTimerManager().SetTimer(TimerHandleSwitchOn, this, &ASwitchTriggerBox::SwitchOn, OnEverySec, true, DelayTimeOn);
	HasPreviouslyBeenTriggeredBegin = true;
}

void ASwitchTriggerBox::OverlapEndAction()
{

	if ((CanOnlyBeTriggeredOnce && !HasPreviouslyBeenTriggeredEnd) || (!CanOnlyBeTriggeredOnce)) 
	{
		World->GetTimerManager().SetTimer(TimerHandleSwitchOff, this, &ASwitchTriggerBox::SwitchOff, OffEverySec, true, DelayTimeOff + DelayTimeOn);
		HasPreviouslyBeenTriggeredEnd = true;
	}
}


