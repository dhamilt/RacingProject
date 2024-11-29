// Copyright Epic Games, Inc. All Rights Reserved.

#include "RacingProjectWheelFront.h"
#include "UObject/ConstructorHelpers.h"

URacingProjectWheelFront::URacingProjectWheelFront()
{
	AxleType = EAxleType::Front;
	bAffectedBySteering = true;
	MaxSteerAngle = 40.f;
}