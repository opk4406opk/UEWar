// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitStateBase.h"
#include "UnitIdleState.generated.h"

/**
 * 
 */
UCLASS()
class UEWAR_API UUnitIdleState : public UUnitStateBase
{
	GENERATED_BODY()
public:
	virtual void Init(UUnitStateManager* stateManager) override;
	virtual void Start(FStateUpdateParams updateParams) override;
	virtual void End() override;
	virtual void TickProcess(float deltaTime) override;
	~UUnitIdleState() override;
};
