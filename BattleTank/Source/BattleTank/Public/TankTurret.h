// Copyright @ArvindRawat
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	void Azimuth(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere, Category = "Setup")
	float MaxDegreesPerSecond = 25;
};
