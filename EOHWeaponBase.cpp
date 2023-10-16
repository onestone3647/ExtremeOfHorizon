// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHWeaponBase.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "DrawDebugHelpers.h"

// Sets default values
AEOHWeaponBase::AEOHWeaponBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bDrawCollisionDebug = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;		// 액터를 대표할 루트 컴포넌트 지정

	//static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_Weapon(TEXT("SkeletalMesh'/Game/Weapon_Pack/Skeletal_Mesh/SK_Sword.SK_Sword'"));
	//if (SK_Weapon.Succeeded())
	//{
	//	Weapon->SetSkeletalMesh(SK_Weapon.Object);
	//}

	//Weapon->SetCollisionProfileName(TEXT("NoCollision"));

	//WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	//WeaponMesh->SetupAttachment(Root);

	WeaponCollisionTop = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionTop"));
	WeaponCollisionTop->SetupAttachment(Root);																	// Weapon의 자식으로 설정
	WeaponCollisionTop->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	// 무기 콜리전 관련
	WeaponCollisionBottom = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollisionBottom"));
	WeaponCollisionBottom->SetupAttachment(Root);																	// Weapon의 자식으로 설정
	WeaponCollisionBottom->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	EquipSocket = TEXT("hand_r_Weapon");
	UnequipSocket = TEXT("UnequipWeaponSocket");
}

