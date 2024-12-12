// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCheckpoint.h"
#include "VehicleInterface.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


AMyCheckpoint::AMyCheckpoint()
{
	checkpointMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = checkpointMesh;
	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Volume"));
	boxComponent->SetupAttachment(checkpointMesh);
	boxComponent->OnComponentBeginOverlap.AddDynamic(this, &AMyCheckpoint::UpdateVehicle);
}

void AMyCheckpoint::UpdateVehicle(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IVehicleInterface* vehicleInterface = Cast<IVehicleInterface>(OtherActor))
	{
		vehicleInterface->UpdateCheckpointInfo(checkpointNumber);
	}
}
