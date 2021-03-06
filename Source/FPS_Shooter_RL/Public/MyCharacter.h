// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"


UCLASS()
class FPS_SHOOTER_RL_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

		
	UPROPERTY(EditAnywhere, Category = Mesh)
	class USkeletalMeshComponent* MeshFov;

	UPROPERTY(EditAnywhere)
	class UCameraComponent* Camera;

	
	
public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	UFUNCTION(BlueprintCallable)
	static void HandleTargets(UPARAM(ref) TArray<FVector>& InputLocations, TArray<FVector>& OutputLocations);
};