// Fill out your copyright notice in the Description page of Project Settings.


#include "MusicChangeTriggerBox.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


AMusicChangeTriggerBox::AMusicChangeTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AMusicChangeTriggerBox::OnOverlapBegin);
}

void AMusicChangeTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Blue, true, -1, 0, 5);
}


void AMusicChangeTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if(Music != nullptr && OtherActor == Player && OtherActor && OtherActor != this)
	{
		Player->ChangeDialogueCue(Music);
	}
}
