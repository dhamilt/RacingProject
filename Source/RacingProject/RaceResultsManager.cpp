// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceResultsManager.h"
#include "MyCheckpoint.h"
#include "RacingProjectSportsCar.h"
#include "Kismet/GameplayStatics.h"
#include "RaceMarkerComponent.h"

// Sets default values
ARaceResultsManager::ARaceResultsManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARaceResultsManager::DeactivateCurrentCheckpoint(int32 currentCheckpoint)
{
	if(currentCheckpoint < checkpoints.Num())
		if (checkpoints[currentCheckpoint].Get()->checkpointMesh->IsVisible())
			checkpoints[currentCheckpoint].Get()->checkpointMesh->ToggleVisibility(true);
}

void ARaceResultsManager::ActivateNextCheckpoint(int32 currentCheckpoint)
{
	int32 index = 0;
	if (currentCheckpoint < checkpoints.Num() - 1)
		index = currentCheckpoint + 1;
	if (!checkpoints[index].Get()->checkpointMesh->IsVisible())
		checkpoints[index].Get()->checkpointMesh->ToggleVisibility(true);
	SetCheckpointTarget(index);
}

void ARaceResultsManager::DisableAllCheckpoints(TArray<int32> exclusions)
{
	for (int32 i = 0; i < checkpoints.Num(); ++i)
	{
		if (!exclusions.IsEmpty())
			if (exclusions.Contains(i))
				continue;
		if (checkpoints[i].Get()->checkpointMesh->IsVisible())
			checkpoints[i].Get()->checkpointMesh->ToggleVisibility(true);
	}

}

void ARaceResultsManager::FindRaceCar()
{
	TArray<AActor*> actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ARacingProjectSportsCar::StaticClass(), actors);
	if (!actors.IsEmpty())
		raceCar = CastChecked<ARacingProjectSportsCar>(actors[0]);

}

void ARaceResultsManager::SetCheckpointTarget(int32 checkPointTarget)
{
	if(checkPointTarget < checkpoints.Num())
	 raceCar.Get()->raceMarker->target =  checkpoints[checkPointTarget].Get();
}

// Called when the game starts or when spawned
void ARaceResultsManager::BeginPlay()
{
	Super::BeginPlay();
	DisableAllCheckpoints({ 0 });
	FindRaceCar();
	SetCheckpointTarget(0);
}

// Called every frame
void ARaceResultsManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

