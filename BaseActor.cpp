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
	
}

// Called every frame
void ABaseActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseActor::Spawn() {

}

void ABaseActor::Death() {

}

void ABaseActor::Active() {

}

void ABaseActor::Pain() {

}

void ABaseActor::Wound() {

}

void ABaseActor::ConditionReceived() {

}

void ABaseActor::ConditionFailed() {

}

void ABaseActor::Idle() {

}

void ABaseActor::Alert() {

}

void ABaseActor::Missile() {

}

void ABaseActor::Heal() {

}

void ABaseActor::Raise() {

}

void ABaseActor::Underwater() {

}

