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
	// Stuff that should be global vars ===============
	//struct coords { float x; float y; float z; }; // UNECESSARY PROPERTY --- UNREAL ALREADY HAS THIS METHOD
	enum damagetypes { Dmg_None = 0, Dmg_Type1 = 1, Dmg_Type2 = 2, Dmg_Type3 = 3, Dmg_Type4 = 4, };
	int damagetype = Dmg_None;
	enum conditiontypes { Cond_None = 0, Cond_Type1 = 1, Cond_Type2 = 2, Cond_Type3 = 3, Cond_Type4 = 4, };
	int conditiontype = Cond_None;
	enum shieldtypes { Shield_None = 0, Shield_Type1 = 1, Shield_Type2 = 2, Shield_Type3 = 3, Shield_Type4 = 4, };
	int shieldtype = Shield_None;
	enum factions { Fac_None = 0, Fac1 = 1, Fac2 = 2, Fac3 = 3, Fac4 = 4, };
	int faction = Fac_None;

	// General properties ===============
	//later on, we should define stuff like AAPTR_THIS, AAPTR_TARGET, AAPTR_MASTER, [...] which are actor pointers
	const int ACTOR_ID = 0;
	bool dormant = false; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	int tag = 0;
	int* master = 0;
	int* child = 0;
	bool soundreact = true; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	int* target = 0;

	// Physics and appearance ===============
	short int renderstyle = 0; //normal...?
	bool shootable = true; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	bool solid = true; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	//radius is meant to increase/decrease the actor's physical size, while maintaning the sma scale for the 3D model
	
	//coords actor_position; // UNECESSARY PROPERTY --- UNREAL ALREADY HAS THIS METHOD
	//coords actor_radius; // UNECESSARY PROPERTY --- UNREAL ALREADY HAS THIS METHOD
	//coords actor_scale; // UNECESSARY PROPERTY --- UNREAL ALREADY HAS THIS METHOD
	//worldpoint position;
	//worldpoint radius;
	//worldpoint scale;
	float mass = 1.0;
	bool rippable = false; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	uint8 ripper_resistance = 0;
	float gravity = 1.0; //or 9.81...?
	float knockbackresistance = 0.0;
	bool invulnerable = false; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD

	/* [Jo�o Pistori]
	 * NOTE: mana, maximum mana, stamina, maximum stamina, maximum shields and maximum health could be changed into
	 * integers instead of floats in order to save memory and cpu. However, this may lead to possible absences of
	 * interpolation during increasing/decreasing effects.
	 * Also, anything related to mana usage and stamina usage could also turn into integers.
	 */

	// Special properties ===============
	//bool hardcoreflag = false;
	//short int = difficultylevel = 0;
	bool canraise = false; //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
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
	//damagetype = None;
	//float damagefactor[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	float damagepiercing[5] = { 0.0, 0.0, 0.0, 0.0, 0.0, };
	float damageresistance[5] = { 0.0, 0.0, 0.0, 0.0, 0.0, };
	//conditiontype = None;
	float conditionresistance[5] = { 0.0, 0.0, 0.0, 0.0, 0.0, };
	bool conditionimmunity[5] = { false, false, false, false, false, };
	//Defining shields without condidions will lead to natural shields, preventing the actor
	//from being buffed with another kind of shield (better or worse than natural shield).
	//This should be done because there's no exactly way to measure which is the best shield.
	//Example: Natural shield has 65 "health" and 5 armor. Shield tried to be applied in a buff has
	//50 "health" and 7 armor. Both of them may have different damage resistance values.
	float maxshield = 0;  // = no shield
	//shieldtype = None;
	float shield = 0;
	float shieldregeneration = 0.35;
	float shieldregenwait = 5.0;
	float shieldarmor = 0;
	float shieldmaxdamage = 0;
	float shieldresistance[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
	float painchance = 0.7;
	float painthreshold = 5;
	bool painimmunity[5] = { false, false, false, false, false };
	float painweakness[5] = { 0.0, 0.0, 0.0, 0.0, 0.0, };
	float movespeed = 10.0;
	float runspeed = 16.5;
	float slowspeed = 4.5;
	float jumpforce = 8.0;
	
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
	//faction = None;
	bool friendlyfactions[5] = { false, false, false, false, false, };
	bool enemyfactions[5] = { false, false, false, false, false, };

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

public:
	// Those below are the native methods which the actor can use for its behavior.
	//Note: ABaseActor* actorpointer parameter was removed from all methods.

	// General properties
	/*FVector GetActorPosition() { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		GetActorLocation();
	}
	void SetActorPosition(FVector location){ // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
			(location);
	}*/
	bool IsActorActive(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorActive(bool active); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	int* GetActorMaster();
	void SetActorMaster(int* newmaster);
	int** GetActorChild(); //this is intended to be an array containing the pointers of each child
	void SetActorChild(int* newchild);
	bool IsActorSoundReact(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorSoundReact(bool react); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	int* GetActorTarget();
	void SetActorTarget(int* newtarget);
	
	//Physics and appearance
	/*FVector GetActorScale() { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		return GetActorScale3D();
		//return test.GetLocation;
	}
	float GetActorScaleX() { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		return GetActorScale().X;
	}
	float GetActorScaleY() { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		return GetActorScale().Y;
	}
	float GetActorScaleZ() { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		return GetActorScale().Z;
	}
	void SetActorScale(FVector value) { // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
		SetActorScale3D(value);
	}
	FRotator GetActorRotation(); // UNECESSARY METHOD --- UNREAL ALREADY HAS THIS METHOD
	void SetActorRotation();*/
	int GetActorRenderStyle();
	void SetActorRenderStyle(int style);
	bool IsActorShootable(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorShootable(bool isshootable);  //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	bool IsActorSolid(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorSolid(bool issolid); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	FVector GetActorRadius();
	void SetActorRadius(FVector value);
	float GetActorMass();
	void SetActorMass(float value);
	bool IsActorRippable(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorRippable(bool isrippable); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	uint8 GetActorRipperResistance();
	void SetActorRipperResistance(uint8 resistance);
	bool IsActorInvulnerable(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorInvulnerable(bool isinvulnerable); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD

	// Special stats
	bool CanActorRaise(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorCanRaise(bool can); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	float GetActorRaiseMana();
	void SetActorRaiseMana(float value);
	uint8 GetActorSummonedCompanions();
	uint8 GetActorMaxSummons();
	void SetActorMaxSummons(uint8 amount);

	// Biological stats
	float GetActorMaxHealth() {
		return maxhealth;
	}
	float GetActorHealth() {
		return health;
	}
	float GetActorHealthRegen() {
		return healthregeneration;
	}
	float GetActorHealthRegenWait() {
		return healthregenwait;
	}
	void SetActorMaxHealth(float value) {
		maxhealth = value;
	}
	void SetActorHealth(float value) {
		if (value > maxhealth)
			health = maxhealth;
		else
			health = value;
	}
	void SetActorHealthRegen(float regen) {
		healthregeneration = regen;
	}
	void SetActorHealthRegenWait(float time) {
		healthregenwait = time;
	}
	float GetActorMaxMana() {
		return maxmana;
	}
	float GetActorMana() {
		return mana;
	}
	float GetActorManaRegen() {
		return manaregeneration;
	}
	float GetActorManaRegenWait() {
		return manaregenwait;
	}
	void SetActorMaxMana(float value) {
		maxmana = value;
	}
	void SetActorMana(float value) {
		if (value > maxmana)
			mana = maxmana;
		else
			mana = value;
	}
	void SetActorManaRegen(float regen) {
		manaregeneration = regen;
	}
	void SetActorManaRegenWait(float time) {
		manaregenwait = time;
	}
	float GetActorMaxStamina() {
		return maxstamina;
	}
	float GetActorStamina() {
		return stamina;
	}
	float GetActorStaminaRegen() {
		return staminaregeneration;
	}
	float GetActorStaminaRegenWait() {
		return staminaregenwait;
	}
	void SetActorMaxStamina(float value) {
		maxstamina = value;
	}
	void SetActorStamina(float value) {
		if (value > maxstamina)
			stamina = maxstamina;
		else
			stamina = value;
	}
	void SetActorStaminaRegen(float regen) {
		staminaregeneration = regen;
	}
	void SetActorStaminaRegenWait(float time) {
		staminaregenwait = time;
	}
	float GetActorMaxShields() {
		return maxshield;
	}
	float GetActorShields() {
		return shield;
	}
	int GetActorShieldType() {
		return shieldtype;
	}
	float GetActorShieldRegeneration() {
		return shieldregeneration;
	}
	float GetActorShieldRegenWait() {
		return shieldregenwait;
	}
	float GetActorShieldArmor() {
		return shieldarmor;
	}
	float GetActorShieldMaxDamage() {
		return shieldmaxdamage;
	}
	//damagefactor GetActorShieldDamageResistance(int* actorpointer, damagetype type); // ==================== #####
	float GetActorShieldDamageResistance(int type) {
		return shieldresistance[type];
	}
	void SetActorMaxShields(float value) {
		maxshield = value;
	}
	void SetActorShields(float value) {
		if (value > maxshield)
			shield = maxshield;
		else
			shield = value;
	}
	void SetActorShieldType(int type) {
		shieldtype = type;
	}
	void SetActorShieldRegeneration(float regen) {
		shieldregeneration = regen;
	}
	void SetActorShieldRegenWait(float time) {
		shieldregenwait = time;
	}
	void SetActorShieldArmor(float amount) {
		shieldarmor = amount;
;	}
	void SetActorShieldMaxDamage(float amount) {
		if (amount > maxshield)
			shieldmaxdamage = 0; //turn off
		else
			shieldmaxdamage = amount;
	}
	//void SetActorShieldDamageResistance(int* actorpointer, damagefactor dmgresistance); // ==================== #####
	void SetActorShieldDamageResistance(int dmgtype, float dmgresistance) {
		shieldresistance[dmgtype] = dmgresistance;
	}
	//damagefactor GetActorDamageResistance(int* actorpointer); // ==================== #####
	float GetActorDamageResistance(int dmgtype) {
		return shieldresistance[dmgtype];
	}
	//void SetActorDamageResistance(int* actorpointer, damagefactor dmgresistance); // ==================== #####
	void SetActorDamageResistance(int dmgtype, float dmgresistance) {
		shieldresistance[dmgtype] = dmgresistance;
	}
	//conditionresistance GetActorConditionResistance(int* actorpointer); // ==================== #####
	float GetActorConditionResistance(int condtype) {
		return conditionresistance[condtype];
	}
	//void SetActorConditionResistance(int* actorpointer, conditionresistance cond_resistance); // ==================== #####
	void SetActorConditionResistance(int condtype, float condresistance) {
		conditionresistance[condtype] = condresistance;
	}
	//conditionimmunity GetActorConditionImmunity(int* actorpointer); // ==================== #####
	float GetActorConditionImmunity(int condtype) {
		return conditionimmunity[condtype];
	}
	//void SetActorConditionImmunity(int* actorpointer, conditionimmunity cond_resistance); // ==================== #####
	void SetActorConditionImmunity(int condtype, bool immune) {
		conditionimmunity[condtype] = immune;
	}
	float GetActorPainChance() {
		return painchance;
	}
	void SetActorPainChange(float chance) {
		painchance = chance;
	}
	float GetActorPainThreshold() {
		return painthreshold;
	}
	void SetActorPainThreshold(float threshold) {
		painthreshold = threshold;
	}
	//painimmunity GetActorPainImmunity(int* actorpointer); // ==================== #####
	bool GetActorPainImmunity(int dmgtype) {
		return painimmunity[dmgtype];
	}
	//void SetActorPainImmunity(int* actorpointer, painimmunity immunity); // ==================== #####
	void SetActorPainImmunity(int dmgtype, bool immune) {
		painimmunity[dmgtype] = immune;
	}
	//painweakness GetActorPainWeakness(int* actorpointer); // ==================== #####
	float GetActorPainWeakness(int dmgtype) {
		return painweakness[dmgtype];
	}
	//void SetActorPainWeakness(int* actorpointer, painweakness weakness); // ==================== #####
	void SetActorPainWeakness(int dmgtype, float weakness) {
		painweakness[dmgtype] = weakness;
	}
	float GetActorMoveSpeed() {
		return movespeed;
	}
	void SetActorMoveSpeed(float mspeed) {
		if (mspeed > 0)
			movespeed = mspeed;
	}
	float GetActorRunSpeed() {
		return runspeed;
	}
	void SetActorRunSpeed(float rspeed) {
		if (rspeed > 0)
			runspeed = rspeed;
	}
	float GetActorSlowSpeed() {
		return slowspeed;
	}
	void SetActorSlowSpeed(float sspeed) {
		if (sspeed > 0)
			slowspeed = sspeed;
	}
	float GetActorJumpForce() {
		return jumpforce;
	}
	void SetActorJumpForce(float force) {
		if (jumpforce > 0)
			jumpforce = force;
	}

	// Player stats
	// I didn't remove the pointer from those methods because they MAY (or may not) be necessary
	// to access the player-class component. Maybe I'll move those methods to player-class only.
	float GetPlayerMaxHunger(int* playerpointer);
	float GetPlayerHunger(int* playerpointer);
	float GetPlayerMaxDehydration(int* playerpointer);
	float GetPlayerDehydration(int* playerpointer);
	float GetPlayerMaxExhaustion(int* playerpointer);
	float GetPlayerExhaustion(int* playerpointer);
	void SetPlayerMaxHunger(int* playerpointer);
	void SetPlayerHunger(int* playerpointer, float value);
	void SetPlayerMaxDehydration(int* playerpointer, float value);
	void SetPlayerDehydration(int* playerpointer, float value);
	void SetPlayerMaxExhaustion(int* playerpointer, float value);
	void SetPlayerExhaustion(int* playerpointer, float value);

	// Behavior stats
	float GetActorAttackChance() {
		return attackchance;
	}
	float GetActorHealChance() {
		return healchance;
	}
	float GetActorAttackInterval() {
		return attackinterval;
	}
	float GetActorHealInterval() {
		return healinterval;
	}
	float GetActorWoundHealth() {
		return woundhealth;
	}
	void SetActorAttackChance(float chance) {
		attackchance = chance;
	}
	void SetActorHealChance(float chance) {
		healchance = chance;
	}
	void SetActorAttackInterval(float interval) {
		attackinterval = interval;
	}
	void SetActorHealInterval(float interval) {
		healinterval = interval;
	}
	void SetActorWoundHealth(float whealth) {
		woundhealth = whealth;
	}

	// Climate effect stats
	//[get/set]waterlevel
	//[get/set]submergedlevel
	//[get/set]issubmerged
	//[get/set]submergedtype

	// Faction stats
	int GetActorFaction();
	//friendlyfactions GetActorFriendlyFactions(int* actorpointer); // ==================== #####
	bool GetActorFriendlyFaction(int faction);
	//enemyfactions GetActorEnemyFactions(int* actorpointer); // ==================== #####
	bool GetActorEnemyFaction(int faction);
	void SetActorFaction(int faction);
	//void SetActorFriendlyFactions(int* actorpointer, friendlyfactions factions); // ==================== #####
	void SetActorFriendlyFactions(int faction, bool isfriendly);
	//void SetActorEnemyFactions(int* actorpointer, enemyfactions factions); // ==================== #####
	void SetActorEnemyFactions(int faction, bool isenemy);

	// Sight methods
	bool CheckLOS(int* actorpointer, int* actorpointer2);
	bool CheckSight(int* actorpointer, int* actorpointer2, float range, float field_angle, float field_pitch);
	bool CheckRange(int* actorpointer, int* actorpointer2, float range);

	// Sound methods
	void NoiseAlert(float range);

	// Damage and Healing methods
	void RayAttack(float damage, int damage_type, float armor_factor, FVector Offset_position, float angle, float pitch, ABaseActor Line, ABaseActor Impact, float spacing, float maxrange, float knockbackstrength, int piercing_llimit);
	bool MeleeAttack(float damage, int damage_type, float range, float hit_angle, float knockback_strength, ABaseActor puff_type, float life_drain, bool destroy_projectiles, float piercing)	;
	void BulletAttack(float spread_angle, int bullets_amoount, float bullet_damage, int damage_type, float armor_factor, ABaseActor puff_type, float maxrange, float knockbackstrength, float piercing);
	void ProjectileAttack(ABaseActor missile, float angle, float pitch, FVector offset_position, int* target);
	void Blast(float strength, float radius, float full_strength_radius);
	void DamageActorMaster(float damage, int damage_type, float piercing);
	void DamageActorSiblings(float damage, int damage_type, float piercing);
	void DamageActorChildren(float damage, int damage_type, float piercing);
	void Explode(float damage, float damage_type, float radius, float armor_factor, float full_damage_radius, bool friendly_fire, float piercing);
	void Defend(float damage_factor, float bonus_armor, float bonus_resistance, float bonus_knockback_resistance, float angle);
	void HealActorMaster(float heal_amount);   //Even if healing is a "negative damage", it's better to have
	void HealActorSiblings(float heal_amount); //methods just for healing because it "removes" any kind of
	void HealActorChildren(float heal_amount); //if-else structures from damage methods. The formula for
	void Area_heal(float heal_amount, float radius, float full_heal_radius); //ignores armor and resistance, except heal% conditions
	void DamageActor(float damage, float armor_factor, int damage_type, float piercing);
	void HealActor(float heal_amount);
	void ApplyKnockbackToActor(float strength);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
