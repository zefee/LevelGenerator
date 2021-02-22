#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProceduralMeshComponent.h"
#include "MeshGeneration.generated.h"



UCLASS()
class LEVELGENERATOR_API AMeshGeneration : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshGeneration();

protected:
	
	virtual void PostActorCreated() override;
	virtual void PostLoad() override;

public:	

	UProceduralMeshComponent* ThisMesh;

	TArray<FVector>Vertices;
	TArray<int32>Triangles;
	TArray<FVector>Normals;
	TArray<FProcMeshTangent>Tangents;
	TArray<FVector2D>UVs;
	TArray<FLinearColor>Colours;

	void GenerateMesh(FVector First, FVector Second, FVector Third, int32 TriIndexCount, FProcMeshTangent TangSetup);
	
	void AddTriangle(FVector TopLeft, FVector BottomLeft, FVector BottomRight, int32& TriIndex, FProcMeshTangent Tangent);

};
