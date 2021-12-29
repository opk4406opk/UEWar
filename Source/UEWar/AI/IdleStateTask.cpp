// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleStateTask.h"
#include "AIController.h"
#include "MeleeAIController.h"
#include "UEWar/Unit/GameUnitBase.h"

EBTNodeResult::Type UIdleStateTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	AGameUnitBase* unitBase = Cast<AMeleeAIController>(OwnerComp.GetAIOwner())->GetUnitOwner();
	unitBase->PlayAnimation(EGameUnitAnimType::Idle);
	return EBTNodeResult::Type::Succeeded;
}

EBTNodeResult::Type UIdleStateTask::AbortTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::AbortTask(OwnerComp, NodeMemory);
	
	return EBTNodeResult::Type::Aborted;
}

void UIdleStateTask::OnGameplayTaskDeactivated(UGameplayTask& Task)
{
	Super::OnGameplayTaskDeactivated(Task);
}

void UIdleStateTask::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
}

void UIdleStateTask::OnMessage(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, FName Message, int32 RequestID,
	bool bSuccess)
{
	Super::OnMessage(OwnerComp, NodeMemory, Message, RequestID, bSuccess);
}

void UIdleStateTask::OnTaskFinished(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory,
	EBTNodeResult::Type TaskResult)
{
	Super::OnTaskFinished(OwnerComp, NodeMemory, TaskResult);
}

UIdleStateTask::~UIdleStateTask()
{
}
