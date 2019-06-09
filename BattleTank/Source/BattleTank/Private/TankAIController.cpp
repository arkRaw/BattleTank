// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp,Warning,TEXT("AI called %s"),*GetPawn()->GetName())
	// TODO Move Towards Player
	auto PlayerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	// Aim towards player
	if (PlayerTank) {
		ControlledTank->AimAt((PlayerTank)->GetActorLocation());
		ControlledTank->Fire();
	}
	// Fire if ready
}