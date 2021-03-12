#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"
#include "MeshGeneration.h"
#include "MarchingVolume.generated.h"




UCLASS()
class LEVELGENERATOR_API AMarchingVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMarchingVolume();

private:

	float cubeSize = 4.f;
	FVector cubeCorn[8];
	TArray<FVector> voxelVolume;
	float isoLevel = 0.1f;
	float volumeScale = 100;

	AMeshGeneration* triGenerator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	FVector interpolateVerts(float iso, FVector vert1, FVector vert2);
	void GenerateVoxelVolume();
	void Generate();

};
