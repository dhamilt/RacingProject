// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceTrack.generated.h"

class USplineComponent;
class UPrimitiveComponent;
class UHierarchicalInstancedStaticMeshComponent;

UCLASS(Blueprintable, Category = "Race Track")
class RACINGPROJECT_API ARaceTrack : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Track")
	USplineComponent* RaceTrack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Track")
	UHierarchicalInstancedStaticMeshComponent* Checkpoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Track")
	FVector CheckpointScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Track")
	float RotationOffset;

private:
	TArray<FTransform> checkpointTransforms;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this actor's properties
	ARaceTrack();

	UFUNCTION(BlueprintCallable, Category = "Race Track")
	void AddCheckpoints();

	UFUNCTION(BlueprintCallable, Category = "Race Track")
	void EnableCheckpoint(int32 index);

	UFUNCTION(BlueprintCallable, Category = "Race Track")
	void DisableCheckpoints(int32 first, int32 last);

	UFUNCTION(BlueprintCallable, Category = "Race Track")
	void DisableCheckpoint(int32 index);

	UFUNCTION(BlueprintCallable, Category = "Race Track")
	void NextCheckpoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult);
};
