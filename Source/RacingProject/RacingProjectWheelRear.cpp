// Copyright Epic Games, Inc. All Rights Reserved.

#include "RacingProjectWheelRear.h"
#include "UObject/ConstructorHelpers.h"

URacingProjectWheelRear::URacingProjectWheelRear()
{
	AxleType = EAxleType::Rear;
	bAffectedByHandbrake = true;
	bAffectedByEngine = true;
}