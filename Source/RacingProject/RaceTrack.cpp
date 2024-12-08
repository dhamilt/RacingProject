// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceTrack.h"
#include "Components/SplineComponent.h"
#include "Components/HierarchicalInstancedStaticMeshComponent.h"

// Sets default values
ARaceTrack::ARaceTrack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Race Track Spline
	RaceTrack = CreateDefaultSubobject<USplineComponent>(TEXT("RaceTrack"));
	RaceTrack->SetupAttachment(RootComponent);

	// Create Checkpoints
	Checkpoints = CreateDefaultSubobject<UHierarchicalInstancedStaticMeshComponent>(TEXT("Checkpoints"));
	Checkpoints->SetupAttachment(RootComponent);
}

void ARaceTrack::AddCheckpoints()
{
	if (RaceTrack->GetNumberOfSplinePoints() > 0)
	{
		int32 numOfCheckPoints = RaceTrack->GetNumberOfSplinePoints();
		for (int32 i = 0; i < numOfCheckPoints; ++i)
		{
			FSplinePoint point = RaceTrack->GetSplinePointAt(i, ESplineCoordinateSpace::Local);
			FRotator rot = point.Rotation;
			rot.Add(0, RotationOffset, 0);
			FTransform transform = FTransform::Identity;
			transform.SetLocation(point.Position);
			transform.SetRotation(rot.Quaternion());
			transform.SetScale3D(CheckpointScale);
			Checkpoints->AddInstance(transform);
		}
	}
}

// Called when the game starts or when spawned
void ARaceTrack::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARaceTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

