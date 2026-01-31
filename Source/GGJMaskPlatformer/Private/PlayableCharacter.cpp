// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayableCharacter::APlayableCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	SetRootComponent(CapsuleComp);
	CapsuleComp->SetCollisionObjectType(ECC_Pawn);
	CapsuleComp->SetCollisionEnabled(ECollisionEnabled::Type::QueryAndPhysics);
	CapsuleComp->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
	
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(GetRootComponent());

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComp->SetupAttachment(GetRootComponent());
	SpringArmComp->SetRelativeRotation(FRotator(0, 0, 0));
	SpringArmComp->TargetArmLength = SpringArmLength;
	SpringArmComp->bDoCollisionTest = false;
	SpringArmComp->bInheritYaw = false;
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComp->SetupAttachment(SpringArmComp);
	CameraComp->SetProjectionMode(ECameraProjectionMode::Orthographic);

	MovementComp = CreateDefaultSubobject<UCharacterMovementComponent>(TEXT("MovementComponent"));
	HealthComp = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
	PlayerController = CreateDefaultSubobject<APlayerController>(TEXT("PlayerController"));
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
}

// Called when the game starts or when spawned
void APlayableCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* NewInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		NewInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &APlayableCharacter::DoAttack);
		NewInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &APlayableCharacter::DoMove);
		NewInputComponent->BindAction(JumpAction, ETriggerEvent::Triggered, this, &APlayableCharacter::DoJump);
		NewInputComponent->BindAction(InteractAction, ETriggerEvent::Triggered, this, &APlayableCharacter::DoInteract);
		NewInputComponent->BindAction(DodgeAction, ETriggerEvent::Triggered, this, &APlayableCharacter::DoDodge);
	}

}

void APlayableCharacter::DoAttack(const FInputActionValue& InputValue)
{

}

void APlayableCharacter::DoMove(const FInputActionValue& InputValue)
{
	FVector2D Direction = InputValue.Get<FVector2D>();
	LastControlInputVector.X = Direction.X;
	LastControlInputVector.Y = Direction.Y;

	FRotator MoveDirection = FRotator( GetControlRotation().Pitch, GetControlRotation().Yaw, 0);

	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::ForwardVector) * Direction.X);
	GetMovementComponent()->AddInputVector(MoveDirection.RotateVector(FVector::ForwardVector) * Direction.Y);
}

void APlayableCharacter::DoJump(const FInputActionValue& InputValue)
{
	
}

void APlayableCharacter::DoInteract(const FInputActionValue& InputValue)
{
	
}

void APlayableCharacter::DoDodge(const FInputActionValue& InputValue)
{
	
}
