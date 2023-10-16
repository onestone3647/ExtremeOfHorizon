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

	// 컨트롤러가 회전 할 때 회전하지 않고 카메라에 영향을 받음
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// 캐릭터 이동 설정
	GetCharacterMovement()->bOrientRotationToMovement = true;			// 캐릭터가 움직이는 방향으로 자동으로 회전한다. 스켈레탈 메시를 이동 방향이 앞이 되도록 회전시킨다.
	GetCharacterMovement()->bUseControllerDesiredRotation = false;			// true일 때 캡슐컴포넌트 자체를 컨트롤러의 방향으로 부드럽게 회전시킨다.
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);		// 회전 속도를 지정해 이동 방향으로 캐릭터가 부드럽게 회전한다.
	//GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 800.0f;
	GetCharacterMovement()->AirControl = 0.2f;

	// 최대 속도 설정
	SprintSpeed = 800.0f;
	NormalSpeed = 400.0f;
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;

	// 중력 설정
	NomalGravity = 1.0f;
	JumpGravity = 1.8f;

	// 캐릭터 위치 설정
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -90.0f), FRotator(0.0f, -90.0f, 0.0f));

	// 카메라 타겟, 스탯 설정
	CharacterStat = CreateDefaultSubobject<UEOHCharacterStatComponent>(TEXT("CharacterStat"));
	CharacterStat->TeamNum = 0;
}

// Called when the game starts or when spawned
void AEOHCharacterBase::BeginPlay()
{
	Super::BeginPlay();

}

