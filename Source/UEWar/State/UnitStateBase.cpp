// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitStateBase.h"

void UUnitStateBase::Init(UUnitStateManager* stateManager)
{
	StateManagerInstance = stateManager;
}

void UUnitStateBase::Start(FStateUpdateParams updateParams)
{
}

void UUnitStateBase::End()
{
}

void UUnitStateBase::TickProcess(float deltaTime)
{
}
