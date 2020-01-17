// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TestProjectCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

ATestProjectCharacter::ATestProjectCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector(0.f,0.f,75.f);
	CameraBoom->SetRelativeRotation(FRotator(0.f,180.f,0.f));

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("SideViewCamera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void ATestProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestProjectCharacter::MoveRight);
	PlayerInputComponent->BindAxis("MoveUp", this, &ATestProjectCharacter::MoveUp);
}

void ATestProjectCharacter::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.f,-1.f,0.f), Value);
}

void ATestProjectCharacter::MoveUp(float Value) {
	AddMovementInput(FVector(-1.f, 0.f, 0.f), Value);
}

// Called when the game starts or when spawned
void ATestProjectCharacter::BeginPlay()
{
	Super::BeginPlay();
	Spawn();
}

void ATestProjectCharacter::Spawn() {}

void ATestProjectCharacter::Death() {}

void ATestProjectCharacter::Active() {}

void ATestProjectCharacter::Pain() {}

void ATestProjectCharacter::Wound() {}

void ATestProjectCharacter::ConditionReceived() {}

void ATestProjectCharacter::ConditionFailed() {}

void ATestProjectCharacter::Idle() {}

void ATestProjectCharacter::Alert() {}

void ATestProjectCharacter::Missile() {}

void ATestProjectCharacter::Heal() {}

void ATestProjectCharacter::Raise() {}

void ATestProjectCharacter::Underwater() {}

// Player methods
void ATestProjectCharacter::PMove() {}

void ATestProjectCharacter::PJump() {}

void ATestProjectCharacter::PAttack() {}

void ATestProjectCharacter::PDefend() {}

void ATestProjectCharacter::PUseAbility() {}

//voiATestPlayerer::PUseItem() {}

void ATestProjectCharacter::PCrouch() {}

void ATestProjectCharacter::PFall() {}

void ATestProjectCharacter::PHide() {}