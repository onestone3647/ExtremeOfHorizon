// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpringArmComponent.h"
#include "EOHLockArmComponent.generated.h"

UENUM(BlueprintType)
enum class ELeftRight : uint8
{
	Left	UMETA(DisplayName = "Left"),
	Right	UMETA(DisplayName = "Right"),
};

UENUM(BlueprintType)
enum class EDistance : uint8
{
	Nearest	UMETA(DisplayName = "Nearest"),
	Futhest	UMETA(DisplayName = "Futhest"),
};

/**
 *
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class EXTREMEOFHORIZON_API UEOHLockArmComponent : public USpringArmComponent
{
	GENERATED_BODY()
	
	UEOHLockArmComponent();

public:
	UPROPERTY(BlueprintReadOnly, Category = "Target")
	class UEOHCharacterStatComponent* CameraTarget;

	UPROPERTY(BlueprintReadWrite, Category = "Target")
	class AActor* TargetLockActor;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category = "Target")
	bool bLockedOnTarget;

private:
	// 타겟팅 할 수 잇는 최대 거리
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target", Meta = (AllowPrivateAccess = "true"))
	float MaxTargetLockDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target", Meta = (AllowPrivateAccess = "true"))
	bool bDrawDebug;
};
