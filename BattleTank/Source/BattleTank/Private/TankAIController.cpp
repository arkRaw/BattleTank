// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"

ATank* ATankAIController::GetTankControlled() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find PlayerTank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player : %s"), *PlayerTank->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// TODO Move Towards Player

	// Aim towards player
	if (GetPlayerTank()) {
		GetTankControlled()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	// Fire if ready
}
