// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitStateManager.h"

#include "UnitIdleState.h"
#include "UnitStateBase.h"
#include "UnitMoveState.h"

void UUnitStateManager::Init(AGameUnitBase* owner)
{
	Owner = owner;
}

void UUnitStateManager::Change(EGameUnitState toState, FStateUpdateParams updateParams)
{
	if(toState == CurrentStateType) {return;}
	if(IsValid(CurrentStateInstance) == true) {CurrentStateInstance->End();}

	CurrentStateType = toState;
	switch (toState)
	{
	case EGameUnitState::None:
		break;
	case EGameUnitState::Idle:
		CurrentStateInstance = NewObject<UUnitIdleState>();
		break;
	case EGameUnitState::Move:
		CurrentStateInstance = NewObject<UUnitMoveState>();
		break;
	default: ;
	}

	CurrentStateInstance->Init(this);
	CurrentStateInstance->Start(updateParams);
}

void UUnitStateManager::TickProcess(float deltaTime)
{
}
