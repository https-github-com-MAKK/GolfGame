/*OscellatingPlatform.cpp
 *Author: Katherine Bozin
 *Description: Platform that moves back and forth on the x, y, or z axis.
 */

#include "OscellatingPlatform.h"
#include "Components/StaticMeshComponent.h"

AOscellatingPlatform::AOscellatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	PauseTime = 120;
	PathHeight = 150.0f;
	Speed = 0.1f;
	Direction = 1;
	Axis = "X";
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	CurTime = PauseTime;

}

// Called when the game starts or when spawned
void AOscellatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	OriginalX = GetActorLocation().X;
	OriginalY = GetActorLocation().Y;
	OriginalZ = GetActorLocation().Z;
	MaxX = OriginalX + PathHeight;
	MaxY = OriginalY + PathHeight;
	MaxZ = OriginalZ + PathHeight;
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
		if (Axis=="X") {
			NewLocation.X += Speed * Direction; //movement on X axis at set speed
			SetActorLocation(NewLocation);
			if (NewLocation.X > MaxX - Speed || NewLocation.X == OriginalX) //if X exceeds max path length or returns to original position
			{
				Direction = Direction * -1; //reverse direction
				Paused = true; //pause
			}
		}
		else if (Axis=="Y") {
			NewLocation.Y += Speed * Direction;
			SetActorLocation(NewLocation);
			if (NewLocation.Y > MaxY - Speed || NewLocation.Y == OriginalY)
			{
				Direction = Direction * -1;
				Paused = true;
			}

		}
		else if (Axis=="Z") {
			NewLocation.Z += Speed * Direction;
			SetActorLocation(NewLocation);
			if (NewLocation.Z > MaxZ - Speed || NewLocation.Z == OriginalZ)
			{
				Direction = Direction * -1;
				Paused = true;
			}
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("Axis set to invalid value!"));
		}
	}
	

}

