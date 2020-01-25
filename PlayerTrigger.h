// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "TestProjectCharacter.h"
#include "PlayerTrigger.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API APlayerTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	UPROPERTY(Category = "Player pointer", EditAnywhere)
		class ATestProjectCharacter* playerpointer;
	UPROPERTY(Category = "Player pointer", EditAnywhere)
		class AActor* playeractorpointer;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool moveup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool movedown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator directionup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator directondown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator angleup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator angledown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator facingup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator facingdown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float cameradistance_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float camerapitch_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector cameraoffset_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool forcedmove_0;
	//UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		//bool upiscircularmove;
	//UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		//bool downiscircularmove;
	//Angles and radius (in the plural!) should be added here
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool moveup_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool movedown_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FRotator angleup_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FRotator angledown_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FRotator facingup_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FRotator facingdown_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float cameradistance_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float camerapitch_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector cameraoffset_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool forcedmove_90;
	//UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		//bool upiscircularmove;
	//UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		//bool downiscircularmove;
	//Angles and radius (in the plural!) should be added here
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool moveup_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool movedown_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FRotator angleup_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FRotator angledown_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FRotator facingup_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FRotator facingdown_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float cameradistance_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float camerapitch_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector cameraoffset_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool forcedmove_180;
	//UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		//bool upiscircularmove;
	//UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		//bool downiscircularmove;
	//Angles and radius (in the plural!) should be added here
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool moveup_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool movedown_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FRotator angleup_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FRotator angledown_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FRotator facingup_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FRotator facingdown_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float cameradistance_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float camerapitch_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector cameraoffset_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool forcedmove_270;
	//UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		//bool upiscircularmove;
	//UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		//bool downiscircularmove;
	//Angles and radius (in the plural!) should be added here
	APlayerTrigger();
	// declare overlap begin function
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor); //(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// declare overlap end function
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor); //(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	void OverlappedFront();
	void OverlappedLeft();
	void OverlappedBack();
	void OverlappedRight();
};