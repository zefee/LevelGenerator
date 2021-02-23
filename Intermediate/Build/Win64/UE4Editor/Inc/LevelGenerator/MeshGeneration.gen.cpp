// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelGenerator/MeshGeneration.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMeshGeneration() {}
// Cross Module References
	LEVELGENERATOR_API UClass* Z_Construct_UClass_AMeshGeneration_NoRegister();
	LEVELGENERATOR_API UClass* Z_Construct_UClass_AMeshGeneration();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LevelGenerator();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void AMeshGeneration::StaticRegisterNativesAMeshGeneration()
	{
	}
	UClass* Z_Construct_UClass_AMeshGeneration_NoRegister()
	{
		return AMeshGeneration::StaticClass();
	}
	struct Z_Construct_UClass_AMeshGeneration_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThisMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ThisMesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMeshGeneration_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LevelGenerator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMeshGeneration_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MeshGeneration.h" },
		{ "ModuleRelativePath", "MeshGeneration.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMeshGeneration_Statics::NewProp_ThisMesh_MetaData[] = {
		{ "Category", "MeshGeneration" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "MeshGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMeshGeneration_Statics::NewProp_ThisMesh = { "ThisMesh", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMeshGeneration, ThisMesh), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMeshGeneration_Statics::NewProp_ThisMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMeshGeneration_Statics::NewProp_ThisMesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMeshGeneration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMeshGeneration_Statics::NewProp_ThisMesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMeshGeneration_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMeshGeneration>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMeshGeneration_Statics::ClassParams = {
		&AMeshGeneration::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMeshGeneration_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMeshGeneration_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMeshGeneration_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMeshGeneration_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMeshGeneration()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMeshGeneration_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMeshGeneration, 2961671355);
	template<> LEVELGENERATOR_API UClass* StaticClass<AMeshGeneration>()
	{
		return AMeshGeneration::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMeshGeneration(Z_Construct_UClass_AMeshGeneration, &AMeshGeneration::StaticClass, TEXT("/Script/LevelGenerator"), TEXT("AMeshGeneration"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMeshGeneration);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
