// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "RaceMarkerComponent.generated.h"

class UStaticMesh;


UCLASS(BlueprintType, ClassGroup=(RaceAttributes), meta=(BlueprintSpawnableComponent) )
class RACINGPROJECT_API URaceMarkerComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Marker")
	float rotationOffset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Marker")
	TSoftObjectPtr<AActor> target;

	UFUNCTION(BlueprintCallable, Category = "Race Marker")
	FRotator FindLookAtRotation();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Sets default values for this component's properties
	URaceMarkerComponent();

		
};
