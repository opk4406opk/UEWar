// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "GameFramework/PlayerStart.h"
#include "InGameLevelScriptActor.generated.h"

/**
 * 
 */
class APlayerStart;
class ACameraActor;

UCLASS()
class UEWAR_API AInGameLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<ACameraActor> FixedCameraActor;
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<APlayerStart> PlayerStartPoint;
};
