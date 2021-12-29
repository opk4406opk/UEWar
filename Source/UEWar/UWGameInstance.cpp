// Fill out your copyright notice in the Description page of Project Settings.


#include "UWGameInstance.h"
#include "Data/GameDataSupervisor.h"

void UUWGameInstance::Init()
{
	Super::Init();
	DataSupervisor.LoadSynchronous();
}

void UUWGameInstance::Shutdown()
{
	Super::Shutdown();
}

#if WITH_EDITOR
FGameInstancePIEResult UUWGameInstance::InitializeForPlayInEditor(int32 PIEInstanceIndex,
                                                                  const FGameInstancePIEParameters& Params)
{
	return Super::InitializeForPlayInEditor(PIEInstanceIndex, Params);
}

FGameInstancePIEResult UUWGameInstance::StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer,
	const FGameInstancePIEParameters& Params)
{
	return Super::StartPlayInEditorGameInstance(LocalPlayer, Params);
}
#endif

void UUWGameInstance::StartGameInstance()
{
	Super::StartGameInstance();
}

UGameDataSupervisor* UUWGameInstance::GetDataSupervisor() const
{
	return DataSupervisor.Get();
}
