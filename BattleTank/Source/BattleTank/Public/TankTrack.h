// Copyright @ArvindRawat
#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 40000000;
private:
	void ApplySidewaysForce();
	UTankTrack();
	float CurrentThrottle = 0;
	virtual void BeginPlay() override;
	void DriveTrack();

	UFUNCTION()
	void OnHit(UPrimitiveComponent*HitComponent, AActor*OtherActor, UPrimitiveComponent*OtherComp, FVector NormalImpulse, const FHitResult&Hit);
};
