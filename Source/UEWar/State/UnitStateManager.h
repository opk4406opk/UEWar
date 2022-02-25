// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UEWar/GameEnumClass.h"
#include "UnitStateManager.generated.h"

/**
 * 
 */

struct FStateUpdateParams;
class AGameUnitBase;
class UUnitStateBase;

UCLASS()
class UEWAR_API UUnitStateManager : public UObject
{
	GENERATED_BODY()
public:
	void Init(AGameUnitBase* owner);
	void Change(EGameUnitState toState, FStateUpdateParams updateParams);
	void TickProcess(float deltaTime);
public:
	UPROPERTY(Transient)
	TObjectPtr<AGameUnitBase> Owner;
private:
	UPROPERTY(Transient)
	TObjectPtr<UUnitStateBase> CurrentStateInstance;

	EGameUnitState CurrentStateType = EGameUnitState::None;
};
