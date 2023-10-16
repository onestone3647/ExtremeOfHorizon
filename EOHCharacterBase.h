// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EOHCharacterStatComponent.h"
#include "EOHCharacterBase.generated.h"

UCLASS()
class EXTREMEOFHORIZON_API AEOHCharacterBase : public ACharacter
{
	GENERATED_BODY()

	public:
	// Sets default values for this character's properties
	AEOHCharacterBase();
public:
	class UEOHCharacterStatComponent* GetCharacterStat()
	{
		return CharacterStat;
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
protected:
	// Ä«¸Þ¶ó Å¸°Ù, Ä³¸¯ÅÍ ½ºÅÝ ÄÄÆ÷³ÍÆ®
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CharacterStat", Meta = (AllowPrivateAccess = "true"))
	class UEOHCharacterStatComponent* CharacterStat;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	float NomalGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	float JumpGravity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveSpeed")
	float SprintSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveSpeed")
	float NormalSpeed;

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "WeaponState")
	bool bIsWeaponSet;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "WeaponState")
	bool bIsWeaponEquipped;

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bCanAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bLightAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSmashAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSmashCooltime;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime1;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime2;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime3;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime4;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime5;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bSkillCooltime6;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bChainAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	int	ChainLightAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	int ChainSmashAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	int ChainSkillAttack;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "AttackState")
	bool bLastAttack;

public:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "DodgeState")
	bool bCanDodge;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "State")
	UAnimMontage* HitAnimMontages;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "State")
	bool bIsDead;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "State")
	bool bIsHit;
};
