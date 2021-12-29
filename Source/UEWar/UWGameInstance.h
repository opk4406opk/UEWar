// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UWGameInstance.generated.h"

class UGameDataSupervisor;
/**
 * 
 */
UCLASS()
class UEWAR_API UUWGameInstance final : public UGameInstance
{
	GENERATED_BODY()
public:
	virtual void Init() final;
	virtual void Shutdown() final;
#if WITH_EDITOR
	virtual FGameInstancePIEResult InitializeForPlayInEditor(int32 PIEInstanceIndex, const FGameInstancePIEParameters& Params) final;
	virtual FGameInstancePIEResult StartPlayInEditorGameInstance(ULocalPlayer* LocalPlayer, const FGameInstancePIEParameters& Params) final;
#endif
	virtual void StartGameInstance() final;
public:
	UGameDataSupervisor* GetDataSupervisor() const;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UGameDataSupervisor> DataSupervisor;
};
