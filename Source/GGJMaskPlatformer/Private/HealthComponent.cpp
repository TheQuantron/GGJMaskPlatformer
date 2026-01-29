// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = Health;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OnDamageEvent);
	
}

void UHealthComponent::OnDamageEvent(AActor* DamagedActor, float Damage, const class UDamageType* DamageType,
		class AController* InstigatedBy, class AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, Health);

	if (CurrentHealth <= 0.0f)
	{
		if (OnDeath.IsBound())
			OnDeath.Broadcast();
	}
}


void UHealthComponent::OnHealEvent(AActor* HealedActor, float Heal, const class UDamageType* HealType,
	class AController* InstigatedBy, class AActor* DamageCauser)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Heal, 1.0f, Health);

	if (CurrentHealth >= 1.0f && CurrentHealth < Health)
	{
		CurrentHealth = CurrentHealth + Heal;
	}
}