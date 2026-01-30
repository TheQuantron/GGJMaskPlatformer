// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "HealthComponent.h"
#include "GameFramework/Character.h"
#include "PlayableCharacter.generated.h"

#pragma region Classes  
class UStaticMesh;
class UInputComponent;
class UCameraComponent;
class UCharacterMovementComponent;
class UCapsuleComponent;
class UHealthComponent;
class UInputAction;
struct FInputActionValue;
#pragma endregion

UCLASS()
class GGJMASKPLATFORMER_API APlayableCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayableCharacter();

#pragma region Properties
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlayerHealth;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlayerSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float PlayerAttackSpeed;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UCameraComponent> CameraComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UCharacterMovementComponent> MovementComp;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UCapsuleComponent> CapsuleComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UHealthComponent> HealthComp;
	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UInputComponent> InputComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* AttackAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* MoveAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* JumpAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* InteractAction;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Input")
	UInputAction* DodgeAction;

#pragma endregion

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

#pragma region Functions	
	UFUNCTION(BlueprintCallable)
	void DoAttack(const FInputActionValue& InputValue);
	
	UFUNCTION(BlueprintCallable)
	void DoMove(const FInputActionValue& InputValue);
	
	UFUNCTION(BlueprintCallable)
	void DoJump(const FInputActionValue& InputValue);
	
	UFUNCTION(BlueprintCallable)
	void DoInteract(const FInputActionValue& InputValue);

	UFUNCTION(BlueprintCallable)
	void DoDodge(const FInputActionValue& InputValue);

#pragma endregion
};
