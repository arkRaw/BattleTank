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

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<ASprungWheel*> ResultArray;
	TArray<USceneComponent*> Children;
	GetChildrenComponents(true, Children);

	for (const auto& Child : Children)
	{
		auto SpawnPointChild = Cast<USpawnPoint>(Child);
		if (!SpawnPointChild) continue;

		auto SpawnedChild = SpawnPointChild->GetSpawnedActor();

		auto SprungWheel = Cast<ASprungWheel>(SpawnedChild);
		if (!SprungWheel) continue;

		ResultArray.Add(SprungWheel);
	}

	return ResultArray;
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