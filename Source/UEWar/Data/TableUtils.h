// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "TableUtils.generated.h"
/**
 * 
 */


#define GENERATED_TABLE_CODE() \
UPROPERTY(EditAnywhere, BlueprintReadWrite) \
FName Code; \



class UEWAR_API TableUtils
{
private:
	TableUtils();
	~TableUtils();
};

USTRUCT(BlueprintType)
struct FCustomTableRowBase : public FTableRowBase
{
	GENERATED_BODY()
public:
};
