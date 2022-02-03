// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UEWar/GameEnumClass.h"
#include "UnitStateBase.generated.h"

class UUnitStateManager;

struct FStateUpdateParams
{
	
};

/**
 * 
 */
UCLASS()
class UEWAR_API UUnitStateBase : public UObject
{
	GENERATED_BODY()

public:
	virtual void Init(UUnitStateManager* stateManager);
	virtual void Start(FStateUpdateParams updateParams);
	virtual void End();
	virtual void TickProcess(float deltaTime);
protected:
	UPROPERTY(Transient)
	TObjectPtr<UUnitStateManager> StateManagerInstance;

	EGameUnitType UnitType = EGameUnitType::None;
};
