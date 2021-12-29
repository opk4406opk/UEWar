// Fill out your copyright notice in the Description page of Project Settings.


#include "StartGameMode.h"

#include "Data/UIWidgetsAsset.h"
#include "Data/GameDataSupervisor.h"
#include "UWGameInstance.h"

void AStartGameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AStartGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AStartGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	UUWGameInstance* gameInstance = Cast<UUWGameInstance>(GetWorld()->GetGameInstance());
	check(gameInstance);
	
	TableAssetInstance = gameInstance->GetDataSupervisor()->TableAssetPtr.LoadSynchronous();
	check(TableAssetInstance);
	TableAssetInstance->Initialize();

	MainUIInstance = CreateWidget<UStartModeUI>(GetWorld(), gameInstance->GetDataSupervisor()->UIWidgetsAssetPtr.LoadSynchronous()->StartModeUIClass);
	check(MainUIInstance);
	MainUIInstance->AddToViewport();

	auto playerController = GetWorld()->GetFirstPlayerController();
	if(IsValid(playerController) == true)
	{
		FInputModeGameAndUI inputMode;
		inputMode.SetHideCursorDuringCapture(false);
		inputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		playerController->SetInputMode(inputMode);
	}
	
	
}

void AStartGameMode::StartPlay()
{
	Super::StartPlay();
}
