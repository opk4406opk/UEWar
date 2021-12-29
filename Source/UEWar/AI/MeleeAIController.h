// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "UEWar/Unit/GameUnitBase.h"
#include "MeleeAIController.generated.h"

class UBehaviorTree;
class UBehaviorTreeComponent;
class AGameUnitBase;
/**
 * 
 */
UCLASS()
class UEWAR_API AMeleeAIController final : public AAIController
{
	GENERATED_BODY()
public:
	AMeleeAIController();
protected:
	virtual void OnPossess(APawn* InPawn) final;
	virtual void OnUnPossess() final;
public:
	virtual void SetPawn(APawn* InPawn) final;
	AGameUnitBase* GetUnitOwner() const {return OwnerUnit;}
	void StartBT();
	void StopBT();
private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UBehaviorTree> BTAsset;
	UPROPERTY(Transient)
	TObjectPtr<UBehaviorTreeComponent> BTComponent;
	UPROPERTY(Transient)
	TObjectPtr<AGameUnitBase> OwnerUnit;
};
