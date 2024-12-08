// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaceTrack.generated.h"

class USplineComponent;
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
};
