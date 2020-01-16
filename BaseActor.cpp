// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseActor.h"

// Sets default values
ABaseActor::ABaseActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseActor::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

//bool scaleup = true;
//bool movingleft = true;
//bool rotatingleft = true;

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector currentscale = GetActorScale3D();
	FVector currentpos = GetActorLocation();
	FRotator currentyaw = GetActorRotation();
	/*
	if (currentscale.Y <= 0.5)
		scaleup = true;
	else if (currentscale.Y >= 2.5)
		scaleup = false;
	if (scaleup)
		SetActorScale3D(currentscale + FVector(0, 0.01, 0));
	else
		SetActorScale3D(currentscale - FVector(0, 0.01, 0));
	
	if (movingleft)
		SetActorLocation(currentpos + FVector(0, 0.35, 0));
	else
		SetActorLocation(currentpos - FVector(0, 0.35, 0));
	if (currentpos.Y >= -600)
		movingleft = false;
	else if (currentpos.Y <= -1200)
		movingleft = true;

	if (rotatingleft)
		SetActorRotation(currentyaw + FRotator(0.12, 0.15, 0.1));
	else
		SetActorRotation(currentyaw - FRotator(0.12, 0.15, 0.1));
	if (currentyaw.Yaw <= 30) //.Roll, .Pitch and .Yaw
		rotatingleft = false;
	else if (currentyaw.Yaw >= 270)
		rotatingleft = true;*/
}

void ABaseActor::Spawn() {
	//FString s_maxhealth = FString::Printf(TEXT("Max health: %02f"), GetActorMaxHealth());
	//FString s_health = FString::Printf(TEXT("Max health: %02f"), GetActorHealth());
	//FString s_healthregen = FString::Printf(TEXT("Max health: %02f"), GetActorHealthRegen());
	//FString s_regenwait = FString::Printf(TEXT("Max health: %02f"), GetActorHealthRegenWait());
	//FString MaxHealthString = FString::SanitizeFloat(maxhealth);
	//FString NewString = FString::FromInt(YourInt);
	UE_LOG(LogTemp, Log, TEXT("Spawned successfully!"));
	UE_LOG(LogTemp, Log, TEXT("Max health: %02f"), GetActorMaxHealth());
	UE_LOG(LogTemp, Log, TEXT("Current health: %02f"), GetActorHealth());
	UE_LOG(LogTemp, Log, TEXT("Health regen: %02f"), GetActorHealthRegen());
	UE_LOG(LogTemp, Log, TEXT("Regen wait: %02f"), GetActorHealthRegenWait());
	SetActorMaxHealth(120);
	SetActorHealth(70);
	SetActorHealthRegen(0.15);
	SetActorHealthRegenWait(3.5);
	UE_LOG(LogTemp, Log, TEXT("Spawned successfully!"));
	UE_LOG(LogTemp, Log, TEXT("Max health: %02f"), GetActorMaxHealth());
	UE_LOG(LogTemp, Log, TEXT("Current health: %02f"), GetActorHealth());
	UE_LOG(LogTemp, Log, TEXT("Health regen: %02f"), GetActorHealthRegen());
	UE_LOG(LogTemp, Log, TEXT("Regen wait: %02f"), GetActorHealthRegenWait());
}

void ABaseActor::Death() {}

void ABaseActor::Active() {}

void ABaseActor::Pain() {}

void ABaseActor::Wound() {}

void ABaseActor::ConditionReceived() {}

void ABaseActor::ConditionFailed() {}

void ABaseActor::Idle() {}

void ABaseActor::Alert() {}

void ABaseActor::Missile() {}

void ABaseActor::Heal() {}

void ABaseActor::Raise() {}

void ABaseActor::Underwater() {}