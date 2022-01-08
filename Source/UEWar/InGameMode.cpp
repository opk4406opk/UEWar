// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMode.h"
#include "InGameLevelScriptActor.h"
#include "Runtime/Engine/Classes/Camera/CameraActor.h"

void AInGameMode::BeginPlay()
{
	Super::BeginPlay();
	
	CurrentLevelScriptActor = Cast<AInGameLevelScriptActor>(GetWorld()->GetLevelScriptActor());
}

void AInGameMode::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
