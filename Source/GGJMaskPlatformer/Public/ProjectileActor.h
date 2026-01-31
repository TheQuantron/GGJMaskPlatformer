// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthComponent.h"
#include "PlayableCharacter.h"
#include "ProjectileActor.generated.h"

class UHealthComponent;

UCLASS()
class GGJMASKPLATFORMER_API AProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float DamageNum;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float FireSpeed;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UDamageType> DamageType;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<UHealthComponent> HealthComp;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<APlayableCharacter> PlayerChar;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	TObjectPtr<APlayerController> PlayerCont;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
