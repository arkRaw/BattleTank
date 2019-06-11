// Copyright @ArvindRawat

#include "TankTrack.h"

void  UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector()*TrackMaxDrivingForce*Throttle;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	if (!ensure(TankRoot)) { return; }
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}