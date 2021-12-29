// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "TableAsset.generated.h"

class UDataAsset;
class UDataTable;

UENUM()
enum class TableType : int8
{
	None,
	Unit,
};
/**
 * 
 */
UCLASS(Blueprintable)
class UEWAR_API UTableAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	virtual void PostLoad() override;
	virtual void Serialize(FArchive& Ar) override;

	void Initialize();
public:
	UPROPERTY(EditDefaultsOnly)
	TMap<TableType, TSoftObjectPtr<UDataTable>> TableMap; 
};
