// Copyright @ArvindRawat

#include "TankTurret.h"

void UTankTurret::Azimuth(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto AzimuthChange = RelativeSpeed * MaxDegreesPerSecond*GetWorld()->DeltaTimeSeconds;
	auto YawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;

	SetRelativeRotation(FRotator(0, YawNewAzimuth,0));
}
