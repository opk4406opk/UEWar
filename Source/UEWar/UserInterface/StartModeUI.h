// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "StartModeUI.generated.h"

/**
 * 
 */

class UWidgetAnimation;

UCLASS(Blueprintable)
class UEWAR_API UStartModeUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void OnStartGame();
protected:
	virtual void NativeConstruct() override;
private:
	UPROPERTY(Meta=(BindWidgetAnim), Transient)
	UWidgetAnimation* OpenAnim;
};
