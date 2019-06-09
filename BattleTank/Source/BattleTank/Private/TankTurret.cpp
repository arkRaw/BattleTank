// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto YawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;

	auto Azimuth = FMath::Clamp(YawNewAzimuth, -180.f, 179.f);

	SetRelativeRotation(FRotator(0,Azimuth,0));
}
