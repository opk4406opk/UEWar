// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEWarGameModeBase.h"
#include "Data/TableAsset.h"
#include "UserInterface/StartModeUI.h"
#include "StartGameMode.generated.h"

class UStartModeUI;
class UUIWidgetsAsset;
/**
 * 
 */
UCLASS()
class UEWAR_API AStartGameMode : public AUEWarGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void StartPlay() override;
public:
	
private:
	UPROPERTY(Transient)
	UTableAsset* TableAssetInstance = nullptr;
	UPROPERTY(Transient)
	UStartModeUI* MainUIInstance = nullptr;
};
