// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "TankAimingComponent.h"
#include "Engine.h"
#include "BattleTank.h"

void UTankBarrel::Elevate(float RelativeSpeed) {
	//auto Time = GetWorld()->GetTimeSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("%f: Barrel->Elevate() called at speed %f"), Time, RelativeSpeed);
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinDegreesElevation, MaxDegreesElevation);
	SetRelativeRotation(FRotator(Elevation, 0, 0));

}



