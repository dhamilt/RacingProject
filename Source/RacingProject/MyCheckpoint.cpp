// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCheckpoint.h"

//void AMyCheckpoint::OnBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* Other, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//}

AMyCheckpoint::AMyCheckpoint()
{
	OnActorBeginOverlap.AddDynamic(this, &AMyCheckpoint::UpdateVehicle);
}

void AMyCheckpoint::UpdateVehicle(AActor* OverlappedActor, AActor* OtherActor)
{
}
