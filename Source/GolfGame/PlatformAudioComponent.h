#pragma once

#include "CoreMinimal.h"
#include "Components/AudioComponent.h"
#include "PlatformAudioComponent.generated.h"

/**
 * 
 */
UCLASS()
class GOLFGAME_API UPlatformAudioComponent : public UAudioComponent
{
	GENERATED_BODY()

public:
	
	UPlatformAudioComponent();

	void PlayMovingAudio();
	void StopMovingAudio();

	UPROPERTY(EditAnywhere)
		class USoundCue* MovingAudio;

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
	
private:

	void ChangeAudio();

	
	
};
