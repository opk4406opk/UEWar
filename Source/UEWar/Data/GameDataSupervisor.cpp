// Fill out your copyright notice in the Description page of Project Settings.


#include "GameDataSupervisor.h"

#include "MeleeUnitDataAsset.h"

FUnitAnimGroup* UGameDataSupervisor::GetUnitAnimGroup(EGameUnitType unitType) const
{
	return MeleeUnitDataAssetPtr.LoadSynchronous()->GetAnimGroup(unitType);
}
