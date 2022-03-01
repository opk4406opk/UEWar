// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UEWar/Unit/PlayerCommanderUnit.h"
#include "UnitBPDataAsset.generated.h"

/**
 * 
 */

class AGameUnitBase;
class APlayerCommanderUnit;

UCLASS()
class UEWAR_API UUnitBPDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AGameUnitBase> PlayerUnitBP;
};
