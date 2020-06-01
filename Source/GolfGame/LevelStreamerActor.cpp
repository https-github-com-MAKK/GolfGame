
#include "LevelStreamerActor.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "Blueprint/UserWidget.h"
//#include "GenericPlatform/GenericPlatformProcess.h"
#include "Kismet/GameplayStatics.h"

ALevelStreamerActor::ALevelStreamerActor()
{
    PrimaryActorTick.bCanEverTick = true;

    OverlapVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapVolume"));
    RootComponent = OverlapVolume;

    OverlapVolume->OnComponentBeginOverlap.AddUniqueDynamic(this, &ALevelStreamerActor::OverlapBegins);

}


void ALevelStreamerActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ALevelStreamerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALevelStreamerActor::OverlapBegins(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("OVERLAP"));

    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (OtherActor == MyCharacter && LevelToLoad != "" /*&& LoadingScreen != NULL*/)
    {
        IsCharacterInTrigger = true;
        // LoadingScreen->AddToViewport();

         GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ENCOUNTERED BOX"));
        //FLatentActionInfo LatentInfo;
        //FPlatformProcess::Sleep(5.0);
        //UGameplayStatics::OpenLevel(this, LevelToLoad);
    }
}
void ALevelStreamerActor::LevelLoad(){
    UGameplayStatics::OpenLevel(this, LevelToLoad);

}

