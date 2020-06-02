// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayOnceSoundTriggerBox.h"
#include "Kismet/GameplayStatics.h"

void APlayOnceSoundTriggerBox::OverlapBeginAction()
{
	if (Sound != nullptr && Player != nullptr && !HasSoundPlayed)
	{
		UGameplayStatics::PlaySoundAtLocation(this, Sound, GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation());
		HasSoundPlayed = true;
	}
}

void APlayOnceSoundTriggerBox::OverlapEndAction()
{

}