// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"

UCLASS()
class TESTPROJECT_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

	// General properties ===============
	//const int* AAPTR_THIS = &this_actor; //how can I define a pointer referencing to the own actor?
	//later on, we should define stuff like AAPTR_THIS, AAPTR_TARGET, AAPTR_MASTER, [...] which are actor pointers
	const int ACTOR_ID = 0;
	bool dormant = false;
	int tag = 0;
	int* master = 0;
	int* child = 0;
	bool soundreact = true;
	int* target = 0;

	// Physics and appearance ===============
	struct scale { float x = 1; float y = 1; float z = 1; };
	short int renderstyle = 0; //normal...?
	bool shootable = true;
	bool solid = true;
	//radius is meant to increase/decrease the actor's physical size, while maintaning the sma scale for the 3D model
	//struct worldpoint { float x; float y; float z; };
	struct position { float x; float y; float z; };
	struct radius { float x = 1; float y = 1; float z = 1; };
	struct scale { float x = 1; float y = 1; float z = 1; };
	//worldpoint position;
	//worldpoint radius;
	//worldpoint scale;
	float mass = 1.0;
	bool rippable = false;
	uint8 ripper_resistance = 0;
	float gravity = 1.0; //or 9.81...?
	float knockbackresistance = 0.0;
	bool invulnerable = false;

	/* [João Pistori]
	 * NOTE: mana, maximum mana, stamina, maximum stamina, maximum shields and maximum health could be changed into
	 * integers instead of floats in order to save memory and cpu. However, this may lead to possible absences of
	 * interpolation during increasing/decreasing effects.
	 * Also, anything related to mana usage and stamina usage could also turn into integers.
	 */

	// Special properties ===============
	//bool hardcoreflag = false;
	//short int = difficultylevel = 0;
	bool canraise = false;
	float raisemana = 100;
	uint8 summonedcompanions = 0;
	uint8 maxsummons = 0;

	// Biological properties ===============
	float maxhealth = 100;
	float health = 100;
	float healthregeneration = 0.1;
	float healthregenwait = 5.0;
	float maxmana = 30;
	float mana = 30;
	float manaregeneration = 0.2;
	float manaregenwait = 3.0;
	float maxstamina = 20;
	float stamina = 20;
	float staminaregeneration = 0.1;
	float staminaregenwait = 5.0;
	float armor = 0;
	//Are the structs below correct? can they be global for any actor and "map stuff"?
	//Also, condtype1, condtype2, condtype3 [...] should be the same for both structs. How can they be]
	//the same automatically?
	struct damageresistance { float dmgtype1 = 0; float dmgtype2 = 0; float gmdtype3 = 0; };
	struct conditionresistance { float condtype1 = 0; float condtype2 = 0; float condtype3 = 0; };
	struct conditionimmunity { float condtype1 = 0; float condtype2 = 0; float condtype3 = 0; };
	//Defining shields without condidions will lead to natural shields, preventing the actor
	//from being buffed with another kind of shield (better or worse than natural shield).
	//This should be done because there's no exactly way to measure which is the best shield.
	//Example: Natural shield has 65 "health" and 5 armor. Shield tried to be applied in a buff has
	//50 "health" and 7 armor. Both of them have different damage resistance values
	float maxshield = 0;  // = no shield
	short int shieldtype = 0; //plasma, fire, frost, physical, etc. This is just to link the 3D model.
	float shield = 0;
	float shieldregeneration = 0.35;
	float shieldregenwait = 5.0;
	float shieldarmor = 0;
	float shieldmaxdamage = 0;
	struct shielddamageresistance { float dmgtype1 = 0; float dmgtype2 = 0; float gmdtype3 = 0; };
	float painchance = 0.7;
	float painthreshold = 5;
	struct painimmunity { float dmgtype1 = 0; float dmgtype2 = 0; float gmdtype3 = 0; };
	struct painweakness { float dmgtype1 = 0; float dmgtype2 = 0; float gmdtype3 = 0; };
	float movespeed = 10.0;
	float runspeed = 16.5;
	float slowspeed = 4.5;
	float jumpforce = 8.0;
	/*
	// Behavior properties ===============
	float attackchance = 0.5; //balanced - 0.25 = defensive, 1.0 = agressive, etc.
	float healchance = 0.5;
	float attackinterval = 3.0;
	float healinterval = 3.0;
	float woundhealth = 30;
	float meleerange = 32;

	// Climate effects properties ===============
	float water_level;
	float submergedlevel;
	bool submerged;
	short int submergedtype;

	// Faction properties
	short int faction = 0;
	struct friendlyfactions { bool fac1 = false; bool fac2 = false; bool fac3 = false; };
	struct enemyfactions { bool fac1 = false; bool fac2 = false; bool fac3 = false; }; */

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Those are the programmable methods for the actor's states.
	virtual void Active(); //for derived classes, "override" should be added.
	virtual void Spawn();
	virtual void Death();
	virtual void Pain();
	virtual void Wound();
	virtual void ConditionReceived();
	virtual void ConditionFailed();
	virtual void Idle();
	virtual void Alert();
	virtual void Missile();
	virtual void Heal();
	virtual void Raise();
	virtual void Underwater();

	// Those below are the native methods which the actor can use for its behavior.

	// General properties
	bool IsActorActive(int* actorpointer);
	void SetActorActive(int* actorpointer, bool active);
	int* GetActorMaster(int* actorpointer);
	void SetActorMaster(int* actorpointer, int* newmaster);
	int** GetActorChild(int* actorpointer); //this is intended to be an array containing the pointers of each child
	void SetActorChild(int* actorpointer, int* newchild);
	bool IsActorSoundReact(int* actorpointer);
	void SetActorSoundReact(int* actorpointer, bool react);
	int* GetActorTarget(int* actorpointer);
	void SetActorTarget(int* actorpointer, int* newtarget);

	//Physics and appearance
	scale GetActorScale (int* actorpointer);
	float GetActorScaleX(int* actorpointer);
	float GetActorScaleY(int* actorpointer);
	float GetActorScaleZ(int* actorpointer);
	void SetActorScale(int* actorpointer, scale value);
	int GetActorRenderStyle(int* actorpointer);
	void SetActorRenderStyle(int* actorpointer, int style);
	bool IsActorShootable(int* actorpointer);
	void SetActorShootable(int* actorpointer, bool isshootable);
	bool IsActorSolid(int* actorpointer);
	void SetActorSolid(int* actorpointer, bool issolid);
	radius GetActorRadius(int* actorpointer);
	void SetActorRadius(int* actorpointer, radius value);
	float GetActorMass(int* actorpointer);
	void SetActorMass(int* actorpointer, float value);
	bool IsActorRippable(int* actorpointer);
	void SetActorRippable(int* actorpointer, bool isrippable);
	uint8 GetActorRipperResistance(int* actorpointer);
	void SetActorRipperResistance(int* actorpointer, uint8 resistance);
	bool IsActorInvulnerable(int* actorpointer);
	void SetActorInvulnerable(int* actorpointer, bool isinvulnerable);

	// Special stats
	bool CanActorRaise(int* actorpointer);
	void SetActorCanRaise(int* actorpointer, bool can);
	float GetActorRaiseMana(int* actorpointer);
	void SetActorRaiseMana(int* actorpointer, float value);
	uint8 GetActorSummonedCompanions(int* actorpointer);
	uint8 GetActorMaxSummons(int* actorpointer);
	void SetActorMaxSummons(int* actorpointer, uint8 amount);

	// Biological stats
	float GetActorMaxHealth(int* actorpointer);
	float GetActorHealth(int* actorpointer);
	float GetActorHealthRegen(int* actorpointer);
	float GetActorHealthRegenWait(int* actorpointer);
	void SetActorMaxHealth(int* actorpointer, float value);
	void SetActorHealth(int* actorpointer, float value);
	void SetActorHealthRegen(int* actorpointer, float regen);
	void SetActorHealthRegenWait(int* actorpointer, float time);
	float GetActorMaxMana(int* actorpointer);
	float GetActorMana(int* actorpointer);
	float GetActorManaRegen(int* actorpointer);
	float GetActorManaRegenWait(int* actorpointer);
	void SetActorMaxMana(int* actorpointer, float value);
	void SetActorMana(int* actorpointer, float value);
	void SetActorManaRegen(int* actorpointer, float regen);
	void SetActorManaRegenWait(int* actorpointer, float time);
	float GetActorMaxStamina(int* actorpointer);
	float GetActorStamina(int* actorpointer);
	float GetActorStaminaRegen(int* actorpointer);
	float GetActorStaminaRegenWait(int* actorpointer);
	void SetActorMaxStamina(int* actorpointer, float value);
	void SetActorStamina(int* actorpointer, float value);
	void SetActorStaminaRegen(int* actorpointer, float regen);
	void SetActorStaminaRegenWait(int* actorpointer, float time);
	float GetActorMaxShields(int* actorpointer);
	float GetActorShields(int* actorpointer);
	short int GetActorShieldType(int* actorpointer);
	float GetActorShieldRegeneration(int* actorpointer);
	float GetActorShieldRegenWait(int* actorpointer);
	float GetActorShieldArmor(int* actorpointer);
	float GetActorShieldMaxDamage(int* actorpointer);
	damageresistance GetActorShieldDamageResistance(int* actorpointer);
	void SetActorMaxShields(int* actorpointer, float value);
	void SetActorShields(int* actorpointer, float value);
	void SetActorShieldType(int* actorpointer, short int type);
	void SetActorShieldRegeneration(int* actorpointer, float regen);
	void SetActorShieldRegenWait(int* actorpointer, float time);
	void SetActorShieldArmor(int* actorpointer, float amount);
	void SetActorShieldMaxDamage(int* actorpointer, float amount);
	void SetActorShieldDamageResistance(int* actorpointer, damageresistance dmg_resistance);
	damageresistance GetActorDamageResistance(int* actorpointer);
	void SetActorDamageResistance(int* actorpointer, damageresistance dmg_resistance);
	conditionresistance GetActorConditionResistance(int* actorpointer);
	void SetActorConditionResistance(int* actorpointer, conditionresistance cond_resistance);
	conditionimmunity GetActorConditionImmunity(int* actorpointer);
	void SetActorConditionImmunity(int* actorpointer, conditionimmunity cond_resistance);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Physics and appearance
	scale GetActorPosition(); //this one is here (public) because it doesn't have a pointer parameter.
	//void SetActorPosition(scale position);
};
