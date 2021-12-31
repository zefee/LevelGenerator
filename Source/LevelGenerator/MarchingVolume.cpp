#include "MarchingVolume.h"

// Sets default values
AMarchingVolume::AMarchingVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ThisMesh = CreateDefaultSubobject<UProceduralMeshComponent>("GeneratedMesh");
	SetRootComponent(ThisMesh);

	voxels.SetNum((cubeSize + 1) * (cubeSize + 1) * (cubeSize + 1));

	Noise = new FastNoiseLite();
	Noise->SetFrequency(Frequency);
	Noise->SetNoiseType(FastNoiseLite::NoiseType_Perlin);
	Noise->SetFractalType(FastNoiseLite::FractalType_FBm);

}

// Called when the game starts or when spawned
void AMarchingVolume::BeginPlay()
{
	Super::BeginPlay();

	GenerateHeightMap();
	Generate();
	ApplyMesh();
}



void AMarchingVolume::GenerateHeightMap() 
{

	FVector position = GetActorLocation() / volumeScale;
	for (int x = 0; x <= cubeSize; ++x)
	{
		for (int y = 0; y <= cubeSize; ++y)
		{
			for (int z = 0; z <= cubeSize; ++z)
			{
				voxels[GetVoxelIndex(x, y, z)] = Noise->GetNoise(x + position.X, y + position.Y, z + position.Z);
			}
		}
	}
}


void AMarchingVolume::Generate() 
{

	float cube[8];

	// The triangle order needs to change
	// depending on which direction the 
	// triangle is going to face
	if (isoLevel > 0.0f)
	{
		triangleOrder[0] = 0;
		triangleOrder[1] = 1;
		triangleOrder[2] = 2;
	}
	else
	{
		triangleOrder[0] = 2;
		triangleOrder[1] = 1;
		triangleOrder[2] = 0;
	}

	for (int x = 0; x < cubeSize; ++x)
	{
		for (int y = 0; y < cubeSize; ++y)
		{
			for (int z = 0; z < cubeSize; ++z)
			{
				for (int i = 0; i < 8; ++i) 
				{
					cube[i] = voxels[GetVoxelIndex(x + vertexOffset[i][0], y + vertexOffset[i][1], z + vertexOffset[i][2])];
				}

				March(x, y, z, cube);
			}
		}
	}
}

