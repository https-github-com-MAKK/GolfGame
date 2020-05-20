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
	//DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Orange, true, -1, 0, 5);
}


void AChangeDialogueTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if(OtherActor && Player != nullptr && Ball != nullptr && Dialogue != nullptr && !DialoguePlayed)
	{
		if(OtherActor == Ball && TriggeringActor == ETriggeringActor::TriggeredByBall)
		{
			Player->ChangeDialogueCue(Dialogue);
			DialoguePlayed = true;
			
		}
		else if(OtherActor == Player && TriggeringActor == ETriggeringActor::TriggeredByPlayer)
		{
			Player->ChangeDialogueCue(Dialogue);
			DialoguePlayed = true;
		}
		
	}

	
	/*if()
	{
		if(OtherActor && OtherActor == Ball)
	}
	
	if(Dialogue != nullptr && OtherActor && (OtherActor == Player || OtherActor == Ball)  && OtherActor != this && !DialoguePlayed)
	{
		Player->ChangeDialogueCue(Dialogue);
		DialoguePlayed = true;
	}*/
}


