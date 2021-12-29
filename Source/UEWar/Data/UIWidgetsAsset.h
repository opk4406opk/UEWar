// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UIWidgetsAsset.generated.h"

class UStartModeUI;
/**
 * 
 */
UCLASS()
class UEWAR_API UUIWidgetsAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category="ObjectPtr")
	TSubclassOf<UStartModeUI> StartModeUIClass;
};
