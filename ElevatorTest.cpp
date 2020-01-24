// Fill out your copyright notice in the Description page of Project Settings.


#include "ElevatorTest.h"

// Sets default values
AElevatorTest::AElevatorTest()
{
	PrimaryActorTick.bCanEverTick = true;
	liftingup = false;
	liftingdown = false;
	movedone = true;
	waiting = false;
	framecounter = 0;
}

void AElevatorTest::BeginPlay()
{
	Super::BeginPlay();
	initialposition = GetActorLocation();
}

void AElevatorTest::InitMove()
{
	if (movedone) {
		movedone = false;
		framecounter = 0;
		liftingup = true;
		UE_LOG(LogTemp, Log, TEXT("Starting to lift. %d --- %d"), PrimaryActorTick.bCanEverTick, movedone);
	}
}

void AElevatorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (movedone) return;
	if (waiting) {
		framecounter++;
		if (framecounter >= interval * 30) {
			waiting = false;
			liftingdown = true;
		}
	}
	else if (liftingup) {
		if (GetActorLocation().Z >= initialposition.Z + movedistance) {
			SetActorLocation(initialposition + FVector(0, 0, movedistance));
			waiting = true;
			liftingup = false;
			UE_LOG(LogTemp, Log, TEXT("Reached the top Z position: %05f"), GetActorLocation().Z);
		}
		else
			SetActorLocation(GetActorLocation() + FVector(0, 0, movespeed));
	}
	else if (liftingdown) {
		if (GetActorLocation().Z <= initialposition.Z) {
			SetActorLocation(initialposition);
			liftingdown = false;
			movedone = true;
			//PrimaryActorTick.bCanEverTick = false;
			UE_LOG(LogTemp, Log, TEXT("Reached the initial Z position: %05f"), GetActorLocation().Z);
		}
		else
			SetActorLocation(GetActorLocation() - FVector(0, 0, movespeed));
	}
}