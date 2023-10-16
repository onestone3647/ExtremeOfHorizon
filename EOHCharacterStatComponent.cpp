// Fill out your copyright notice in the Description page of Project Settings.


#include "EOHCharacterStatComponent.h"

// Sets default values for this component's properties
UEOHCharacterStatComponent::UEOHCharacterStatComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// InitializeComponent �Լ��� ����ϱ� ���� �� ���� true�� �����ؾ��Ѵ�.
	bWantsInitializeComponent = true;

	MaxHealth = 300.0f;
	CurrentHealth = MaxHealth;
	MaxMana = 200.0f;
	CurrentMana = MaxMana;
}

// Called when the game starts
void UEOHCharacterStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

	SetStat();
}

void UEOHCharacterStatComponent::SetStat()
{
	CurrentHealth = MaxHealth;
	CurrentMana = MaxMana;
}

