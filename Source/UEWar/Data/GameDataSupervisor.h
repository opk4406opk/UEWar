// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerDataAsset.h"
#include "UnitBPDataAsset.h"
#include "Engine/DataAsset.h"
#include "UEWar/GameEnumClass.h"
#include "GameDataSupervisor.generated.h"


class UMeleeUnitDataAsset;
class UTableAsset;
class UUIWidgetsAsset;
class UPlayerDataAsset;
class UCameraDataAsset;
class UUnitBPDataAsset;

struct FUnitAnimGroup;
/**
 * 
 */
UCLASS(Blueprintable)
class UEWAR_API UGameDataSupervisor final : public UDataAsset
{
	GENERATED_BODY()

public:
	FUnitAnimGroup* GetUnitAnimGroup(EGameUnitType unitType) const;
public:
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UPlayerDataAsset> PlayerDataAssetPtr;
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UMeleeUnitDataAsset> MeleeUnitDataAssetPtr;
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UTableAsset> TableAssetPtr;
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UUIWidgetsAsset> UIWidgetsAssetPtr;
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UCameraDataAsset> CameraDataAssetPtr;
	UPROPERTY(EditDefaultsOnly, Category="DataAsset_ObjectPtr")
	TSoftObjectPtr<UUnitBPDataAsset> UnitBPDataAssetPtr;
};
