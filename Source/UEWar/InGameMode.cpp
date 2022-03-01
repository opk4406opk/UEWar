// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMode.h"
#include "InGameLevelScriptActor.h"
#include "UWGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraAnim.h"
#include "Camera/CameraAnimInst.h"
#include "Controller/InGamePlayerController.h"
#include "Data/CameraDataAsset.h"
#include "Data/GameDataSupervisor.h"
#include "Data/UIWidgetsAsset.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"
#include "Unit/PlayerCommanderUnit.h"
#include "UserInterface/InGameUI.h"

void AInGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLevelScriptActor = Cast<AInGameLevelScriptActor>(GetWorld()->GetLevelScriptActor());
	
	UCameraAnim* introAnim = GetGameInstance()->GetDataSupervisor()->CameraDataAssetPtr.LoadSynchronous()->IntroCameraAnim;
	check(introAnim);
	
	const AInGamePlayerController* playerController = Cast<AInGamePlayerController>(GetWorld()->GetFirstPlayerController());
	const UCameraAnimInst* animInst = playerController->PlayerCameraManager->PlayCameraAnim(introAnim);
	IntroTimeSec = animInst->CamAnim->AnimLength;
}

void AInGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AInGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);

	MainUIInstance = CreateWidget<UInGameUI>(GetWorld(), GetGameInstance()->GetDataSupervisor()->UIWidgetsAssetPtr.LoadSynchronous()->InGameUIClass);
	check(MainUIInstance);
	MainUIInstance->AddToViewport();

	bOncePlayIntroAnim = false;

	PrimaryActorTick.bCanEverTick = true;
}

void AInGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if(bOncePlayIntroAnim == false)
	{
		ElapsedTimeSec += DeltaSeconds;
		if(ElapsedTimeSec >= IntroTimeSec)
		{
			bOncePlayIntroAnim = true;
			const FVector spawnLocation = CurrentLevelScriptActor->PlayerStartPoint->GetActorLocation();
			auto ttt = GetGameInstance()->GetDataSupervisor()->UnitBPDataAssetPtr.LoadSynchronous();
			auto t = ttt->PlayerUnitBP->GetClass();
			auto testvalue = APlayerCommanderUnit::StaticClass();
			APlayerCommanderUnit* playerUnit = GetWorld()->SpawnActor<APlayerCommanderUnit>(testvalue);
			playerUnit->SetActorLocation(spawnLocation);
		}
	}
}