// Fill out your copyright notice in the Description page of Project Settings.
/*
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Engine/Engine.h"

#include "LightSwitchTrigger.generated.h"

UCLASS()
class GOLFGAME_API ALightSwitchTrigger : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	ALightSwitchTrigger();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		AActor* MyCharacter;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION()
		void TurnOffLights();
	void TurnOnLights();
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Lights)
		TArray<AActor*> Lights;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* OverlapVolume;
};

// Fill out your copyright notice in the Description page of Project Settings.

*/
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "Ball.h"
#include "Components/LightComponent.h"
#include "Engine/Light.h"
#include "LightSwitch.h"
#include "LightSwitchTrigger.generated.h"


UCLASS()
class GOLFGAME_API ALightSwitchTrigger : public AGolfGameTriggerBox
{

	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = References)
		TArray<ALightSwitch*> LightSwitch;
public:

	ALightSwitchTrigger();
	void LightActionBegin();
	void LightActionEnd();
	
	virtual void OverlapBeginAction() override;
	virtual void OverlapEndAction() override;
};


