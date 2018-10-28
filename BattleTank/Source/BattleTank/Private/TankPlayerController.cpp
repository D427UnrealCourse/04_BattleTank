// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"
#include "Engine.h"

//  Tick
	//  Super
	//  AimTowardsCrosshair();

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
}

ATank* ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
		//  TODO Tell controlled tank to aim at this point
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const {
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D((ViewportSizeX * CrosshairXLoc), (ViewportSizeY * CrosshairYLoc));
	FVector CameraWorldLoc;
	FVector LookDirection;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLoc, LookDirection)) {
		// UE_LOG(LogTemp, Warning, TEXT("Look direction: %s"), *WorldDirection.ToString());
		FHitResult HitResult;
		auto StartLocation = PlayerCameraManager->GetCameraLocation();
		auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility)) {
			HitLocation = HitResult.Location;
			return true;
		}
		HitLocation = FVector(0);
		return false;
	}
	return false;
}