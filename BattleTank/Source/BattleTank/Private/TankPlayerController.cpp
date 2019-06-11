// Copyright @ArvindRawat

#include "TankPlayerController.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) { return; }
	FoundAimingComponent(AimingComponent);
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(GetPawn()) || !ensure(AimingComponent)) { return; }
	FVector OutHitLocation;
	if (GetSightRayHitLocation(OutHitLocation))
	{
		AimingComponent->AimAt(OutHitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the crosshair position in pixel co-ordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX*CrossHairXLocation,ViewportSizeY*CrossHairYLocation);
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation,LookDirection))
	{
		// line trace along the look direction upto max range
		if (GetLookVectorHitLocation(LookDirection, OutHitLocation))
		{
		}
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D & ScreenLocation, FVector & LookDirection) const
{
	FVector  CameraWorldLocation;
	// "De-project" the screen position to a world direction
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& LookDirection,FVector& OutHitLocation) const
{
	FHitResult OutHitResult;
	FVector StartLocation= PlayerCameraManager->GetCameraLocation();


	FVector EndLocation = StartLocation + LookDirection * LineTraceRange;
	FCollisionQueryParams Params(FName("None"),false, GetOwner());
	
	if (GetWorld()->LineTraceSingleByChannel(
		OutHitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility
		)
	)
	{
		OutHitLocation = OutHitResult.Location;
		return true;
	}
	OutHitLocation = FVector(0.f);
	return false;
}