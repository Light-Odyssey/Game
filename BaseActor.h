	// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseActor.generated.h"
//#include "GlobalVars.h"

UCLASS()
class TESTPROJECT_API ABaseActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseActor();

	// Stuff that should be global vars ===============
	struct coords { float x; float y; float z; };
	enum damagetypes { None = 0, Type1 = 1, Type2 = 2, Type3 = 3, Type4 = 4, } damagetype;
	enum conditiontypes { None = 0, Type1 = 1, Type2 = 2, Type3 = 3, Type4 = 4, } conditiontype;
	enum shieldtypes { None = 0, Type1 = 1, Type2 = 2, Type3 = 3, Type4 = 4, } shieldtype;
	enum factions { None = 0, fac1 = 1, fac2 = 2, fac3 = 3, fac4 = 4, } faction;

	// General properties ===============
	//later on, we should define stuff like AAPTR_THIS, AAPTR_TARGET, AAPTR_MASTER, [...] which are actor pointers
	const int ACTOR_ID = 0;
	bool dormant = false;
	int tag = 0;
	int* master = 0;
	int* child = 0;
	bool soundreact = true;
	int* target = 0;

	// Physics and appearance ===============
	short int renderstyle = 0; //normal...?
	bool shootable = true;
	bool solid = true;
	//radius is meant to increase/decrease the actor's physical size, while maintaning the sma scale for the 3D model
	
	coords actor_position;
	coords actor_radius;
	coords actor_scale;
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
	//damagetype = None;
	float damagefactor[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	float damagepiercing[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	float damageresistance[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
	//conditiontype = None;
	float conditionresistance[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
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
	float shieldresistance[5] = { 1.0, 1.0, 1.0, 1.0, 1.0 };
	float painchance = 0.7;
	float painthreshold = 5;
	bool painimmunity[5] = { false, false, false, false, false };
	float painweakness[5] = { 1.0, 1.0, 1.0, 1.0, 1.0, };
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
	/*coords GetActorScale() {
		FTransform test = GetTransform();
		return test.GetScale3D;
		//return test.GetLocation;
	}*/
	coords GetActorScale();
	float GetActorScaleX(); //ABaseActor* actorpointer parameter was removed from all methods.
	float GetActorScaleY();
	float GetActorScaleZ();
	void SetActorScale(coords value);
	int GetActorRenderStyle();
	void SetActorRenderStyle(int style);
	bool IsActorShootable(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorShootable(bool isshootable);  //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	bool IsActorSolid(); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	void SetActorSolid(bool issolid); //ACTOR FLAG --- BRING IT TO THE OVERALL FLAGS METHOD
	coords GetActorRadius();
	void SetActorRadius(coords value);
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
	float GetActorMaxHealth();
	float GetActorHealth();
	float GetActorHealthRegen();
	float GetActorHealthRegenWait();
	void SetActorMaxHealth(float value);
	void SetActorHealth(float value);
	void SetActorHealthRegen(float regen);
	void SetActorHealthRegenWait(float time);
	float GetActorMaxMana();
	float GetActorMana();
	float GetActorManaRegen();
	float GetActorManaRegenWait();
	void SetActorMaxMana(float value);
	void SetActorMana(float value);
	void SetActorManaRegen(float regen);
	void SetActorManaRegenWait(float time);
	float GetActorMaxStamina();
	float GetActorStamina();
	float GetActorStaminaRegen();
	float GetActorStaminaRegenWait();
	void SetActorMaxStamina(float value);
	void SetActorStamina(float value);
	void SetActorStaminaRegen(float regen);
	void SetActorStaminaRegenWait(float time);
	float GetActorMaxShields();
	float GetActorShields();
	short int GetActorShieldType();
	float GetActorShieldRegeneration();
	float GetActorShieldRegenWait();
	float GetActorShieldArmor();
	float GetActorShieldMaxDamage();
	//damagefactor GetActorShieldDamageResistance(int* actorpointer, damagetype type); // ==================== #####
	float GetActorShieldDamageResistance(int type);
	void SetActorMaxShields(float value);
	void SetActorShields(float value);
	void SetActorShieldType(int type);
	void SetActorShieldRegeneration(float regen);
	void SetActorShieldRegenWait(float time);
	void SetActorShieldArmor(float amount);
	void SetActorShieldMaxDamage(float amount);
	//void SetActorShieldDamageResistance(int* actorpointer, damagefactor dmgresistance); // ==================== #####
	void SetActorShieldDamageResistance(int dmgtype, float dmgresistance);
	//damagefactor GetActorDamageResistance(int* actorpointer); // ==================== #####
	float GetActorDamageResistance(int dmgtype);
	//void SetActorDamageResistance(int* actorpointer, damagefactor dmgresistance); // ==================== #####
	void SetActorDamageResistance(int dmgtype, float dmgresistance);
	//conditionresistance GetActorConditionResistance(int* actorpointer); // ==================== #####
	float GetActorConditionResistance(int condtype);
	//void SetActorConditionResistance(int* actorpointer, conditionresistance cond_resistance); // ==================== #####
	void SetActorConditionResistance(int condtype, float condresistance);
	//conditionimmunity GetActorConditionImmunity(int* actorpointer); // ==================== #####
	float GetActorConditionImmunity(int condtype);
	//void SetActorConditionImmunity(int* actorpointer, conditionimmunity cond_resistance); // ==================== #####
	void SetActorConditionImmunity(int condtype, bool immune);
	float GetActorPainChance();
	void SetActorPainChange(float chance);
	float GetActorPainThreshold();
	void SetActorPainThreshold(float threshold);
	//painimmunity GetActorPainImmunity(int* actorpointer); // ==================== #####
	float GetActorPainImmunity(int dmgtype);
	//void SetActorPainImmunity(int* actorpointer, painimmunity immunity); // ==================== #####
	void SetActorPainImmunity(int dmgtype, bool immune);
	//painweakness GetActorPainWeakness(int* actorpointer); // ==================== #####
	float GetActorPainWeakness(int dmgtype);
	//void SetActorPainWeakness(int* actorpointer, painweakness weakness); // ==================== #####
	void SetActorPainWeakness(int dmgtype, float weakness);
	float GetActorMoveSpeed();
	void SetActorMoveSpeed(float mspeed);
	float GetActorRunSpeed();
	void SetActorRunSpeed(float rspeed);
	float GetActorSlowSpeed(int* actorpointer);
	void SetActorSlowSpeed(float sspeed);
	float GetActorJumpForce();
	void SetActorJumpForce(float force);

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
	float GetActorAttackChance();
	float GetActorHealChance();
	float GetActorAttackInterval();
	float GetActorHealInterval();
	float GetActorWoundHealth();
	void SetActorAttackChance(float chance);
	void SetActorHealChance(float chance);
	void SetActorAttackInterval(float interval);
	void SetActorHealInterval(float interval);
	void SetActorWoundHealth(float whealth);

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
	void RayAttack(float damage, int damage_type, float armor_factor, coords Offset_position, float angle, float pitch, ABaseActor Line, ABaseActor Impact, float spacing, int piercing_llimit);
	bool MeleeAttack(float damage, int damage_type, float range, float hit_angle, float knockback_strength, ABaseActor puff_type, float life_drain, bool destroy_projectiles, float piercing);
	void BulletAttack(float spread_angle, int bullets_amoount, float bullet_damage, int damage_type, float armor_factor, ABaseActor puff_type, float max_range, float piercing);
	void ProjectileAttack(ABaseActor missile, float angle, float pitch, coords offset_position, int* target);
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

	//Physics and appearance
	coords GetActorPosition(); //this one is here (public) because it doesn't have a pointer parameter.
	//void SetActorPosition(scale position);
};
