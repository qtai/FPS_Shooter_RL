// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelGenerator.generated.h"

class ULevelStreaming;

UCLASS()
class FPS_SHOOTER_RL_API ALevelGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALevelGenerator();

private:

	//ULevelStreaming* CreateInstance(ULevelStreaming* Level, FString InstanceUniqueName);

	int16 NumX = 5, NumY = 5;
	int32 GridSize = 2000;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
