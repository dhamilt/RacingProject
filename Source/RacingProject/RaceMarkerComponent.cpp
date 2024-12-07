// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceMarkerComponent.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
URaceMarkerComponent::URaceMarkerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

}


FQuat URaceMarkerComponent::FindLookRotation()
{
	// Set the arbituary axis for rotation to the X-Axis
	FVector axisOfRotation = FVector(0, 0, 1);

	// Find how much the component needs to rotate to point towards the target
	FVector lookDir = GetForwardVector();
	FVector targetLoc = target.Get()->GetActorLocation();
	float dot = lookDir.Dot(targetLoc);
	float angle = FMath::Acos(dot);
	FRotator rot = FRotationMatrix::MakeFromX(targetLoc - GetRelativeLocation()).Rotator();
	return rot.Quaternion();
}

// Called when the game starts
void URaceMarkerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void URaceMarkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if(target.Get())
		SetRelativeRotation( UKismetMathLibrary::FindLookAtRotation(GetComponentLocation(), target->GetActorLocation()).GetInverse());
}

