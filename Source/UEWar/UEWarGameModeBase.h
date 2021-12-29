// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UEWarGameModeBase.generated.h"

class UUWGameInstance;
/**
 * 
 */
UCLASS()
class UEWAR_API AUEWarGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UUWGameInstance* GetGameInstance();
private:
	UPROPERTY(Transient)
	UUWGameInstance* CurGameInstance;
};
