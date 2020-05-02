// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeDialogueTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

AChangeDialogueTriggerBox::AChangeDialogueTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AChangeDialogueTriggerBox::OnOverlapBegin);
	DialoguePlayed = false;
};

void AChangeDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}


void AChangeDialogueTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{	
	if(Dialogue != nullptr && OtherActor == Player && OtherActor && OtherActor != this && !DialoguePlayed)
	{
		Player->ChangeSoundCue(Dialogue);
		DialoguePlayed = true;
	}
}


