// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMode.h"
#include "InGameLevelScriptActor.h"
#include "LevelSequenceActor.h"
#include "LevelSequencePlayer.h"
#include "UWGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Data/CameraDataAsset.h"
#include "Data/GameDataSupervisor.h"
#include "Data/UIWidgetsAsset.h"
#include "LevelSequence/Public/LevelSequence.h"
#include "MovieSceneSequencePlayer.h"
#include "Unit/PlayerCommanderUnit.h"
#include "UserInterface/InGameUI.h"

void AInGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLevelScriptActor = Cast<AInGameLevelScriptActor>(GetWorld()->GetLevelScriptActor());
	
	ULevelSequence* introAnimSeq = GetGameInstance()->GetDataSupervisor()->CameraDataAssetPtr.LoadSynchronous()->IntroCameraAnimSeq;
	check(introAnimSeq);

	FMovieSceneSequencePlaybackSettings playsetting;
	ALevelSequenceActor* outActor = nullptr;
	LevelSeqPlayer = ULevelSequencePlayer::CreateLevelSequencePlayer(GetWorld(), introAnimSeq, playsetting, outActor);
	LevelSeqActor = outActor;
	check(LevelSeqPlayer);
	check(LevelSeqActor);

	OnFinishIntroSeq.BindUFunction(this, TEXT("OnFinishIntroSeq_Internal"));
	LevelSeqPlayer->OnFinished.Add(OnFinishIntroSeq);
	LevelSeqPlayer->Play();
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

	PrimaryActorTick.bCanEverTick = true;
}

void AInGameMode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}

void AInGameMode::OnFinishIntroSeq_Internal()
{
	const FVector spawnLocation = CurrentLevelScriptActor->PlayerStartPoint->GetActorLocation();
	auto bpData = GetGameInstance()->GetDataSupervisor()->UnitBPDataAssetPtr.LoadSynchronous();
	APlayerCommanderUnit* playerUnit = GetWorld()->SpawnActor<APlayerCommanderUnit>(bpData->PlayerUnitBP.Get());
	playerUnit->SetActorLocation(spawnLocation);
}
