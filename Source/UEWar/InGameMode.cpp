// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMode.h"
#include "InGameLevelScriptActor.h"
#include "UWGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Data/GameDataSupervisor.h"
#include "Data/UIWidgetsAsset.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "UserInterface/InGameUI.h"

void AInGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLevelScriptActor = Cast<AInGameLevelScriptActor>(GetWorld()->GetLevelScriptActor());

}

void AInGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AInGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	
	UUWGameInstance* gameInstance = Cast<UUWGameInstance>(GetWorld()->GetGameInstance());
	check(gameInstance);
	
	MainUIInstance = CreateWidget<UInGameUI>(GetWorld(), gameInstance->GetDataSupervisor()->UIWidgetsAssetPtr.LoadSynchronous()->InGameUIClass);
	check(MainUIInstance);
	MainUIInstance->AddToViewport();
}
