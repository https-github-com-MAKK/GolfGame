// Fill out your copyright notice in the Description page of Project Settings.


#include "ChangeDialogueTriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

AChangeDialogueTriggerBox::AChangeDialogueTriggerBox()
{
	OnActorBeginOverlap.AddDynamic(this, &AChangeDialogueTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AChangeDialogueTriggerBox::OnOverlapEnd);
};

void AChangeDialogueTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}


void AChangeDialogueTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{	
	if(Dialogue != nullptr && OtherActor == Player && OtherActor && OtherActor != this)
	{
		Player->ChangeSoundCue(Dialogue);
	}
}


void AChangeDialogueTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::Green, TEXT("End Begin"));
}

