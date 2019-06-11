// Copyright @ArvindRawat

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	auto PlayerTank = Cast<ATank>( GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	// Move towards player
	if (!ensure(PlayerTank)) { return; }
	MoveToActor(PlayerTank, AcceptanceRadius);


	// Aim towards player
	
	ControlledTank->AimAt((PlayerTank)->GetActorLocation());

	// Fire if ready

	ControlledTank->Fire();
}