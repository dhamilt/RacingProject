// Fill out your copyright notice in the Description page of Project Settings.


#include "RaceTrack.h"
#include "Components/SplineComponent.h"
#include "Components/PrimitiveComponent.h"
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
			checkpointTransforms.Add(transform);
		}
	}
}

void ARaceTrack::EnableCheckpoint(int32 index)
{
	if (index < checkpointTransforms.Num())
	{
		FTransform* transform = &checkpointTransforms[index];
		transform->SetScale3D(CheckpointScale);
		Checkpoints->UpdateInstanceTransform(index, *transform, false);
	}
}



void ARaceTrack::DisableCheckpoints(int32 first, int32 last)
{
	int32 numOfInstances = Checkpoints->GetNumInstances();
	if(first > 0 && first < last)
		if (last < numOfInstances)
			for (int i = first; i <= last; ++i)
			{
				FTransform* transform = &checkpointTransforms[i];
				transform->SetScale3D(FVector::Zero());
				Checkpoints->UpdateInstanceTransform(i, *transform, false);
			}
}

void ARaceTrack::DisableCheckpoint(int32 index)
{
	if (index < checkpointTransforms.Num())
	{
		FTransform* transform = &checkpointTransforms[index];
		transform->SetScale3D(FVector::Zero());
		Checkpoints->UpdateInstanceTransform(index, *transform, false);
	}
}

void ARaceTrack::NextCheckpoint(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool FromSweep, const FHitResult& SweepResult)
{
	int32 instanceIndex = SweepResult.Item;
	DisableCheckpoint(instanceIndex);
	int32 next = instanceIndex + 1 < Checkpoints->GetNumInstances() ? instanceIndex + 1 : 0;
	EnableCheckpoint(next);
}

// Called when the game starts or when spawned
void ARaceTrack::BeginPlay()
{
	Super::BeginPlay();
	Checkpoints->OnComponentBeginOverlap.AddDynamic(this, &ARaceTrack::NextCheckpoint);
	DisableCheckpoints(1, Checkpoints->GetNumInstances() - 1);
}

// Called every frame
void ARaceTrack::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

