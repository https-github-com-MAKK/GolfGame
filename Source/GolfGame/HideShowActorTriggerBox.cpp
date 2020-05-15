// Fill out your copyright notice in the Description page of Project Settings.


#include "HideShowActorTriggerBox.h"

#include "Engine/Engine.h"

void AHideShowActorTriggerBox::OverlapBeginAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin action light trigger"));
	HideShowActionBegin();
}


void AHideShowActorTriggerBox::OverlapEndAction()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end action light trigger"));
	HideShowActionEnd();

}

void AHideShowActorTriggerBox::HideShowActionEnd()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch end"));

	int32 size = ActorSwitch.Num();
	for (int i = 0; i < size; i++)
	{
		ActorSwitch[i]->HideShowActionOff();
	}


}
void AHideShowActorTriggerBox::HideShowActionBegin()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("trigger switch begin"));

	int32 size = ActorSwitch.Num();
	for (int i = 0; i < size; i++)
	{
		ActorSwitch[i]->HideShowActionOn();
	}

}
