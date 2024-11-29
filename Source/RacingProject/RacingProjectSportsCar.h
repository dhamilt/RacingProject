// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RacingProjectPawn.h"
#include "RacingProjectSportsCar.generated.h"

/**
 *  Sports car wheeled vehicle implementation
 */
UCLASS(abstract)
class RACINGPROJECT_API ARacingProjectSportsCar : public ARacingProjectPawn
{
	GENERATED_BODY()
	
public:

	ARacingProjectSportsCar();
};
