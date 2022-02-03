// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UIWidgetsAsset.generated.h"

class UStartModeUI;
class UInGameUI;
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
	UPROPERTY(EditDefaultsOnly, Category="ObjectPtr")
	TSubclassOf<UInGameUI> InGameUIClass;
};
