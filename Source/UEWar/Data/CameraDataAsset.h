// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CameraDataAsset.generated.h"

/**
 * 
 */

class UCameraAnim;

UCLASS()
class UEWAR_API UCameraDataAsset : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCameraAnim> IntroCameraAnim;
};
