// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GolfGameEnums.h"
#include "Switch.generated.h"

UCLASS()

class GOLFGAME_API ASwitch : public AActor
{

	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitch();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	


	virtual void ActionOn() PURE_VIRTUAL(ASwitch::ActionOn, );
	virtual void ActionOff() PURE_VIRTUAL(ASwitch::ActionOff, );
	virtual void GetMethodToCall(uint8 Status) PURE_VIRTUAL(ASwitch::GetMethodToCall, );
	virtual void SetActionOn(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOn, );
	virtual void SetActionOff(uint8 Status) PURE_VIRTUAL(ASwitch::SetActionOff, );
	virtual uint8 GetActionOn() PURE_VIRTUAL(ASwitch::GetActionOn, return 0;);
	virtual uint8 GetActionOff() PURE_VIRTUAL(ASwitch::GetActionOff, return 0;);
	


};
