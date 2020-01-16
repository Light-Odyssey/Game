// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseActor.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ABasePlayer : public ABaseActor
{
	GENERATED_BODY()

public:
	ABasePlayer();

	// General properties
	const bool gender = false; //male (?)
	enum playerclasses { PClass_None = 0, PClass_C1 = 1, PClass_C2 = 2, PClass_C3 = 3, PClass_C4 = 4, };
	int playerclass = PClass_None;
	int level = 1;
	const float physicalspheregain[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	const float socialspheregain[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	const float mindspheregain[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	const float spiritspheregain[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	unsigned int experience = 0;
	unsigned int upgradetreepoints = 0;
	unsigned int physicalspherepoints = 0;
	unsigned int socialspherepoints = 0;
	unsigned int mindspherepoints = 0;
	unsigned int spiritspherepoints = 0;

	// Biological properties
	float maxhunger = 100;
	float hunger = 100;
	float maxdehydration = 100;
	float dehydration = 100;
	float maxexhaustion = 100;
	float exhaustion = 100;
	float maxsleep = 100;
	float sleep = 100;
 
	// Sphere attributes
	unsigned int agility = 0;
	unsigned int strength = 0;
	unsigned int toughness = 0;
	unsigned int fortitude = 0;
	unsigned int resilience = 0;
	unsigned int charisma = 0;
	unsigned int sagacity = 0;
	unsigned int persuasion = 0;
	unsigned int intellect = 0;
	unsigned int reasoning = 0;
	unsigned int memory = 0;
	unsigned int intensity = 0;
	unsigned int volatility = 0;
	unsigned int nexus = 0;
	
	virtual void Tick(float DeltaTime) override; // Called every frame

protected:
	// Programmable methods
	virtual void PMove(); //for derived classes, "override" should be added.
	virtual void PJump();
	virtual void PAttack();
	virtual void PDefend();
	virtual void PUseAbility();
	//virtual void PUseItem();
	virtual void PCrouch();
	virtual void PFall();
	virtual void PHide();

	//base actor methods
	virtual void BeginPlay() override; // Called when the game starts or when spawned
	virtual void Active() override;
	virtual void Spawn() override;
	virtual void Death() override;
	virtual void Pain() override;
	virtual void Wound() override;
	virtual void ConditionReceived() override;
	virtual void ConditionFailed() override;
	virtual void Idle() override;
	virtual void Alert() override;
	virtual void Missile() override;
	virtual void Heal() override;
	virtual void Raise() override;
	virtual void Underwater() override;

public:
	// General properties
	bool GetPlayerGender() {
		return gender;
	}
	//This is a constant bool, thus it cannot be changed.
	//If you call me an homofobic I'll cur your head off.
	//void SetPlayerGender(bool which) {
		//gender = which;
	//}
	int GetPlayerClass() {
		return playerclass;
	}
	void SetPlayerClass(int which) {
		playerclass = which;
	}
	int GetPlayerLevel() {
		return level;
	}
	void SetPlayerLevel(int lvl) {
		//Later on, this method must be changed in order to give the respective amount
		//of upgrade points.
		level = lvl;
	}
	float GetPhysicalSphereGain(int pclass) {
		return physicalspheregain[pclass];
	}
	//void SetPhysicalSphereGain(int pclass, float gain) {
		//physicalspheregain[pclass] = gain;
	//}
	float GetSocialSphereGain(int pclass) {
		return socialspheregain[pclass];
	}
	//void SetSocialSphereGain(int pclass, float gain) {
		//socialspheregain[pclass] = gain;
	//}
	float GetMindSphereGain(int pclass) {
		return mindspheregain[pclass];
	}
	//void SetMindSphereGain(int pclass, float gain) {
		//mindspheregain[pclass] = gain;
	//}
	float GetSpiritSphereGain(int pclass) {
		return spiritspheregain[pclass];
	}
	//void SetSpiritSphereGain(int pclass, float gain) {
		//spiritspheregain[pclass] = gain;
	//}
	//experience
	unsigned int GetPlayerExperience() {
		return experience;
	}
	void SetPlayerExperience(unsigned int value) {
		//Later on, this method must be changed in order to give the respective amount
		//of upgrade points.
		experience = value;
	}
	unsigned int GetTreeUpgradePoints() {
		return upgradetreepoints;
	}
	void SetTreeUpgradePoints(unsigned int points) {
		upgradetreepoints = points;
	}
	unsigned int GetPhysicalSpherePoints() {
		return physicalspherepoints;
	}
	void SetPhysicalSpherePoints(unsigned int points) {
		physicalspherepoints = points;
	}
	unsigned int GetSocialSpherePoints() {
		return socialspherepoints;
	}
	void SetSocialSpherePoints(unsigned int points) {
		socialspherepoints = points;
	}
	unsigned int GetMindSpherePoints() {
		return mindspherepoints;
	}
	void SetMindSpherePoints(unsigned int points) {
		mindspherepoints = points;
	}
	unsigned int GetSpiritSpherePoints() {
		return spiritspherepoints;
	}
	void SetSpiritSpherePoints(unsigned int points) {
		spiritspherepoints = points;
	}

	// Biological stats
	float GetPlayerMaxHunger() {
		return maxhunger;
	}
	float GetPlayerHunder() {
		return hunger;
	}
	float GetPlayerMaxDehydration() {
		return maxdehydration;
	}
	float GetPlayerDehydration() {
		return dehydration;
	}
	float GetPlayerMaxExhaustion() {
		return maxexhaustion;
	}
	float GetPlayerExhaustion() {
		return exhaustion;
	}
	float GetPlayerMaxSleep() {
		return maxsleep;
	}
	float GetPlayerSleep() {
		return sleep;
	}
	void SetPlayerMaxHunger(float value) {
		maxhunger = value;
	}
	void SetPlayerHunder(float value) {
		hunger = value;
	}
	void SetPlayerMaxDehydration(float value) {
		maxdehydration = value;
	}
	void SetPlayerDehydration(float value) {
		dehydration = value;
	}
	void SetPlayerMaxExhaustion(float value) {
		maxexhaustion = value;
	}
	void SetPlayerExhaustion(float value) {
		exhaustion = value;
	}
	void SetPlayerMaxSleep(float value) {
		maxsleep = value;
	}
	void SetPlayerSleep(float value) {
		sleep = value;
	}

	//Sphere attributes

};
