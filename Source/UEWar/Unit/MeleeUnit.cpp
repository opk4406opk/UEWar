// Fill out your copyright notice in the Description page of Project Settings.

#include "MeleeUnit.h"

#include "BrainComponent.h"
#include "UEWar/AI/MeleeAIController.h"

// Sets default values
AMeleeUnit::AMeleeUnit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMeleeUnit::BeginPlay()
{
	Super::BeginPlay();
	GetAIController<AMeleeAIController>()->StartBT();
}

// Called every frame
void AMeleeUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AMeleeUnit::~AMeleeUnit()
{
}

