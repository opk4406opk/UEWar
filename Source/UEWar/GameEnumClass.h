// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EGameUnitType : uint8
{
	None,
	Spear,
	Sword,
	Ranger,
	Commander,
	Count,
};

UENUM(BlueprintType)
enum class EGameUnitState : uint8
{
	None,
	Idle,
	Move,
};

UENUM(BlueprintType)
enum class EGameUnitAnimType : uint8
{
	None,
	Idle,
	Walk,
	Run,
	Attack,
	Defeat,
	Dead,
	Count,
};

UENUM(BlueprintType)
enum class EPlayerAnimType : uint8
{
	None,
	Idle,
	Walk,
	Run,
	Count,
};

/**
 * 
 */
class UEWAR_API GameEnumClass
{
private:
	GameEnumClass();
	~GameEnumClass();
};
