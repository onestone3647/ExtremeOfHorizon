// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHPlayerController.h"

void AEOHPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// ���ӿ��Ը� �Է��� �����ϵ��� ����(�÷��� ���� ����Ʈ�� Ŭ������ �ʾƵ� ��)
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
