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
	// ī�޶� ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	class UEOHLockArmComponent* CameraLockArm;

	// ī�޶�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", Meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// �����е� ���� �潺ƽ Y��
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveForward(float NewAxisValue);
	// �����е� ���� �潺ƽ X��
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void MoveRight(float NewAxisValue);

	// ���콺 X��
	void Turn(float NewAxisValue);
	// ���콺 Y��
	void LookUp(float NewAxisValue);
	// �����е� ������ �潺ƽ X��
	//void TurnRate(float NewAxisValue);
	// �����е� ������ �潺ƽ Y��
	//void LookUpRate(float NewAxisValue);

	UPROPERTY(EditAnywhere, Category = "Movement")
	float VerticalLookRate;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float HorizontalLookRate;

private:
	// �޸���
	void Sprint();
	// �ȱ�
	void Walk();

private:
	// ����
	void Jump();
	// ������ �߷��� �����Ѵ�.
	void JumpGravityControl();

private:
	// ���� ���� �ʱ�ȭ
	UFUNCTION(BlueprintCallable, Category = "AttackState")
	void ResetAttack();

private:
	// ���� ���
	UFUNCTION(BlueprintCallable, Category = "ManaState")
	bool UseMana(float ManaValue);

	// ���� ����
	UFUNCTION(BlueprintCallable, Category = "ManaState")
	void ManaDecrease(float ManaValue);

private:
	// Ÿ�ٶ� ����
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
