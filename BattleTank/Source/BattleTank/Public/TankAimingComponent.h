// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringStatus :uint8 
{
	Reloading,
	Aiming,
	Locked
};

// Forward Declarations
class UTankBarrel; 
class UTankTurret;

// Hold Barrel's Properties
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadonly, Category = "State")
	EFiringStatus FiringState = EFiringStatus::Reloading;

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialse(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector OutHitLocation,float LaunchSpeed);

	UTankBarrel* GetTankBarrel();

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
