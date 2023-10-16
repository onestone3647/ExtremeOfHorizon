// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EOHAnimInstanceBase.generated.h"

/**
 * 
 */
UCLASS()
class EXTREMEOFHORIZON_API UEOHAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UEOHAnimInstanceBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveSpeed")
	float CurrentCharacterSpeed;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsInAir;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	bool bIsDead;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponEquip")
	bool bIsWeaponEquippedAnimBP;
};
