
#include "PlatformAudioComponent.h"

UPlatformAudioComponent::UPlatformAudioComponent()
{
	
}

void UPlatformAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UPlatformAudioComponent::PlayMovingAudio()
{
	FadeOut(2, 0, EAudioFaderCurve::Linear);
}

void UPlatformAudioComponent::StopMovingAudio()
{
	FadeIn(2, 1, 0, EAudioFaderCurve::Linear);
}

void UPlatformAudioComponent::ChangeAudio()
{

}