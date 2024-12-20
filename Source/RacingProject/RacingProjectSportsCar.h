// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RacingProjectPawn.h"
#include "VehicleInterface.h"
#include "RacingProjectSportsCar.generated.h"

class ARaceResultsManager;
class URaceMarkerComponent;

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class RACINGPROJECT_API ARacingProjectSportsCar : public ARacingProjectPawn, public IVehicleInterface
{
	GENERATED_BODY()
	
public:

	ARacingProjectSportsCar();

	virtual void UpdateCheckpointInfo(int32 checkpointNumber) override;
private:
	int32 _checkpointNumber;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Race Manager")
	TSoftObjectPtr<ARaceResultsManager> raceManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Marker")
	URaceMarkerComponent* raceMarker;
};
