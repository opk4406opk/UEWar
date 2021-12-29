// Fill out your copyright notice in the Description page of Project Settings.


#include "StartModeUI.h"

#include "Kismet/GameplayStatics.h"

void UStartModeUI::OnStartGame()
{
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("InGameLevel"));
}

void UStartModeUI::NativeConstruct()
{
	Super::NativeConstruct();
	PlayAnimation(OpenAnim);
}
