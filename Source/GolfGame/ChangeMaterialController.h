#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <string>
#include "Platform_Moving.h"
#include "Ball.h"
#include "Engine/RectLight.h"
#include "ElevatorPlatform.h"
#include "Components/RectLightComponent.h"
#include "Components/AudioComponent.h"
#include "ChangeMaterialController.generated.h"

/**\brief Class controls the functionality behind the in-game switches. Toggles movement of associated elevator or moving
 *platform, switches material of the controller to represent whether it is on or off, and toggles visiblity of an associated
 *light source. The switch can only be hit once per second by the ball as to not have false positive hits.
 * 
 */

UCLASS()
class GOLFGAME_API AChangeMaterialController : public AActor
{
	/**\Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

	
public:
	// Sets default values for this actor's properties
	/**\brief Sets up static mesh component for the visual aspect of the actor. Adds materials for
	 * on and off states. Sets up box component for impact of the ball to toggle associated actor
	 * properties.
	 */
	AChangeMaterialController();

	
protected:
	
	/**\brief Called when the game starts or when spawned. Sets material to OffMaterial. Sets CanBeHit
	 *  to true so that is can toggle properties when hit. Sets timer for resetting CanBeHit.
	 */
	virtual void BeginPlay() override;

	
public:

	/**\brief Called every frame.*/
	virtual void Tick(float DeltaTime) override;

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

	/**\brief Toggles properties when ball overlaps the actor. Sets CanBeHit to false. Toggles associated
	 * light's visibility, whether an associated platform is moving and whether an associated elevator can
	 * move. 
	 */
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, 
			class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, 
			const FHitResult& SweepResult);

	/**\brief Represents the moving platform whose movement is toggled on or off. Associated platform
	 *set in UE4 editor.
	 */
	UPROPERTY(EditAnywhere)
		class APlatform_Moving* AssociatedPlatform;

	//
	/**\brief The ball that impact the switch to turn it on or off. Specific ball set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class ABall* Ball;

	/**\brief Selected light source to toggle visibility. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class ARectLight* AssociatedRectlight;

	/**\brief Selected elevator to toggle active or inactive. Set in UE4 editor.*/
	UPROPERTY(EditAnywhere)
		class AElevatorPlatform* AssociatedElevator;
	
	
private:

	/**\brief Toggles a moving platform's movement to on or off.*/
	void TogglePlatformMovement();

	/**\brief Toggles visibility of selected light source.*/
	void ToggleSpotlight();

	/**\brief Toggles a selected elevator to active or inactive.*/
	void ToggleElevator();

	/**\brief sets CanBeHit variable to true.*/
	void SetCanBeHit();

	/**\brief Intended to toggle audio component sound on or off, unfinished.*/
	void CyclePlatformMovingAudio();

	/**\brief enum for switches to internally represent whether they are in an on or off state.*/
	enum SwitchState { On, Off };

	/**\brief Current state of the the switch, on of off.*/
	SwitchState CurrentSwitchState = Off;

	/**\brief Current state of the light, on or off*/
	SwitchState CurrentSpotlightState = Off;

	/**\brief Current state of the audio component.*/
	SwitchState CurrentMovingAudio = Off;

	

	//
	/**\brief Whether the switch can currently be hit by the ball to toggle associated actors.*/
	bool CanBeHit;

	/**\brief Timer for when the switch can be hit by the ball*/
	FTimerHandle MemberTimerHandle;
	
};
