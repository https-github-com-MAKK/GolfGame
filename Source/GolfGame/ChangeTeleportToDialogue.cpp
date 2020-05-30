// Fill out your copyright notice in the Description page of Project Settings.

#include "GolfGameCharacter.h"
#include "ChangeTeleportToDialogue.h"
#include "Sound/SoundBase.h"
#include <string>

void AChangeTeleportToDialogue::OverlapBeginAction()
{
    try
    {
		AGolfGameCharacter* Player = dynamic_cast<AGolfGameCharacter*>(ActorToCheck);
        Player->NeedToTeleportBallCue = Dialogue;
    }
	catch(std::string Message)
	{
        UE_LOG(LogTemp, Warning, TEXT("Setting new cannot teleport to ball dialogue failed"));
	}
    
}

void AChangeTeleportToDialogue::OverlapEndAction()
{
    
}