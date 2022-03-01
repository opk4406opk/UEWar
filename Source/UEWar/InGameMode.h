// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEWarGameModeBase.h"
#include "InGameMode.generated.h"

/**
 * 
 */
class UInGameUI;
class AInGameLevelScriptActor;

UCLASS()
class UEWAR_API AInGameMode : public AUEWarGameModeBase
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
public:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void Tick(float DeltaSeconds) override;
private:
	UPROPERTY(Transient)
	AInGameLevelScriptActor* CurrentLevelScriptActor;
	UPROPERTY(Transient)
	TObjectPtr<UInGameUI> MainUIInstance = nullptr;

	float IntroTimeSec = 0.0f;
	float ElapsedTimeSec = 0.0f;
	bool bOncePlayIntroAnim = false;
};
