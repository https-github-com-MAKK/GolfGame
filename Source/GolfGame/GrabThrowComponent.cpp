/*GolfGameCharacter.cpp
*Author: Katherine Bozin
*Revision: 1 (03/04/2020)
*Revision: 2 (05/18/2020)
*Rev. Author: Kaylene Petrin
*Rev. Comments: Updated the class to have a SummonGrabBall method, allowing the use to grab
*the ball when it is summoned to the player
*Description: Component that allows player to grab objects
*/
#include "GrabThrowComponent.h"
#include "Ball.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "Components/PrimitiveComponent.h"
#include "Engine/Engine.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UGrabThrowComponent::UGrabThrowComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}


// Called when the game starts
void UGrabThrowComponent::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void UGrabThrowComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UGrabThrowComponent::Grab(UObject* WorldContextObject, UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent)
{
	if (FPCameraComponent == nullptr || WorldContextObject == nullptr) return false;

	FHitResult Hit;
	const auto StartTrace = FPCameraComponent->GetComponentLocation();
	const auto ForwardVector = FPCameraComponent->GetForwardVector();
	const auto EndTrace = StartTrace + (ForwardVector * MaxGrabDist);
	const auto MyLocation = GetOwner()->GetActorLocation();
	if (UKismetSystemLibrary::LineTraceSingleForObjects(WorldContextObject, StartTrace, EndTrace, PhysicsObjectType, false, ActorsToIgnore, EDrawDebugTrace::None, Hit, true, FColor::Blue, FColor::Blue))
	{
		HitComponent = Hit.GetComponent();
		const auto Distance = MyLocation - HitComponent->GetComponentLocation();
		PlayerObjectDist = Distance.Size();

		if (Hit.GetActor() != nullptr && HitComponent != nullptr && Ph != nullptr && HitComponent->IsSimulatingPhysics() && PlayerObjectDist <= MinGrabDist)
		{
			HitComponent->SetEnableGravity(true);
			bPhysicsHandleActive = true;
			PlayerObjectDist = SnapDistance;
			bObjectHeld = true;
			if (GrabSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, GrabSound, GetOwner()->GetActorLocation());
			}
			Ph->GrabComponentAtLocation(HitComponent, Hit.BoneName, HitComponent->GetCenterOfMass());
			return true;
		}
		return false;
	}
	return false;
}

void UGrabThrowComponent::SummonGrabBall(ABall* Ball, FVector SummonLocation, UPhysicsHandleComponent* Ph)
{

	HitComponent = Ball->SphereVisual;

	if (HitComponent != nullptr && Ph != nullptr && HitComponent->IsSimulatingPhysics())
	{
		UE_LOG(LogTemp, Log, TEXT("Picked up ball"));

		HitComponent->SetEnableGravity(true);
		bPhysicsHandleActive = true;
		PlayerObjectDist = SnapDistance;
		bObjectHeld = true;
		if (GrabSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, GrabSound, GetOwner()->GetActorLocation());
		}
		Ball->SetActorLocation(SummonLocation);
		FHitResult Hit;
		Ph->GrabComponentAtLocationWithRotation(HitComponent, Hit.BoneName, HitComponent->GetCenterOfMass(),HitComponent->GetComponentRotation());
		UE_LOG(LogTemp, Log, TEXT("Updating"));
	}
	
}

bool UGrabThrowComponent::Throw(UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent)
{
	if (Ph != nullptr && FPCameraComponent != nullptr && HitComponent != nullptr && Release(Ph, true) && HitComponent->IsSimulatingPhysics())
	{
		const auto ForwardVector = FPCameraComponent->GetForwardVector();
		const auto ImpulseVector = ForwardVector * ThrowingForce;
		HitComponent->AddImpulse(ImpulseVector, NAME_None, true);
		if (ThrowSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ThrowSound, GetOwner()->GetActorLocation());
		}
		return true;
	}
	return false;
}

bool UGrabThrowComponent::Release(UPhysicsHandleComponent* Ph, const bool bThrow)
{
	if (Ph != nullptr && bObjectHeld && bPhysicsHandleActive)
	{
		bPhysicsHandleActive = false;
		bObjectHeld = false;
		Ph->ReleaseComponent();
		if (bThrow && ReleaseSound != nullptr)
		{
			UGameplayStatics::PlaySoundAtLocation(this, ReleaseSound, GetOwner()->GetActorLocation());
		}
		return true;
	}
	return false;
}

void UGrabThrowComponent::TraceHandleLocation(UPhysicsHandleComponent* Ph, UCameraComponent* FPCameraComponent)
{
	if (bPhysicsHandleActive)
	{
		if (Ph != nullptr && FPCameraComponent != nullptr)
		{
			const auto StartTrace = FPCameraComponent->GetComponentLocation();
			const auto  ForwardVector = FPCameraComponent->GetForwardVector();
			const auto EndTrace = StartTrace + (ForwardVector * PlayerObjectDist);
			HandleLocation = EndTrace;
			Ph->SetTargetLocationAndRotation(HandleLocation, GetOwner()->GetActorRotation());
		}
	}
}

