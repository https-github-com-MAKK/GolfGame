
#include "LightSwitchTriggerBox.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
/*
// Sets default values
ALightSwitchTriggerBox::ALightSwitchTriggerBox()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapEnd);

}

// Called when the game starts or when spawned
void ALightSwitchTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);


}

/*
void ALightSwitchTriggerBox::TurnOffLights()
{
	int num = Lights.Num();
	for (int i = 0; i < num; i++) {
		Lights[i]->SetActorHiddenInGame(true);

		//SetActorHiddenInGame(false);
	}

}
void ALightSwitchTriggerBox::TurnOnLights()
{
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		Lights[i]->SetActorHiddenInGame(false);

		//SetActorHiddenInGame(false);
	}

}


void ALightSwitchTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	
	if (OtherActor && (OtherActor != this) && OtherActor == Ball) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));
		TurnOffLights();
	}
}

void ALightSwitchTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == Ball) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
		TurnOnLights();

	}
}
*/

// Fill out your copyright notice in the Description page of Project Settings.




ALightSwitchTriggerBox::ALightSwitchTriggerBox()
{

	OnActorBeginOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapEnd);
}


void ALightSwitchTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 5);

}

void ALightSwitchTriggerBox::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == MyCharacter) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap begin actor"));
		TurnOffLights();
	}
}

void ALightSwitchTriggerBox::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this) && OtherActor == MyCharacter) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap end actor"));
		//TurnOnLights();

	}
}

void ALightSwitchTriggerBox::TurnOffLights()
{
	int num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetActorHiddenInGame(true);
		
		}
		AreLightsHidden = true;
		//SetActorHiddenInGame(false);
	}
	DimLights();
}
void ALightSwitchTriggerBox::TurnOnLights()
{
	FTimerHandle TimerHandle;
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		Lights[i]->SetActorHiddenInGame(false);
		//SetActorHiddenInGame(false);
	}
	AreLightsHidden = false;
	DimLights();
	//GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitchTriggerBox::FlickerLights, .05f, true, 5.0f);


}
void ALightSwitchTriggerBox::DimLights()
{
	//bool NewBoolean;
	int32 num = LightsToDim.Num();
	for (int i = 0; i < num; i++)
	{
		LightsToDim[i]->SetBrightness(10.0);
		
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dim lights"));

	
}
void ALightSwitchTriggerBox::FlickerLights()
{
	bool NewBoolean;
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if(AreLightsHidden==true)
		{
			Lights[i]->SetActorHiddenInGame(false);
			NewBoolean = false;
		}else
		{
			Lights[i]->SetActorHiddenInGame(true);
			NewBoolean = true;
			
		}
		//SetActorHiddenInGame(false);
	}
	AreLightsHidden = NewBoolean;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Flickering lights"));


}