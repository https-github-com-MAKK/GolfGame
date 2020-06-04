
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/AudioComponent.h"
#include "Ball.generated.h"

UCLASS()
class GOLFGAME_API ABall : public AActor
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()
	
public:
	
	/**\brief Sets default values for this actor's properties
	 *\param something
	 *None
	 *Returns:
	 *void
	 */
	ABall();


protected:
	/**\brief default the ball cannot be telported to in beginning.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BallOptions)
		bool CanTeleportToInBeginning;

	/**\brief Indicates if the ball can currently be teleported to.*/
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool CanBeTeleportedTo;

	/**\brief Indicates if the ball has previously been summoned in this level.*/
	UPROPERTY(VisibleAnywhere, Category = BallOptions)
		bool HasBeenSummoned;

	/**\brief Indicates if the ball can be currently summoned.*/
	UPROPERTY(EditAnywhere, Category = BallOptions)
		bool CanBallBeSummoned;

	/**\brief Called when the game starts or when spawned, sets CanTeleportToInBeginning.
	 *to false.
	 */
	
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	UPROPERTY()
		USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere)
		UStaticMeshComponent* SphereVisual;
	
	//Visual sparkles the ball emits
	UPROPERTY()
		UParticleSystemComponent* SparksParticleSystem;
	
	//Crackling sound the ball makes
	UPROPERTY(VisibleAnywhere, Category = Sound)
		class UAudioComponent* CrackleSoundPlayer;

	
	UPROPERTY(EditAnywhere, Category = Sound)
		class USoundCue* CrackleSound;

	UPROPERTY(EditAnywhere)
		class UMaterial* BallMaterial;

	UFUNCTION()
		/**\brief Returns if the Ball can currently be teleported to
		 *\reutrns bool the value of CanBeTeleportedTo.
		 */
	
		bool GetCanBeTeleportedTo();
	
		/**\brief Sets if the Ball can currently be teleported to based on the value of
		 *CanTeleportTo
		 *\param CanTeleportTo the value of the ability to teleport to the ball at the
		 *current time, sets CanBeTeleportedTo to the value of CanTeleportTo.
		 */
	
		void SetCanBeTeleportedTo(bool CanTeleportTo);
	
		/**\brief Returns if the Ball has been summoned at least once during the current level.
		 *\returns bool the value of HasBeenSummoned
		 */
		bool GetHasBeenSummonedOnce();
	
		/**\brief Sets the value of bool HasBeenSummoned to HasSummoned.
		 *\param HasSummoned the new value of HasBeenSummoned.
		 */
		void SetHasBeenSummonedOnce(bool HasSummoned);
	
		/**\brief Returns if the Ball can currently be summoned by the player.
		 *\returns* bool the value of CanBallBeSummoned.
		 */
	
		bool GetCanBallBeSummoned();
	
		/**\brief  sets the value of bool CanBallBeSummoned to CanBeSummoned.
		 *\param CanBeSummoned the new value of CanBallBeSummoned.
		 */
		void SetCanBallBeSummoned(bool CanBeSummoned);
};
