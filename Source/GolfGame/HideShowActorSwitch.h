// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.h"
#include "HideShowActorSwitch.generated.h"


UCLASS()
class GOLFGAME_API AHideShowActorSwitch : public ASwitch
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHideShowActorSwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus On;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		ActorHideShowStatus Off;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		float FlickerRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		bool AreActorsHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<AActor*> ActorsToShowHide;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		TArray<ActorHideShowStatus> FlickerPattern;
	UPROPERTY()
		UWorld* World;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int Time;
	UPROPERTY()
		int LastCalled;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int FlickerTime;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeHidden;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeShown;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ActorBehavior)
		int TimeFlickering;
		int FlickerIndex;
		int CurrentRunTime;
	UFUNCTION()
		void HideOrShowActors(bool Show);
		void FlickerInAndOut();
		void IncrementFlickerIndex();
		void SetCurrentRunTime();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void ActionOn() override;
	virtual void ActionOff() override;
	virtual void GetMethodToCall(uint8 Status) override;
	virtual uint8 GetActionOff() override;
	virtual void SetActionOn(uint8 Status) override;
	virtual void SetActionOff(uint8 Status) override;
	virtual uint8 GetActionOn() override;

};


