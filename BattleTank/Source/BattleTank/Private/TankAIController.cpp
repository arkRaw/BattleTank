// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

ATank* ATankAIController::GetTankControlled() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* ControlledTank = GetTankControlled();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing Tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possesing : %s"), *ControlledTank->GetName())
	}
}
