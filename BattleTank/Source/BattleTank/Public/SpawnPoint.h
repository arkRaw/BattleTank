// Copyright @ArvindRawat

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "SpawnPoint.generated.h"

class ASprungWheel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API USpawnPoint : public USceneComponent
{
	GENERATED_BODY()

public:
//	ASprungWheel* GetSprungWheel();

	AActor* GetSpawnedActor() const;

private:
	
	// UPROPERTY because Need to be tracked by Garbage Collection System
	UPROPERTY()
	AActor* SpawnedActor = nullptr;

	// Sets default values for this component's properties
	USpawnPoint();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AActor> SpawnClassBlueprint;
};
