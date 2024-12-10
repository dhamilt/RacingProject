// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RacingProjectPawn.h"
#include "RacerInterface.h"
#include "RacingProjectSportsCar.generated.h"

class ARaceResultsManager;
class URaceMarkerComponent;

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class RACINGPROJECT_API ARacingProjectSportsCar : public ARacingProjectPawn, public IRacerInterface
{
	GENERATED_BODY()
	
public:

	ARacingProjectSportsCar();
	
	UFUNCTION(BlueprintPure, Category = "Race Track")
	int32 GetCurrentLap() const;
	virtual void UpdateCheckpointInfo(int32 checkpointNumber) override;
	virtual void UpdateLap() override;
private:
	int32 _checkpointNumber;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="Race Manager")
	TSoftObjectPtr<ARaceResultsManager> raceManager;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Race Marker")
	URaceMarkerComponent* raceMarker;
	
};
