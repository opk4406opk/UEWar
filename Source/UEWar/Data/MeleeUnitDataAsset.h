// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/UnitConversion.h"
#include "UEWar/GameEnumClass.h"
#include "MeleeUnitDataAsset.generated.h"

/**
 * 
 */

class UAnimSequence;

USTRUCT()
struct FUnitAnimGroup
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TMap<EGameUnitAnimType, TSoftObjectPtr<UAnimSequence>> Animations;
};

UCLASS(Blueprintable)
class UEWAR_API UMeleeUnitDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	FUnitAnimGroup* GetAnimGroup(EGameUnitType unitType);
public:
	UPROPERTY(EditDefaultsOnly)
	TMap<EGameUnitType, FUnitAnimGroup> AnimGroupPerType;
};
