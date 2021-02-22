#include "MeshGeneration.h"

AMeshGeneration::AMeshGeneration()
{
	//ThisMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("GeneratedMesh"));
}


void AMeshGeneration::PostActorCreated()
{
	Super::PostActorCreated();
//	GenerateMesh();
}

void AMeshGeneration::PostLoad()
{
	Super::PostLoad();
//	GenerateMesh();
}

void AMeshGeneration::GenerateMesh(FVector First, FVector Second, FVector Third, int32 TriIndexCount, FProcMeshTangent TangSetup)
{
	/*Vertices.Reset();
	Triangles.Reset();
	Normals.Reset();
	Tangents.Reset();
	UVs.Reset();
	Colours.Reset();
	*/
	int32 TriangleIndexCount = 0;
	FVector DefinedShape[3];
	FProcMeshTangent TangentSetup;

	TangentSetup = FProcMeshTangent(0.0f, 1.0f, 0.0f);

	AddTriangle(First, Second, Third, TriIndexCount, TangSetup);

	ThisMesh->CreateMeshSection_LinearColor(0, Vertices, Triangles, Normals, UVs, Colours, Tangents, true);
}


void AMeshGeneration::AddTriangle(FVector TopLeft, FVector BottomLeft, FVector BottomRight, int32& TriIndex, FProcMeshTangent Tangent)
{
	int32 Point1 = TriIndex++;
	int32 Point2 = TriIndex++;
	int32 Point3 = TriIndex++;

	Vertices.Add(TopLeft);
	Vertices.Add(BottomLeft);
	Vertices.Add(BottomRight);

	Triangles.Add(Point1);
	Triangles.Add(Point2);
	Triangles.Add(Point3);

	

	//FVector ThisNorm = FIntVector::CrossProduct(TopLeft, BottomRight).GetSafeNormal();

	for (int i = 0; i < 3; i++)
	{
		//Normals.Add(ThisNorm);
		Tangents.Add(Tangent);
		Colours.Add(FLinearColor::Green);
	}
	UVs.Add(FVector2D(0.0f, 1.0f)); //Top Left
	UVs.Add(FVector2D(0.0f, 0.0f)); //Bottom Left
	UVs.Add(FVector2D(1.0f, 0.0f)); //Bottom Right
}

