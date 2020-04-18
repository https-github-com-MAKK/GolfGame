#include "OscellatingPlatform.h"
#include "Components/StaticMeshComponent.h"

AOscellatingPlatform::AOscellatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	Direction = 1; //initially going up
	CurTime = PauseTime;

}

// Called when the game starts or when spawned
void AOscellatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginalZ = GetActorLocation().Z;
	MaxZ = OriginalZ + PathHeight; //calculates path height
}

// Called every frame
void AOscellatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(Paused)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Paused: %d"), CurTime);
		CurTime--; //if paused, decrement curtime by 1
		if(CurTime==0)
		{
			CurTime = PauseTime;
			Paused = false; //if curtime reaches 0, reset curtime and end pause
		}
	}
	else //if not paused
	{
		FVector NewLocation = GetActorLocation();
		NewLocation.Z += Speed*Direction; //movement up or down at set speed
		SetActorLocation(NewLocation);
		if (NewLocation.Z > MaxZ-Speed || NewLocation.Z == OriginalZ) //if Z exceeds max path height or returns to original position
		{
			Direction = Direction*-1; //reverse direction
			Paused = true; //pause
		}

	}
	

}

