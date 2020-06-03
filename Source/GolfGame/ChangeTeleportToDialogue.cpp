// Fill out your copyright notice in the Description page of Project Settings.

#include "ChangeTeleportToDialogue.h"
#include "GolfGameCharacter.h"
#include <string>

void AChangeTeleportToDialogue::OverlapBeginAction()
{
   
	AGolfGameCharacter* Player = dynamic_cast<AGolfGameCharacter*>(ActorToCheck);
    Player->NeedToTeleportBallCue = Dialogue;
    
}

void AChangeTeleportToDialogue::OverlapEndAction()
{
    
}