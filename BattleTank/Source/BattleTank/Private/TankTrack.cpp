// Copyright @ArvindRawat

#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
}

void  UTankTrack::SetThrottle(float Throttle)
{
	auto CurrentThrottle = FMath::Clamp<float>(Throttle, -1, +1);
	DriveTrack(CurrentThrottle);
}

TArray<class ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<USceneComponent*> OutSpawnPoints;
	GetChildrenComponents(false, OutSpawnPoints);
	TArray<ASprungWheel*> SprungWheels;
	SprungWheels.Init(nullptr, OutSpawnPoints.Num());

	for (int32 i = 0; i < SprungWheels.Num(); ++i)
	{
		SprungWheels[i] = (Cast<USpawnPoint>(OutSpawnPoints[i]))->GetSprungWheel();
	}
	
	return SprungWheels;
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	auto ForceApplied = TrackMaxDrivingForce*CurrentThrottle;
	auto Wheels = GetWheels();
	auto ForcePerWheel = ForceApplied / Wheels.Num();
	for (auto Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}