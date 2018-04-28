// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine.h"

void UTankTrack::SetThrottle(float Throttle) {
	// auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle set to: %f!!!"), *Name, Throttle);
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	AddForceAtLocation(ForceApplied, ForceLocation);
}


