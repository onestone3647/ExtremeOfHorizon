// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHPlayer.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "EOHLockArmComponent.h"

AEOHPlayer::AEOHPlayer()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 카메라 지지대 설정
	//SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	//SpringArm->SetupAttachment(GetCapsuleComponent());
	//SpringArm->TargetArmLength = 450.0f;
	//SpringArm->SetRelativeRotation(FRotator::ZeroRotator);
	//SpringArm->bUsePawnControlRotation = true;
	//SpringArm->bInheritPitch = true;
	//SpringArm->bInheritRoll = true;
	//SpringArm->bInheritYaw = true;
	//SpringArm->bDoCollisionTest = true;											// 카메라 시선과 캐릭터 사이에 장애물이 감지되면 캐릭터가 보이도록 카메라를 장애물 앞으로 줌인한다.

	// 콜리전 설정
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("PRCharacter"));
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// 스프링 암 설정, 충돌이 발생하면 플레이어 쪽으로 끌어당긴다.
	CameraLockArm = CreateDefaultSubobject<UEOHLockArmComponent>(TEXT("CameraLockArm"));
	CameraLockArm->SetupAttachment(RootComponent);
	CameraLockArm->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	//CameraLockArm->SetRelativeLocation(FVector::ZeroVector);
	CameraLockArm->SocketOffset = FVector(0.0f, 0.0f, 30.0f);

	// 카메라 설정
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(CameraLockArm);
	Camera->bUsePawnControlRotation = false;		// 카메라가 팔에 의해 회전하지 않는다.

	// Movement 설정
	HorizontalLookRate = 45.0f;
	VerticalLookRate = 45.0f;

	// 팀을 플레이어로 설정
	CharacterStat->TeamNum = 1;

	SwitchWeapon = 0;
	bSwitchWeaponCooltime = false;

	bSetMoveable = true;

	bSkillCooltime1 = false;
	bSkillCooltime2 = false;
	bSkillCooltime3 = false;
	bSkillCooltime4 = false;
	bSkillCooltime5 = false;
	bSkillCooltime6 = false;
}

// Called every frame
void AEOHPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	JumpGravityControl();
}

// Called to bind functionality to input
void AEOHPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AEOHPlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AEOHPlayer::MoveRight);

	// 마우스 입력
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AEOHPlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AEOHPlayer::LookUp);

	// 아날로그 스틱 입력
	//PlayerInputComponent->BindAxis(TEXT("TurnRate"), this, &AEOHPlayer::TurnRate);
	//PlayerInputComponent->BindAxis(TEXT("LookUpRate"), this, &AEOHPlayer::LookUpRate);

	// Action inputs
	//PlayerInputComponent->BindAction("ToggleCameraLock", IE_Pressed, CameraLockArm, &UPRLockArmComponent::ToggleCameraLock);

	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &AEOHPlayer::Jump);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Pressed, this, &AEOHPlayer::Sprint);
	PlayerInputComponent->BindAction(TEXT("Sprint"), EInputEvent::IE_Released, this, &AEOHPlayer::Walk);
	//PlayerInputComponent->BindAction(TEXT("Dodge"), EInputEvent::IE_Pressed, this, &APRCharacterBase::Dodge);
	//PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &APRCharacterBase::Attack);
	//PlayerInputComponent->BindAction(TEXT("Smash"), EInputEvent::IE_Pressed, this, &APRCharacter::Smash);
}

void AEOHPlayer::MoveForward(float NewAxisValue)
{
	if ((Controller != NULL) && (NewAxisValue != 0.0f) && bSetMoveable)
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, NewAxisValue);
	}
}

void AEOHPlayer::MoveRight(float NewAxisValue)
{
	if ((Controller != NULL) && (NewAxisValue != 0.0f) && bSetMoveable)
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, NewAxisValue);
	}
}

void AEOHPlayer::Turn(float NewAxisValue)
{
	if (!(CameraLockArm->bLockedOnTarget))
	{
		AddControllerYawInput(NewAxisValue);
	}
}

void AEOHPlayer::LookUp(float NewAxisValue)
{
	if (!(CameraLockArm->bLockedOnTarget))
	{
		AddControllerPitchInput(NewAxisValue);
	}
}

//void AEOHPlayer::TurnRate(float NewAxisValue)
//{
//}
//
//void AEOHPlayer::LookUpRate(float NewAxisValue)
//{
//
//}

void AEOHPlayer::Sprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AEOHPlayer::Walk()
{
	GetCharacterMovement()->MaxWalkSpeed = NormalSpeed;
}

void AEOHPlayer::Jump()
{
	// 다른 행동 시 점프를 못하게 한다.
	if (!bCanDodge && !bCanAttack)
	{
		ACharacter::Jump();
	}
}

void AEOHPlayer::JumpGravityControl()
{
	// 점프 후 내려올 때 중력 값을 조절한다.
	if (GetCharacterMovement()->IsFalling())
	{
		GetCharacterMovement()->GravityScale = JumpGravity;
	}
	else
	{
		GetCharacterMovement()->GravityScale = NomalGravity;
	}
}

void AEOHPlayer::ResetAttack()
{
	bSetMoveable = true;
	bLightAttack = false;
	bSmashAttack = false;
	bSkillAttack = false;
	bLastAttack = false;
	bChainAttack = false;

	ChainLightAttack = 0;
	ChainSmashAttack = 0;
	ChainSkillAttack = 0;
}

bool AEOHPlayer::UseMana(float ManaValue)
{
	return (ManaValue > CharacterStat->CurrentMana);
}

void AEOHPlayer::ManaDecrease(float ManaValue)
{
	float CurrentMana = CharacterStat->CurrentMana;

	if (CurrentMana >= ManaValue)
	{
		CurrentMana -= ManaValue;
	}
	else
	{
		return;
	}
}

void AEOHPlayer::EndTargetLock()
{
	CameraLockArm->bLockedOnTarget = false;
	CameraLockArm->TargetLockActor = nullptr;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bUseControllerDesiredRotation = false;
}

