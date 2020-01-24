// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ElevatorTest.h"
#include "TestTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ATestTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(Category = "Actor pointers", EditAnywhere, BlueprintReadWrite)
		class AActor* targetactor;
	UPROPERTY(Category = "Actor pointers", EditAnywhere, BlueprintReadWrite)
		class AElevatorTest* targetelevator;
	ATestTriggerBox();
	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor); //(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor); //(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	UFUNCTION()
		void OnHit(class AActor* OverlappedActor, class AActor* OtherActor);
};
