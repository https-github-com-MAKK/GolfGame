// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "HideShowActorSwitch.generated.h"

UCLASS()
class GOLFGAME_API AHideShowActorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHideShowActorSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TEnumAsByte<ActorHideShowStatus> On;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TEnumAsByte<ActorHideShowStatus> Off;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float FlickerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		bool AreActorsHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<AActor*> ActorsToShowHide;
	UPROPERTY()
		UWorld* World;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int Time;
	UPROPERTY()
		int LastCalled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int ActorFlickerLoopTime;
	UFUNCTION()
 
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void HideShowActionOn();
	void HideShowActionOff();

};


