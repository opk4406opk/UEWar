// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEWarGameModeBase.h"
#include "InGameMode.generated.h"

/**
 * 
 */

class AInGameLevelScriptActor;

UCLASS()
class UEWAR_API AInGameMode : public AUEWarGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	UPROPERTY(Transient)
	AInGameLevelScriptActor* CurrentLevelScriptActor;
};
