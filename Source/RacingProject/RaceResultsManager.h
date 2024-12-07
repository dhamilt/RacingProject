// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceResultsManager.generated.h"

class AMyCheckpoint;
class ARacingProjectSportsCar;

UCLASS()
class RACINGPROJECT_API ARaceResultsManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaceResultsManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoints")
	TArray<TSoftObjectPtr<AMyCheckpoint>> checkpoints;
	
	UPROPERTY(VisibleAnywhere, Category = "Race Manager")
	TSoftObjectPtr<ARacingProjectSportsCar> raceCar;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Disables current checkpoint from view
	void DeactivateCurrentCheckpoint(int32 currentCheckpoint);
	// Activates next checkpoint to view
	void ActivateNextCheckpoint(int32 currentCheckpoint);
	void DisableAllCheckpoints(TArray<int32> exclusions = TArray<int32>());
	// Finds the first instance of the wheeled pawn
	void FindRaceCar();
	// Sets checkpoint target for race arrow marker
	void SetCheckpointTarget(int32 checkPointTarget);
};
