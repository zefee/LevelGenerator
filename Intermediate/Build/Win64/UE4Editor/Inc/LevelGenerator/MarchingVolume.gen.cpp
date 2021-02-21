// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "LevelGenerator/MarchingVolume.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMarchingVolume() {}
// Cross Module References
	LEVELGENERATOR_API UClass* Z_Construct_UClass_AMarchingVolume_NoRegister();
	LEVELGENERATOR_API UClass* Z_Construct_UClass_AMarchingVolume();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_LevelGenerator();
// End Cross Module References
	void AMarchingVolume::StaticRegisterNativesAMarchingVolume()
	{
	}
	UClass* Z_Construct_UClass_AMarchingVolume_NoRegister()
	{
		return AMarchingVolume::StaticClass();
	}
	struct Z_Construct_UClass_AMarchingVolume_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMarchingVolume_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_LevelGenerator,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMarchingVolume_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MarchingVolume.h" },
		{ "ModuleRelativePath", "MarchingVolume.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMarchingVolume_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMarchingVolume>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMarchingVolume_Statics::ClassParams = {
		&AMarchingVolume::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMarchingVolume_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMarchingVolume_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMarchingVolume()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMarchingVolume_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMarchingVolume, 2966119070);
	template<> LEVELGENERATOR_API UClass* StaticClass<AMarchingVolume>()
	{
		return AMarchingVolume::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMarchingVolume(Z_Construct_UClass_AMarchingVolume, &AMarchingVolume::StaticClass, TEXT("/Script/LevelGenerator"), TEXT("AMarchingVolume"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMarchingVolume);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
