// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UEWarGameModeBase.h"
#include "Runtime/Core/Public/UObject/ScriptDelegates.h"
#include "InGameMode.generated.h"

/**
 * 
 */
class UInGameUI;
class AInGameLevelScriptActor;
class ULevelSequencePlayer;
class ALevelSequenceActor;

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
	UFUNCTION()
	void OnFinishIntroSeq_Internal();
private:
	UPROPERTY(Transient)
	AInGameLevelScriptActor* CurrentLevelScriptActor;
	UPROPERTY(Transient)
	TObjectPtr<UInGameUI> MainUIInstance = nullptr;

	UPROPERTY(Transient)
	TObjectPtr<ULevelSequencePlayer> LevelSeqPlayer = nullptr;
	UPROPERTY(Transient)
	TObjectPtr<ALevelSequenceActor> LevelSeqActor = nullptr;
	
	TScriptDelegate<FWeakObjectPtr> OnFinishIntroSeq; 
};
