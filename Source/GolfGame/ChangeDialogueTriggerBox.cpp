// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeDialogueTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

AChangeDialogueTriggerBox::AChangeDialogueTriggerBox()
{
	DialoguePlayed = false;
};

void AChangeDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
}


void AChangeDialogueTriggerBox::OverlapBeginAction()
{

	
	if(Dialogue != nullptr && !DialoguePlayed && PlayerForAudio != nullptr)
	{
		PlayerForAudio->ChangeDialogueCue(Dialogue);
		DialoguePlayed = true;
	}
	
}
void AChangeDialogueTriggerBox::OverlapEndAction()
{
	
}
