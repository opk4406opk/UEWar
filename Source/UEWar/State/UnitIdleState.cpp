// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitIdleState.h"

#include "UnitStateManager.h"
#include "UEWar/Unit/GameUnitBase.h"

void UUnitIdleState::Init(UUnitStateManager* stateManager)
{
	Super::Init(stateManager);
}

void UUnitIdleState::Start(FStateUpdateParams updateParams)
{
	Super::Start(updateParams);
	StateManagerInstance->Owner->PlayAnimation(EGameUnitAnimType::Idle);
}

void UUnitIdleState::End()
{
	Super::End();
}

void UUnitIdleState::TickProcess(float deltaTime)
{
	Super::TickProcess(deltaTime);
}

UUnitIdleState::~UUnitIdleState()
{
}
