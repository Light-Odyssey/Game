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
		FRotator angleup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator angledown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator facingup_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FRotator facingdown_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float cameradistance_0 = 500.0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float camerapitch_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector cameraoffset_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool forcedmove_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool upisparabolicmove_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		bool downisparabolicmove_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector upparabolicdelta_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector downparabolicdelta_0;
	/*UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector2D upcirclecenter_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		FVector2D downcirclecenter_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float upcircleradiusX_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float downcircleradiusX_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float upcircleradiusY_0;
	UPROPERTY(Category = "Trigger settings: FRONT SIDE", EditAnywhere)
		float downcircleradiusY_0;*/

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
		float cameradistance_90 = 500.0;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float camerapitch_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector cameraoffset_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool forcedmove_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool upisparabolicmove_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		bool downisparabolicmove_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector upparabolicdelta_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector downparabolicdelta_90;
	/*UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector2D upcirclecenter_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		FVector2D downcirclecenter_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float upcircleradiusX_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float downcircleradiusX_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float upcircleradiusY_90;
	UPROPERTY(Category = "Trigger settings: LEFT SIDE", EditAnywhere)
		float downcircleradiusY_90;*/

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
		float cameradistance_180 = 500.0;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float camerapitch_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector cameraoffset_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool forcedmove_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool upisparabolicmove_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		bool downisparabolicmove_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector upparabolicdelta_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector downparabolicdelta_180;
	/*UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector2D upcirclecenter_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		FVector2D downcirclecenter_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float upcircleradiusX_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float downcircleradiusX_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float upcircleradiusY_180;
	UPROPERTY(Category = "Trigger settings: BACK SIDE", EditAnywhere)
		float downcircleradiusY_180;*/

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
		float cameradistance_270 = 500.0;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float camerapitch_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector cameraoffset_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool forcedmove_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool upisparabolicmove_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		bool downisparabolicmove_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector upparabolicdelta_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector downparabolicdelta_270;
	/*UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector2D upcirclecenter_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		FVector2D downcirclecenter_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float upcircleradiusX_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float downcircleradiusX_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float upcircleradiusY_270;
	UPROPERTY(Category = "Trigger settings: RIGHT SIDE", EditAnywhere)
		float downcircleradiusY_270;*/

	APlayerTrigger();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
		void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	void OverlappedFront();
	void OverlappedLeft();
	void OverlappedBack();
	void OverlappedRight();
};