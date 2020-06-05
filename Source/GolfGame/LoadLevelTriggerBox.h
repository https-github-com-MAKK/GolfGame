#pragma once
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "LoadLevelTriggerBox.generated.h"

/**\brief Trigger box that loads the next level when overlapped.
 *\details Abstract trigger box that loads the designated next level
 *when overlapped by the referenced ActorToCheck (from super GolfGameTriggerBox).
 */

UCLASS(Abstract)
class GOLFGAME_API ALoadLevelTriggerBox : public AGolfGameTriggerBox
{
	/**\brief Macro that sets up the class to support the infrastructure required by the engine.*/
	GENERATED_BODY()

protected:

	/**\brief Determines if end credits should play or the loading screen.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RollCredits;

	/**\brief The amount of time to wait for the next level to load.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LevelLoadTimeDelay;
	
	/**\brief The name of the next level to load.*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelToLoad;

	/**\brief Indicates whether the ActorToCheck is in the trigger box or not.*/
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool IsCharacterInTrigger;
	
public:

	/**\brief Loads the level specified by LevelToLoad.*/

	UFUNCTION(BlueprintCallable, Category = LevelChange)
		void LevelLoad();
	
	/**\brief Sets IsCharacterInTriggerBox to true once the ActorToCheck overlaps this
	 *trigger box.
	 */
	
	UFUNCTION(BlueprintCallable, Category = LevelChange)
	virtual void OverlapBeginAction() override;
	
private:

	/**\brief Inherited method that is not implemented
	 */
	
	virtual void OverlapEndAction() override;

};

