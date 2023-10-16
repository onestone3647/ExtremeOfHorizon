// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHLockArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "GameFramework/Pawn.h"
#include "EOHCharacterStatComponent.h"

#define print(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Green, text)

UEOHLockArmComponent::UEOHLockArmComponent()
{
	MaxTargetLockDistance = 900.0f;

	//TargetArmLength = 300.0f;
	TargetArmLength = 400.0f;
	bUsePawnControlRotation = true;		// 컨트롤러를 중심으로 회전한다.
	bInheritPitch = true;
	bInheritRoll = true;
	bInheritYaw = true;
	bDoCollisionTest = true;		// 카메라 시선과 캐릭터 사이에 장애물이 감지되면 캐릭터가 보이도록 카메라를 장애물 앞으로 줌인한다.

	bEnableCameraLag = true;		// true인 경우 카메라가 목표 위치보다 뒤떨어져 이동을 원활하게 한다.
	bEnableCameraRotationLag = false;		// true인 경우 카메라가 이동을 부드럽게하기 위해 대상 회전보다 뒤떨어져 있다.
	CameraLagSpeed = 3.0f;				// bEnableameraLag가 true인 경우 카메라가 목표 위치에 도달하는 속도를 제어한다.
	CameraRotationLagSpeed = 2.0f;		// bEnableCameraRotationLag가 true인 경우 카메라가 목표 위치에 도달하는 속도를 제어한다.
	CameraLagMaxDistance = 100.0f;		// 타겟의 뒤의 현재 위치에 대한 최대 거리
}

