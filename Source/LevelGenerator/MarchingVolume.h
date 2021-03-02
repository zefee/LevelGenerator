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

	float cubeSize = 100.f;
	float volume [100][100][100];
	float isoLevel = 0.5f;
	float cubeCorners[8][3];

	float data[100 * 100 * 100];
	
	AMeshGeneration* triGenerator;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	float interpolateVerts(float iso, float vert1[3], float vert2[3], float scalar1, float scalar2);
	void Generate();


};
