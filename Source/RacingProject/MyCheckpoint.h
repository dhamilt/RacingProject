// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "MyCheckpoint.generated.h"


/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category = "Checkpoint")
class RACINGPROJECT_API AMyCheckpoint : public ATriggerVolume
{
	GENERATED_BODY()

	

public:
	AMyCheckpoint();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Checkpoint")
	int32 checkpointNumber;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Checkpoint")
	bool isFinishLine;

	UFUNCTION(BlueprintInternalUseOnly, Category = "Checkpoint")
	void UpdateVehicle(AActor* OverlappedActor, AActor* OtherActor);
	//virtual void OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
