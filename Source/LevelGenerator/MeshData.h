// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MeshData.generated.h"

USTRUCT()
struct FMeshData
{
	GENERATED_BODY()

public:
	TArray<FVector>Vertices;
	TArray<int>Triangles;
	TArray<FVector>Normals;
	TArray<FVector2D>UVs;
	TArray<FColor>Colours;
};
