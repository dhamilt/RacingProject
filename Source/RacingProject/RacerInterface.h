// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "RacerInterface.generated.h"

/** Signature for when racer has finished lap count */
DECLARE_DYNAMIC_DELEGATE(FOnRaceFinished);

/** Signature for when racer finished a lap*/
DECLARE_DYNAMIC_DELEGATE(FOnLapFinished);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class URacerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RACINGPROJECT_API IRacerInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	int32 currentLap = 0;

	int32 numOfLapsForRace = 3;

	FOnRaceFinished OnRaceFinished;

	FOnLapFinished OnLapFinished;

	virtual void UpdateCheckpointInfo(int32 checkpointNumber) = 0;

	virtual void UpdateLap() = 0;
};
