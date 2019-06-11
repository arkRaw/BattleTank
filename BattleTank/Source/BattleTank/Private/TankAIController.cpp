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
	MoveToActor(PlayerTank, AcceptanceRadius);


	// Aim towards player
	if (PlayerTank) {
		ControlledTank->AimAt((PlayerTank)->GetActorLocation());
		ControlledTank->Fire();
	}
	// Fire if ready
}