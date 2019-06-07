// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:

	ATank* GetTankControlled() const;

	virtual void BeginPlay() override;

	void Tick(float DeltaTime) override;

	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

	bool GetLookDirection(FVector2D& ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector& LookDirection, FVector& OutHitLocation) const;

	
};