
#include "LightSwitchTriggerBox.h"
#include "TimerManager.h"
#include "DrawDebugHelpers.h"
#include "Engine/Engine.h"
#include "Engine/World.h"



ALightSwitchTriggerBox::ALightSwitchTriggerBox()
{

	OnActorBeginOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ALightSwitchTriggerBox::OnOverlapEnd);
}


void ALightSwitchTriggerBox::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
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
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap light swithc"));
		TurnOnLights();

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
	//DimLights();
}
void ALightSwitchTriggerBox::TurnOnLights()
{
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle2;
	int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetActorHiddenInGame(false);
		}
		//SetActorHiddenInGame(false);
	}
	AreLightsHidden = false;
	DimLights();
	//int flicker = rand() % 100;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitchTriggerBox::FlickerLights, flickerRate, true, 0.0f);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle2, this, &ALightSwitchTriggerBox::FlickerLights2, flickerRate2, true, 0.0f);

}
void ALightSwitchTriggerBox::DimLights()
{
	//bool NewBoolean;
	int32 num = LightsToDim.Num();
	for (int i = 0; i < num; i++)
	{
		if (LightsToDim[i] != NULL) {
			LightsToDim[i]->SetBrightness(Brightness);
		}
	}
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Dim lights"));

	
}

int LastCalled = 0;
void ALightSwitchTriggerBox::FlickerLights()
{

	bool NewBoolean;
	int32 num = LightsToFlicker.Num();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("world : %f"), World->GetTimeSeconds()));

	Time = World->GetTimeSeconds() - LastCalled;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("time : %d"), Time));

	if(Time%20==0 && World->GetTimeSeconds()!=0)
	{
		LastCalled = World->GetTimeSeconds();
		
	}

	if(Time<2 || (Time<8 && Time>=7)|| (Time < 12 && Time >= 11)|| Time <= 15 && Time >= 14)
	{
		for (int i = 0; i < num; i++) {
			if (AreLightsHidden == true)
			{
				LightsToFlicker[i]->SetActorHiddenInGame(false);
				NewBoolean = false;
			}
			else
			{
				LightsToFlicker[i]->SetActorHiddenInGame(true);
				NewBoolean = true;

			}
			//SetActorHiddenInGame(false);
		}
	}else if(Time==12 || Time==13)
	{
		for (int i = 0; i < num; i++) {
			LightsToFlicker[i]->SetActorHiddenInGame(true);
			NewBoolean = true;
		}
		
	}else
	{
		for (int i = 0; i < num; i++) {
			LightsToFlicker[i]->SetActorHiddenInGame(false);
			NewBoolean = false;
		}
	}
	AreLightsHidden = NewBoolean;

}

void ALightSwitchTriggerBox::FlickerLights2()
{
	bool NewBoolean;
	int32 num = LightsToFlicker2.Num();
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Flickering lights 2"));
	if (AreLightsDimmed == true) {
		for (int i = 0; i < num; i++) {
			if (LightsToFlicker2[i] != NULL)
				LightsToFlicker2[i]->SetBrightness(Brightness);
				//LightsToFlicker2[i]->SetActorHiddenInGame(false);
			
		}
		NewBoolean = false;
	}else
	{
		for (int i = 0; i < num; i++) {
			if (LightsToFlicker2[i] != NULL)
				LightsToFlicker2[i]->SetBrightness(Brightness2);
				
		}
		NewBoolean = true;
	}
	AreLightsDimmed = NewBoolean;
}