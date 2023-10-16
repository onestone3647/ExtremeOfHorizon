// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHPlayerController.h"

void AEOHPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// 게임에게만 입력을 전달하도록 설정(플레이 마다 뷰포트를 클릭하지 않아도 됨)
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
