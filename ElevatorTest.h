// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElevatorTest.generated.h"

UCLASS()
class TESTPROJECT_API AElevatorTest : public AActor
{
	GENERATED_BODY()

public:
	bool liftingup;
	bool liftingdown;
	bool movedone;
	bool waiting;
	int framecounter;
	UPROPERTY(Category = "Elevator properties", EditAnywhere, meta = (ClampMin = "0", UIMin = "0"))
		float movespeed;
	UPROPERTY(Category = "Elevator properties", EditAnywhere, meta = (ClampMin = "0", UIMin = "0"))
		float movedistance;
	UPROPERTY(Category = "Elevator properties", EditAnywhere, meta = (ClampMin = "0", UIMin = "0"))
		float interval;
	FVector initialposition;
	AElevatorTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InitMove();
};