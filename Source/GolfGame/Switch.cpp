/*Switch.cpp
 *Author: Kaylene Petrin
 *Revision: 1
 *Description: Abstract class that switches objects on/off.  Ue4 interfaces do not work well, so an
 *abstract class was chosen
 */
#include "Switch.h"
#include "Engine/Engine.h"

// Sets default values
ASwitch::ASwitch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


