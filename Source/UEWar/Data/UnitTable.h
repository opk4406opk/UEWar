// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TableUtils.h"
#include "UnitTable.generated.h"

USTRUCT(BlueprintType)
struct FUnitTable : public FCustomTableRowBase
{
	GENERATED_BODY()

public:
	GENERATED_TABLE_CODE()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Hp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Mp;
};
