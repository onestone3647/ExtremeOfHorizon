// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EOHCharacterStatComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class EXTREMEOFHORIZON_API UEOHCharacterStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEOHCharacterStatComponent();

protected:
	// 액터의 PostInitializeComponent()에 대응하는 컴포넌트, 액터의 PostInitializeComponents함수가 호출되기 바로 전에 호출된다.
	virtual void InitializeComponent() override;

public:
	void SetStat();

public:
	// 1 = 플레이어, 2 = 적, 3 = NPC
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 TeamNum;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Stat")
	float CurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float MaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Stat")
	float CurrentMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 SkiilLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 SkillPoint;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 SkillMaxPoint;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category = "Stat")
	int32 CurrentExp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	int32 ExpMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
	float Attack;
};
