// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelGenerator.h"
#include "Engine/LevelStreaming.h"
#include "Kismet/GameplayStatics.h"



// Sets default values
ALevelGenerator::ALevelGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALevelGenerator::BeginPlay()
{
	Super::BeginPlay();

	TArray<FName> LevelNames = { "Test_T1", "Test_T2","Test_T3"};
	

	for(int x = 0; x < NumX; x++)
	{
		for(int y = 0; y < NumY; y++)
		{
			ULevelStreaming* StreamingLevel;
			FName RandLevelName = LevelNames[FMath::RandRange(0, LevelNames.Max() - 1)];
						
			float posX = (x * GridSize) - ((NumX * GridSize) / 2);
			float posY = (y * GridSize) - ((NumY * GridSize) / 2);

			StreamingLevel = UGameplayStatics::GetStreamingLevel(GetWorld(), RandLevelName)->CreateInstance(FString(FString::FromInt(x) + "x" + FString::FromInt(y)));
			StreamingLevel->LevelTransform = FTransform((FVector(posX, posY, 0)));
			StreamingLevel->SetShouldBeLoaded(true);
			StreamingLevel->SetShouldBeVisible(true);
			

			/*ULevelStreaming* Level = CreateInstance(StreamingLevel, FString(FString::FromInt(x) + "x" + FString::FromInt(y)));
			Level->LevelTransform = FTransform(FVector(posX, posY, 0));
			Level->SetShouldBeLoaded(true);
			Level->SetShouldBeVisible(true);*/
				
		}
	}
}

// Called every frame
void ALevelGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



//ULevelStreaming* ALevelGenerator::CreateInstance(ULevelStreaming* Level, FString InstanceUniqueName)
//{
//	ULevelStreaming* StreamingLevelInstance = nullptr;
//
//	UWorld* InWorld = Level->GetWorld();
//	if (InWorld)
//	{
//		// Create instance long package name 
//		FString InstanceShortPackageName = InWorld->StreamingLevelsPrefix + FPackageName::GetShortName(InstanceUniqueName);
//		FString InstancePackagePath = FPackageName::GetLongPackagePath(Level->GetWorldAssetPackageName()) + TEXT("/");
//		FName	InstanceUniquePackageName = FName(*(InstancePackagePath + InstanceShortPackageName));
//
//		// check if instance name is unique among existing streaming Level objects
//		const bool bUniqueName = (InWorld->GetStreamingLevels().IndexOfByPredicate(ULevelStreaming::FPackageNameMatcher(InstanceUniquePackageName)) == INDEX_NONE);
//
//		if (bUniqueName)
//		{
//			StreamingLevelInstance = NewObject<ULevelStreaming>(InWorld, Level->GetClass(), NAME_None, RF_Transient, NULL);
//			// new Level streaming instance will load the same map package as this object
//			StreamingLevelInstance->PackageNameToLoad = (Level->PackageNameToLoad == NAME_None ? Level->GetWorldAssetPackageFName() : Level->PackageNameToLoad);
//			// under a provided unique name
//			StreamingLevelInstance->SetWorldAssetByPackageName(InstanceUniquePackageName);
//			StreamingLevelInstance->SetShouldBeLoaded(false);
//			StreamingLevelInstance->SetShouldBeVisible(false);
//			StreamingLevelInstance->LevelTransform = Level->LevelTransform;
//
//			// add a new instance to streaming Level list
//			InWorld->AddStreamingLevel(StreamingLevelInstance);
//		}
//		else
//		{
//			UE_LOG(LogStreaming, Warning, TEXT("Provided streaming Level instance name is not unique: %s"), *InstanceUniquePackageName.ToString());
//		}
//	}
//
//	return StreamingLevelInstance;
//}