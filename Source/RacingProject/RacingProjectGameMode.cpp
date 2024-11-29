// Copyright Epic Games, Inc. All Rights Reserved.

#include "RacingProjectGameMode.h"
#include "RacingProjectPlayerController.h"

ARacingProjectGameMode::ARacingProjectGameMode()
{
	PlayerControllerClass = ARacingProjectPlayerController::StaticClass();
}
