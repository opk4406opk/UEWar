// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUnitBase.h"

#include "UEWar/InGameMode.h"
#include "UEWar/UWGameInstance.h"
#include "UEWar/Data/GameDataSupervisor.h"

// Sets default values
AGameUnitBase::AGameUnitBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	UnitType = EGameUnitType::None;
}

// Called when the game starts or when spawned
void AGameUnitBase::BeginPlay()
{
	Super::BeginPlay();
	AnimationGroup = Cast<AInGameMode>(GetWorld()->GetAuthGameMode())->GetGameInstance()->GetDataSupervisor()->GetUnitAnimGroup(UnitType);
}

// Called every frame
void AGameUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameUnitBase::PlayAnimation(EGameUnitAnimType animType) const
{
	const auto animSoftPtr = AnimationGroup->Animations.Find(animType);
	MeshComponent->PlayAnimation(animSoftPtr->LoadSynchronous(), true);
}

AGameUnitBase::~AGameUnitBase()
{
	
}

void AGameUnitBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
