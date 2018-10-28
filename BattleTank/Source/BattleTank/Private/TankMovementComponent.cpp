// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet) {
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
}


void UTankMovementComponent::IntendMoveForward(float Throw) {
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("Intend to move forward: %f"), Throw);
}

