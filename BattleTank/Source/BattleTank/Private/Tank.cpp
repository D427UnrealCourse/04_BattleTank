// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "BattleTank.h"
#include "Projectile.h"
#include "TankAimingComponent.h"
#include "Engine.h"

// Sets default values
ATank::ATank() {
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay() {
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation) {
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATank::Fire() {
	auto Time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("!!! Tank Fires !!!"))

	if (!Barrel) { return; }
	auto Projectile = GetWorld()->SpawnActor<class AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
	);
	Projectile->LaunchProjectile(LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet) {
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet) {
	TankAimingComponent->SetTurretReference(TurretToSet);
}