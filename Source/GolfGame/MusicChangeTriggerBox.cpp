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
}


void AMusicChangeTriggerBox::OverlapBeginAction()
{
	if(Music != nullptr && PlayerForAudio != nullptr && !MusicStarted)
	{
		PlayerForAudio->ChangeMusicCue(Music);
		MusicStarted = true;
	}
}

void AMusicChangeTriggerBox::OverlapEndAction()
{
	
}
