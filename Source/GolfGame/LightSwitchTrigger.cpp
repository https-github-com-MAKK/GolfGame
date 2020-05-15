// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchTrigger.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"


ALightSwitchTrigger::ALightSwitchTrigger()
{

	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}


void ALightSwitchTrigger::OverlapBeginAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin action light trigger"));
	LightActionBegin();
}


void ALightSwitchTrigger::OverlapEndAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end action light trigger"));
	LightActionEnd();

}

void ALightSwitchTrigger::LightActionEnd()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch end"));
	int32 size = LightSwitch.Num();
	for (int i = 0; i < size; i++)
	{
		LightSwitch[i]->LightActionOff();
	}	
}
void ALightSwitchTrigger::LightActionBegin()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch begin"));

	int32 size = LightSwitch.Num();
	for (int i = 0; i < size; i++)
	{
		LightSwitch[i]->LightActionOn();
	}

}

