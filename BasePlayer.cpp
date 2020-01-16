// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABasePlayer::Spawn() {}

void ABasePlayer::Death() {}

void ABasePlayer::Active() {}

void ABasePlayer::Pain() {}

void ABasePlayer::Wound() {}

void ABasePlayer::ConditionReceived() {}

void ABasePlayer::ConditionFailed() {}

void ABasePlayer::Idle() {}

void ABasePlayer::Alert() {}

void ABasePlayer::Missile() {}

void ABasePlayer::Heal() {}

void ABasePlayer::Raise() {}

void ABasePlayer::Underwater() {}

//BasePlayer virtual methods

// Programmable methods
void ABasePlayer::PMove() {}

void ABasePlayer::PJump() {}

void ABasePlayer::PAttack() {}

void ABasePlayer::PDefend() {}

void ABasePlayer::PUseAbility() {}

//void ABasePlayer::PUseItem() {}

void ABasePlayer::PCrouch() {}

void ABasePlayer::PFall() {}

void ABasePlayer::PHide() {}