
#pragma once

#include "Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Blueprint/UserWidget.h"
#include "GenericPlatform/GenericPlatformProcess.h"
#include "LevelStreamerActor.generated.h"

UCLASS()
class GOLFGAME_API ALevelStreamerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ALevelStreamerActor();
	virtual void Tick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	
	UFUNCTION()
		void OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable, Category = LevelChange)
		void LevelLoad();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelToLoad;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		bool IsCharacterInTrigger;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* OverlapVolume;

};
