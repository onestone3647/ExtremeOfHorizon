// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHCharacterBase.h"

// Sets default values
AEOHCharacterBase::AEOHCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bCanDodge = false;
	bCanAttack = false;
	bIsWeaponEquipped = false;
	bIsDead = false;
	bIsHit = false;

	// ��Ʈ�ѷ��� ȸ�� �� �� ȸ������ �ʰ� ī�޶� ������ ����
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// ĳ���� �̵� ����
	GetCharacterMovement()->bOrientRotationToMovement = true;			// ĳ���Ͱ� �����̴� �������� �ڵ����� ȸ���Ѵ�. ���̷�Ż �޽ø� �̵� ������ ���� �ǵ��� ȸ����Ų��.
	GetCharacterMovement()->bUseControllerDesiredRotation = false;			// true�� �� ĸ��������Ʈ ��ü�� ��Ʈ�ѷ��� �������� �ε巴�� ȸ����Ų��.
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);		// ȸ�� �ӵ��� ������ �̵� �������� ĳ���Ͱ� �ε巴�� ȸ���Ѵ�.
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 800.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	// �ִ� �ӵ� ����
	SprintSpeed = 800.0f;
	NormalSpeed = 400.0f;
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

	// �߷� ����
	NomalGravity = 1.0f;
	JumpGravity = 1.8f;

	// ĳ���� ��ġ ����
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -90.0f, 0.0f));

	// ī�޶� Ÿ��, ���� ����
	CharacterStat = CreateDefaultSubobject<UEOHCharacterStatComponent>(TEXT("CharacterStat"));
	CharacterStat->TeamNum = 0;
}

// Called when the game starts or when spawned
void AEOHCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

