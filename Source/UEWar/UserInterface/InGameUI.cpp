// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameUI.h"

#include "Components/TextBlock.h"

void UInGameUI::NativeConstruct()
{
	Super::NativeConstruct();
	InGameModeInstance = Cast<AInGameMode>(GetWorld()->GetAuthGameMode());
}

void UInGameUI::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);
	FText fps = FText::FromString("FPS : " + FString::SanitizeFloat(InGameModeInstance->GetFPS()));
	TextBlock_FPS->SetText(fps);
}
