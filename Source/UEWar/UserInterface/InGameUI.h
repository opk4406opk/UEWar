// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UEWar/InGameMode.h"
#include "InGameUI.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class UEWAR_API UInGameUI : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
public:
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> TextBlock_FPS;
private:
	UPROPERTY(Transient)
	TObjectPtr<AInGameMode> InGameModeInstance;
};
