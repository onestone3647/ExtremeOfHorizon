// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EOHCharacterBase.h"
#include "EOHPlayer.generated.h"

UENUM(BlueprintType)
enum class EDirection : uint8
{
	Forward			UMETA(DisplayName = "Forward"),
	ForwardLeft		UMETA(DisplayName = "ForwardLeft"),
	ForwardRight	UMETA(DisplayName = "ForwardRight"),
	Backward		UMETA(DisplayName = "Backward"),
	BackwardLeft	UMETA(DisplayName = "BackwardLeft"),
	BackwardRight	UMETA(DisplayName = "BackwardRight"),
	Left			UMETA(DisplayName = "Left"),
	Right			UMETA(DisplayName = "Right"),
};

/**
 *
 */
UCLASS()
class EXTREMEOFHORIZON_API AEOHPlayer : public AEOHCharacterBase
{
	GENERATED_BODY()

	public:
	AEOHPlayer();

private:
	// 카메라 지지대
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	class UEOHLockArmComponent* CameraLockArm;

	// 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// 게임패드 왼쪽 썸스틱 Y축
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveForward(float NewAxisValue);
	// 게임패드 왼쪽 썸스틱 X축
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveRight(float NewAxisValue);

	// 마우스 X축
	void Turn(float NewAxisValue);
	// 마우스 Y축
	void LookUp(float NewAxisValue);
	// 게임패드 오른쪽 썸스틱 X축
	//void TurnRate(float NewAxisValue);
	// 게임패드 오른쪽 썸스틱 Y축
	//void LookUpRate(float NewAxisValue);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float VerticalLookRate;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float HorizontalLookRate;

private:
	// 달리기
	void Sprint();
	// 걷기
	void Walk();

private:
	// 점프
	void Jump();
	// 점프의 중력을 설정한다.
	void JumpGravityControl();

private:
	// 공격 상태 초기화
	UFUNCTION(BlueprintCallable, Category = "AttackState")
	void ResetAttack();

private:
	// 마나 사용
	UFUNCTION(BlueprintCallable, Category = "ManaState")
	bool UseMana(float ManaValue);

	// 마나 감소
	UFUNCTION(BlueprintCallable, Category = "ManaState")
	void ManaDecrease(float ManaValue);

private:
	// 타겟락 해제
	UFUNCTION(BlueprintCallable, Category = "Target")
	void EndTargetLock();

private:
	UPROPERTY(BlueprintReadWrite, Category = "WeaponState", Meta = (AllowPrivateAccess = "true"))
	int32 SwitchWeapon;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "WeaponState", Meta = (AllowPrivateAccess = "true"))
	bool bSwitchWeaponCooltime;

private:
	UPROPERTY(BlueprintReadWrite, Category = "Movement", Meta = (AllowPrivateAccess = "true"))
	bool bSetMoveable;
};
