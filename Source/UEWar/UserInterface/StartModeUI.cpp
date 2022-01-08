// Fill out your copyright notice in the Description page of Project Settings.


#include "StartModeUI.h"

#include "Kismet/GameplayStatics.h"
#include "UEWar/StartGameMode.h"

void UStartModeUI::OnStartGame()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(GetWorld(), InGameLevelPtr);
}

void UStartModeUI::NativeConstruct()
{
	Super::NativeConstruct();
	PlayAnimation(OpenAnim);

	AStartGameMode* startMode = Cast<AStartGameMode>(GetWorld()->GetAuthGameMode());
	check(startMode);
	InGameLevelPtr = startMode->InGameLevelPtr;
}
