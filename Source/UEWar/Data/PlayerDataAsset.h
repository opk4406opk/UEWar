// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "UEWar/GameEnumClass.h"
#include "PlayerDataAsset.generated.h"

class UAnimSequence;

UCLASS()
class UEWAR_API UPlayerDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TMap<EPlayerAnimType, TSoftObjectPtr<UAnimSequence>> Animations;
};
