// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSwitchTrigger.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
ALightSwitchTrigger::ALightSwitchTrigger()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALightSwitchTrigger::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ALightSwitchTrigger::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALightSwitchTrigger::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALightSwitchTrigger::TurnOffLights()
{
	int num = Lights.Num();
	for (int i = 0; i < num;  i++) {
		Lights[i]->SetActorHiddenInGame(true);
		
		//SetActorHiddenInGame(false);
	}
	
}
void ALightSwitchTrigger::TurnOnLights()
{
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		Lights[i]->SetActorHiddenInGame(false);

		//SetActorHiddenInGame(false);
	}

}


void ALightSwitchTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (OtherActor == MyCharacter){
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));

	}
}

void ALightSwitchTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
	if (OtherActor == MyCharacter){
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));


	}
}