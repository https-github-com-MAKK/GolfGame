// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicChangeTriggerBox.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


AMusicChangeTriggerBox::AMusicChangeTriggerBox()
{

}

void AMusicChangeTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	Player = dynamic_cast<AGolfGameCharacter*>(ActorToCheck);
}


void AMusicChangeTriggerBox::OverlapBeginAction()
{
	if(Music != nullptr && Player != NULL)
	{
		Player->ChangeDialogueCue(Music);
	}
}

void AMusicChangeTriggerBox::OverlapEndAction()
{
	
}
