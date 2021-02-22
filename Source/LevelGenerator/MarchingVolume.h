#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MeshGeneration.h"
#include "MarchingVolume.generated.h"

UCLASS()
class LEVELGENERATOR_API AMarchingVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMarchingVolume();

	float data[100 * 100 * 100];
	
	AMeshGeneration* triGenerator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Generate();

};
