
#include "LevelStreamerActor.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
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
    
    ACharacter* MyCharacter = UGameplayStatics::GetPlayerCharacter(this, 0);
    if (OtherActor == MyCharacter && LevelToLoad != "")
    {
        //GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ENCOUNTERED BOX"));
        FLatentActionInfo LatentInfo;
        UGameplayStatics::OpenLevel(this, LevelToLoad);
    }
}
