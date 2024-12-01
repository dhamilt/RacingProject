// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "MyCheckpoint.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "Checkpoint")
class RACINGPROJECT_API AMyCheckpoint : public AActor
{
	GENERATED_BODY()

	

public:
	AMyCheckpoint();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category ="Checkpoint")
	UBoxComponent* boxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Checkpoint")
	UStaticMeshComponent* checkpointMesh;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Checkpoint")
	int32 checkpointNumber;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Checkpoint")
	bool isFinishLine;

	UFUNCTION(BlueprintInternalUseOnly, Category = "Checkpoint")
	void UpdateVehicle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
