#pragma once
#include "CoreMinimal.h"
#include "GolfGameTriggerBox.h"
#include "LoadLevelTriggerBox.generated.h"


UCLASS(Abstract)
class GOLFGAME_API ALoadLevelTriggerBox : public AGolfGameTriggerBox
{
	//Macro that sets up the class to support the infrastructure required by the engine
	GENERATED_BODY()

protected:

	//Determines if end credits should play or the loading screen
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RollCredits;

	//The amount of time to wait for the next level to load
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LevelLoadTimeDelay;
	
	//The name of the next level to load
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName LevelToLoad;

	//Indicates whether the ActorToCheck is in the trigger box or not
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		bool IsCharacterInTrigger;
	
public:

	/*Loads the level specified by LevelToLoad
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */

	UFUNCTION(BlueprintCallable, Category = LevelChange)
		void LevelLoad();
	
	/*Sets IsCharacterInTriggerBox to true once the ActorToCheck overlaps this
	 *trigger box
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	UFUNCTION(BlueprintCallable, Category = LevelChange)
	virtual void OverlapBeginAction() override;
	
private:

	/*Inherited method that is not implemented
	 *Parameters:
	 *None
	 *Returns:
	 *void
	 */
	
	virtual void OverlapEndAction() override;

};