void AMarchingVolume::March(int X, int Y, int Z, const float cubeCorner[8]) {

	int edgeTableIndex = 0;
	
	// Calculate the unique index for each cube
	// to figure out if it's inside or outside of the surface level
	if (cubeCorner[0] < isoLevel)
	{
		edgeTableIndex |= 1;
	}
	if (cubeCorner[1] < isoLevel)
	{
		edgeTableIndex |= 2;
	}
	if (cubeCorner[2] < isoLevel)
	{
		edgeTableIndex |= 4;
	}
	if (cubeCorner[3] < isoLevel)
	{
		edgeTableIndex |= 8;
	}
	if (cubeCorner[4] < isoLevel)
	{
		edgeTableIndex |= 16;
	}
	if (cubeCorner[5] < isoLevel)
	{
		edgeTableIndex |= 32;
	}
	if (cubeCorner[6] < isoLevel)
	{
		edgeTableIndex |= 64;
	}
	if (cubeCorner[7] < isoLevel)
	{
		edgeTableIndex |= 128;
	} 

	// Check which corners were below the iso level
	// and set up the verts for each of the edges
	// that are going to generate triangles
	FVector vertList[12];
	if (edgeTable[edgeTableIndex] == 0)
	{
		return;
	}
	if (edgeTable[edgeTableIndex] & 1)
	{
		vertList[0].X = X + (vertexOffset[0][0] + InterpolateVerts(cubeCorner[0], cubeCorner[1]) * edgeDirection[0][0]);
		vertList[0].Y = Y + (vertexOffset[0][1] + InterpolateVerts(cubeCorner[0], cubeCorner[1]) * edgeDirection[0][1]);
		vertList[0].Z = Z + (vertexOffset[0][2] + InterpolateVerts(cubeCorner[0], cubeCorner[1]) * edgeDirection[0][2]);
	}
	if (edgeTable[edgeTableIndex] & 2)
	{
		vertList[1].X = X + (vertexOffset[1][0] + InterpolateVerts(cubeCorner[1], cubeCorner[2]) * edgeDirection[1][0]);
		vertList[1].Y = Y + (vertexOffset[1][1] + InterpolateVerts(cubeCorner[1], cubeCorner[2]) * edgeDirection[1][1]);
		vertList[1].Z = Z + (vertexOffset[1][2] + InterpolateVerts(cubeCorner[1], cubeCorner[2]) * edgeDirection[1][2]);
	}
	if (edgeTable[edgeTableIndex] & 4)
	{
		vertList[2].X = X + (vertexOffset[2][0] + InterpolateVerts(cubeCorner[2], cubeCorner[3]) * edgeDirection[2][0]);
		vertList[2].Y = Y + (vertexOffset[2][1] + InterpolateVerts(cubeCorner[2], cubeCorner[3]) * edgeDirection[2][1]);
		vertList[2].Z = Z + (vertexOffset[2][2] + InterpolateVerts(cubeCorner[2], cubeCorner[3]) * edgeDirection[2][2]);
	}
	if (edgeTable[edgeTableIndex] & 8)
	{
		vertList[3].X = X + (vertexOffset[3][0] + InterpolateVerts(cubeCorner[3], cubeCorner[0]) * edgeDirection[3][0]);
		vertList[3].Y = Y + (vertexOffset[3][1] + InterpolateVerts(cubeCorner[3], cubeCorner[0]) * edgeDirection[3][1]);
		vertList[3].Z = Z + (vertexOffset[3][2] + InterpolateVerts(cubeCorner[3], cubeCorner[0]) * edgeDirection[3][2]);
	}
	if (edgeTable[edgeTableIndex] & 16)
	{
		vertList[4].X = X + (vertexOffset[4][0] + InterpolateVerts(cubeCorner[4], cubeCorner[5]) * edgeDirection[4][0]);
		vertList[4].Y = Y + (vertexOffset[4][1] + InterpolateVerts(cubeCorner[4], cubeCorner[5]) * edgeDirection[4][1]);
		vertList[4].Z = Z + (vertexOffset[4][2] + InterpolateVerts(cubeCorner[4], cubeCorner[5]) * edgeDirection[4][2]);
	}
	if (edgeTable[edgeTableIndex] & 32)
	{
		vertList[5].X = X + (vertexOffset[5][0] + InterpolateVerts(cubeCorner[5], cubeCorner[6]) * edgeDirection[5][0]);
		vertList[5].Y = Y + (vertexOffset[5][1] + InterpolateVerts(cubeCorner[5], cubeCorner[6]) * edgeDirection[5][1]);
		vertList[5].Z = Z + (vertexOffset[5][2] + InterpolateVerts(cubeCorner[5], cubeCorner[6]) * edgeDirection[5][2]);
	}
	if (edgeTable[edgeTableIndex] & 64)
	{
		vertList[6].X = X + (vertexOffset[6][0] + InterpolateVerts(cubeCorner[6], cubeCorner[7]) * edgeDirection[6][0]);
		vertList[6].Y = Y + (vertexOffset[6][1] + InterpolateVerts(cubeCorner[6], cubeCorner[7]) * edgeDirection[6][1]);
		vertList[6].Z = Z + (vertexOffset[6][2] + InterpolateVerts(cubeCorner[6], cubeCorner[7]) * edgeDirection[6][2]);
	}
	if (edgeTable[edgeTableIndex] & 128)
	{
		vertList[7].X = X + (vertexOffset[7][0] + InterpolateVerts(cubeCorner[7], cubeCorner[4]) * edgeDirection[7][0]);
		vertList[7].Y = Y + (vertexOffset[7][1] + InterpolateVerts(cubeCorner[7], cubeCorner[4]) * edgeDirection[7][1]);
		vertList[7].Z = Z + (vertexOffset[7][2] + InterpolateVerts(cubeCorner[7], cubeCorner[4]) * edgeDirection[7][2]);
	}
	if (edgeTable[edgeTableIndex] & 256)
	{
		vertList[8].X = X + (vertexOffset[0][0] + InterpolateVerts(cubeCorner[0], cubeCorner[4]) * edgeDirection[8][0]);
		vertList[8].Y = Y + (vertexOffset[0][1] + InterpolateVerts(cubeCorner[0], cubeCorner[4]) * edgeDirection[8][1]);
		vertList[8].Z = Z + (vertexOffset[0][2] + InterpolateVerts(cubeCorner[0], cubeCorner[4]) * edgeDirection[8][2]);
	}
	if (edgeTable[edgeTableIndex] & 512)
	{
		vertList[9].X = X + (vertexOffset[1][0] + InterpolateVerts(cubeCorner[1], cubeCorner[5]) * edgeDirection[9][0]);
		vertList[9].Y = Y + (vertexOffset[1][1] + InterpolateVerts(cubeCorner[1], cubeCorner[5]) * edgeDirection[9][1]);
		vertList[9].Z = Z + (vertexOffset[1][2] + InterpolateVerts(cubeCorner[1], cubeCorner[5]) * edgeDirection[9][2]);
	}
	if (edgeTable[edgeTableIndex] & 1024)
	{
		vertList[10].X = X + (vertexOffset[2][0] + InterpolateVerts(cubeCorner[2], cubeCorner[6]) * edgeDirection[10][0]);
		vertList[10].Y = Y + (vertexOffset[2][1] + InterpolateVerts(cubeCorner[2], cubeCorner[6]) * edgeDirection[10][1]);
		vertList[10].Z = Z + (vertexOffset[2][2] + InterpolateVerts(cubeCorner[2], cubeCorner[6]) * edgeDirection[10][2]);
	}
	if (edgeTable[edgeTableIndex] & 2048)
	{
		vertList[11].X = X + (vertexOffset[3][0] + InterpolateVerts(cubeCorner[3], cubeCorner[7]) * edgeDirection[11][0]);
		vertList[11].Y = Y + (vertexOffset[3][1] + InterpolateVerts(cubeCorner[3], cubeCorner[7]) * edgeDirection[11][1]);
		vertList[11].Z = Z + (vertexOffset[3][2] + InterpolateVerts(cubeCorner[3], cubeCorner[7]) * edgeDirection[11][2]);
	} 

	// Add all the data required for each cube
	// with a maximum of 5 triangles per cube
	for (int i = 0; triTable[edgeTableIndex][i] != -1; i += 3) {
		FVector Vert1 = vertList[triTable[edgeTableIndex][i]] * volumeScale;
		FVector Vert2 = vertList[triTable[edgeTableIndex][i + 1]] * volumeScale;
		FVector Vert3 = vertList[triTable[edgeTableIndex][i + 2]] * volumeScale;

		FVector Normal = FVector::CrossProduct(Vert2 - Vert1, Vert3 - Vert1);

		FColor Colour = FColor::Green;

		Normal.Normalize();

		MeshData.Vertices.Append({ Vert1, Vert2, Vert3 });

		MeshData.Triangles.Append({ vertexCount + triangleOrder[0], vertexCount + triangleOrder[1], vertexCount + triangleOrder[2]});

		MeshData.Normals.Append({ Normal, Normal, Normal });

		MeshData.Colours.Append({ Colour, Colour, Colour });

		vertexCount+= 3;
	}

}

void AMarchingVolume::ApplyMesh() {

	ThisMesh->CreateMeshSection(0, MeshData.Vertices, MeshData.Triangles, MeshData.Normals, MeshData.UVs, MeshData.Colours, TArray<FProcMeshTangent>(), true);
}

int AMarchingVolume::GetVoxelIndex(int X, int Y, int Z) {

	return Z * (cubeSize + 1) * (cubeSize + 1) + Y * (cubeSize + 1) + X;;

}

float AMarchingVolume::InterpolateVerts(float vert1, float vert2)
{
	return (isoLevel - vert1) / (vert2 - vert1);
}