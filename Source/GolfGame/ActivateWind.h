#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
#include "Ball.h"
#include "Engine/RectLight.h"
#include "Components/RectLightComponent.h"
#include "GolfGameEnums.h"
#include "Sound/AmbientSound.h"
#include "ActivateWind.generated.h"


UCLASS()
class GOLFGAME_API AActivateWind : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AActivateWind();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/**\brief boolean to specify how many trigger boxes.*/

	UPROPERTY(EditAnywhere)
		bool ToggleTwoWindTriggerBoxes;
	
	/**\brief Visible mesh representing the actor. Set in UE4 editor.*/

	UPROPERTY(VisibleAnywhere)
		class UStaticMeshComponent* MyMesh;

	/**\brief Green material should be selected, represents the switch in the on state. Set in
	 * UE4 editor.
	 */
	UPROPERTY(EditAnywhere)
		class UMaterial* OnMaterial;

	/**\brief Red material should be selected, represents the switch in the off state. Set in
	 * UE4 editor.
	 */
	UPROPERTY(EditAnywhere)
		class UMaterial* OffMaterial;

	/**\brief Box component for the overlapping section of the switch, where the ball will make
	 *contact and toggle switch properties.*/
	UPROPERTY()
		class UBoxComponent* MyBoxComponent;

	/**\brief .*/
	UPROPERTY(EditAnywhere)
		bool OnAtStart = false;

	/**\brief Toggles properties when ball overlaps the actor. Sets CanBeHit to false. Toggles associated
	 * light's visibility, whether an associated platform is moving and whether an associated elevator can
	 * move.
	 */
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/**\brief The WindTriggerBox that needs to be turned on or off.*/
	UPROPERTY(EditAnywhere)
		class AWindTriggerBox* AssociatedWindBox;

	//
	/**\brief The ball that impact the switch to turn it on or off. Specific ball set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	/**\brief Selected light source to toggle visibility. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class ARectLight* AssociatedRectlight;

	/**\brief left side wind sound*/
	UPROPERTY(EditAnywhere)
		class AAmbientSound* WindSoundLeft;

	/**\brief Right side wind sound.*/
	UPROPERTY(EditAnywhere)
		class AAmbientSound* WindSoundRight;

	/**\brief timer for the wind force.*/
	FTimerHandle MemberTimerHandle;


	
private:

	/**\brief Called to turn the wind off if it is on
		 */
	void ToggleWind();

	/**\brief Called to turn the wind on if it is off
		 */
	void ToggleWindOff();

	/**\brief Called to turn the the spotlight on or off
		 */
	void ToggleSpotlight();

	/**\brief sets CanBeHit variable to true.*/

	void SetCanBeHit();

	/**\brief Called to turn the wind sound on or off
		 */
	void ToggleWindSound();

	/**\brief enum for switches to internally represent whether they are in an on or off state.*/

	enum SwitchState { On, Off };

	/**\brief Variable to decide whether or not this actor can be hit.*/

	bool CanBeHit;

	/**\brief Current state of the the switch, on of off.*/
	SwitchState CurrentSwitchState = Off;

	/**\brief Current state of the light, on or off*/
	SwitchState CurrentSpotlightState = Off;

	/**\brief Current state of the fan in the left room, on or off*/
	SwitchState CurrentWindSoundRight = Off;

	/**\brief Current state of the fan in the right room, on or off*/
	SwitchState CurrentWindSoundLeft = On;

};
