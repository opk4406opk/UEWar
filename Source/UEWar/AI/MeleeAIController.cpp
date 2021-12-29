// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AMeleeAIController::AMeleeAIController()
{
	BrainComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorTreeComponent"));
	BTComponent = Cast<UBehaviorTreeComponent>(BrainComponent);
}

void AMeleeAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	OwnerUnit = Cast<AGameUnitBase>(InPawn);
}

void AMeleeAIController::OnUnPossess()
{
	Super::OnUnPossess();
}

void AMeleeAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);
}

void AMeleeAIController::StartBT()
{
	BTComponent->StartTree(*BTAsset);
}

void AMeleeAIController::StopBT()
{
	BTComponent->StopTree();
}
