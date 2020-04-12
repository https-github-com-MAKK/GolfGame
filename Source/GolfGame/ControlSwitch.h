// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ControlSwitch.generated.h"

UCLASS()
class GOLFGAME_API AControlSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AControlSwitch();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* VisualMesh;

	//overhead directional light, illuminated when switch is on
	UPROPERTY(EditAnywhere)
		AActor* OverheadLight;

	void SwitchMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

};
