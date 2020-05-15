
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
	LastCalled = 0;
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
		FlickerLights2();
	}
}

void ALightSwitchTriggerBox::TurnOffLights()
{
	HideShowActors(Lights, true);
}
void ALightSwitchTriggerBox::TurnOnLights()
{
	FTimerHandle TimerHandle;
	FTimerHandle TimerHandle2;
	/*int32 num = Lights.Num();
	for (int i = 0; i < num; i++) {
		if (Lights[i] != NULL) {
			Lights[i]->SetActorHiddenInGame(false);
		}
		//SetActorHiddenInGame(false);
	}
	AreLightsHidden = false;*/
	HideShowActors(Lights, false);
	//DimLights();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ALightSwitchTriggerBox::FlickerLights, flickerRate, true, 0.0f);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle2, this, &ALightSwitchTriggerBox::FlickerLights2, flickerRate2, true, 0.0f);

}
void ALightSwitchTriggerBox::DimLights(TArray<ALight*> LightsToDim, float Dim)
{

	int32 num = LightsToDim.Num();
	for (int i = 0; i < num; i++) {
		if (LightsToDim[i] != NULL) {
			LightsToDim[i]->SetBrightness(Dim);
		}
	}

}


void ALightSwitchTriggerBox::FlickerLights()
{

	bool NewBoolean;
	int32 num = LightsToFlicker.Num();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("world : %f"), World->GetTimeSeconds()));

	Time = World->GetTimeSeconds() - LastCalled;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("time : %d"), Time));

	if(Time%LightLoopTime==0 && World->GetTimeSeconds()!=0)
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
		DimLights(LightsToFlicker2, Brightness);
		NewBoolean = false;
	}else
	{
		DimLights(LightsToFlicker2, Brightness2);
		NewBoolean = true;
	}
	AreLightsDimmed = NewBoolean;
}

void ALightSwitchTriggerBox::HideShowActors(TArray<AActor*> ActorsToHideShow, bool Show)
{
	int num = ActorsToHideShow.Num();
	for (int i = 0; i < num; i++) {
		if (ActorsToHideShow[i] != NULL) {
			ActorsToHideShow[i]->SetActorHiddenInGame(Show);
		}
	}
	AreLightsHidden = Show;
}