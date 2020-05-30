// Fill out your copyright notice in the Description page of Project Settings.


#include "LoadLevelTriggerBox.h"

#include "Kismet/GameplayStatics.h"

ALoadLevelTriggerBox::ALoadLevelTriggerBox()
{
    PrimaryActorTick.bCanEverTick = true;

}


void ALoadLevelTriggerBox::BeginPlay()
{
    Super::BeginPlay();

}

void ALoadLevelTriggerBox::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}


void ALoadLevelTriggerBox::LevelLoad() {
    UGameplayStatics::OpenLevel(this, LevelToLoad);
}

void ALoadLevelTriggerBox::SetTimeDelay(float TimeDelay)
{
    if (TimeDelay >= 0)
    {
        LevelLoadTimeDelay = TimeDelay;
    }
}
float ALoadLevelTriggerBox::GetTimeDelay()
{
    return LevelLoadTimeDelay;
}

void ALoadLevelTriggerBox::OverlapBeginAction()
{
    IsCharacterInTrigger = true;
    if (IsNotBlueprint) {
        FPlatformProcess::Sleep(LevelLoadTimeDelay);
        UGameplayStatics::OpenLevel(this, LevelToLoad);
    }
}


void ALoadLevelTriggerBox::OverlapEndAction()
{
	
}