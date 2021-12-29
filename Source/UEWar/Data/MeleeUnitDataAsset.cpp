// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeUnitDataAsset.h"

FUnitAnimGroup* UMeleeUnitDataAsset::GetAnimGroup(EGameUnitType unitType)
{
	return AnimGroupPerType.Find(unitType);
}
