// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveStateTask.h"

#include "AIController.h"
#include "MeleeAIController.h"
#include "UEWar/Unit/GameUnitBase.h"

EBTNodeResult::Type UMoveStateTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AGameUnitBase* unitBase = Cast<AMeleeAIController>(OwnerComp.GetAIOwner())->GetUnitOwner();
	unitBase->PlayAnimation(EGameUnitAnimType::Run);
	return EBTNodeResult::Succeeded;
}

void UMoveStateTask::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}

EBTNodeResult::Type UMoveStateTask::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::AbortTask(OwnerComp, NodeMemory);
	return EBTNodeResult::Aborted;
}

void UMoveStateTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

void UMoveStateTask::OnMessage(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, FName Message, int32 RequestID,
	bool bSuccess)
{
	Super::OnMessage(OwnerComp, NodeMemory, Message, RequestID, bSuccess);
}

void UMoveStateTask::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
}

UMoveStateTask::~UMoveStateTask()
{
}