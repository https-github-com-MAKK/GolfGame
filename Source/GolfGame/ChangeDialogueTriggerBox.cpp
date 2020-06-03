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


void AChangeDialogueTriggerBox::OverlapBeginAction() {

	if (Dialogue != nullptr && !DialoguePlayed && PlayerForAudio != nullptr)
	{
		UE_LOG(LogTemp, Log, TEXT("Played dialogue cue"));
		DialoguePlayed = true;
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AChangeDialogueTriggerBox::DialoguePlay, 10.0, true, TimeToDelayDialogue);
	}

}

void AChangeDialogueTriggerBox::DialoguePlay()
{
	PlayerForAudio->ChangeDialogueCue(Dialogue);
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
}

void AChangeDialogueTriggerBox::OverlapEndAction()
{

}
