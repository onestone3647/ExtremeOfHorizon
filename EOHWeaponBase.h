// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EOHWeaponBase.generated.h"

UCLASS()
class EXTREMEOFHORIZON_API AEOHWeaponBase : public AActor
{
	GENERATED_BODY()

	public:
	// Sets default values for this actor's properties
	AEOHWeaponBase();

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
	class USceneComponent* Root;

	//UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Weapon", Meta = (AllowPrivateAccess = "true"))
	//class USkeletalMeshComponent* WeaponMesh;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WeaponCollisionTop;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* WeaponCollisionBottom;

	UPROPERTY(BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	TArray<UBoxComponent*> WeaponCollisions;

	UPROPERTY(BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	TArray<FVector> AttackTraceStartLocation;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	float OffsetBetweenWeaponCollisions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	int TracesPerSwing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	bool bDrawCollisionDebug;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponCollision", Meta = (AllowPrivateAccess = "true"))
	bool bDrawSkillCollisionDebug;

private:
	UPROPERTY(BlueprintReadWrite, Category = "WeaponHit", Meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> HitActors;

	UPROPERTY(BlueprintReadWrite, Category = "WeaponHit", Meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> AlreadyHitActors;

	UPROPERTY(BlueprintReadWrite, Category = "WeaponHit", Meta = (AllowPrivateAccess = "true"))
	FHitResult LastHit;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	float Damage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	FName EquipSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	FName UnequipSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> LightAttackMontages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> SmashMontages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	TArray<UAnimMontage*> SkillMontages;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponStat", Meta = (AllowPrivateAccess = "true"))
	float SkillDamage;
};
