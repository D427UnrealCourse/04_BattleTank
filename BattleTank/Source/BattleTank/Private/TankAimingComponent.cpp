// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "BattleTank.h"
#include "Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true; // TODO should this really tick?

	// ...
}

void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet) {
	Barrel = BarrelToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
	if (!Barrel) { return; }
	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	auto Time = GetWorld()->GetTimeSeconds();
	if (UGameplayStatics::SuggestProjectileVelocity(
		this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			auto BarrelRotator = Barrel->GetForwardVector().Rotation();
			auto AimAsRotator = AimDirection.Rotation();
			auto DeltaRotator = AimAsRotator - BarrelRotator;
			// UE_LOG(LogTemp, Warning, TEXT("AimAsRotator: %s"), *AimAsRotator.ToString())
			Barrel->Elevate(5);
			UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time)
	} else {
		UE_LOG(LogTemp, Warning, TEXT("%f: No Aim solution found"), Time)
	}
}

/*
void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
	auto BarrelRotation = Barrel->GetForwardVector();
}

*/