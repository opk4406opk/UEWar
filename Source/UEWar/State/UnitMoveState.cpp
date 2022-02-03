// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitMoveState.h"

#include "UnitStateManager.h"
#include "UEWar/Unit/GameUnitBase.h"

void UUnitMoveState::Init(UUnitStateManager* stateManager)
{
	Super::Init(stateManager);
}

void UUnitMoveState::Start(FStateUpdateParams updateParams)
{
	Super::Start(updateParams);
	StateManagerInstance->Owner->PlayAnimation(EGameUnitAnimType::Run);
}

void UUnitMoveState::End()
{
	Super::End();
}

void UUnitMoveState::TickProcess(float deltaTime)
{
	Super::TickProcess(deltaTime);
}

UUnitMoveState::~UUnitMoveState()
{
}
