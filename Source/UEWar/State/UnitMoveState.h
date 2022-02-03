// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitStateBase.h"
#include "UnitMoveState.generated.h"

/**
 * 
 */
UCLASS()
class UEWAR_API UUnitMoveState : public UUnitStateBase
{
	GENERATED_BODY()
public:
	virtual void Init(UUnitStateManager* stateManager) override;
	virtual void Start(FStateUpdateParams updateParams) override;
	virtual void End() override;
	virtual void TickProcess(float deltaTime) override;
	~UUnitMoveState() override;
};
