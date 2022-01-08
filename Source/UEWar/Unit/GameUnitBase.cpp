// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUnitBase.h"

#include "UEWar/InGameMode.h"
#include "UEWar/UWGameInstance.h"
#include "UEWar/Data/GameDataSupervisor.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"

// Sets default values
AGameUnitBase::AGameUnitBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	RootComponent = CapsuleComponent;
	
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetRelativeRotation(FRotator(0.0f, -90.0f ,0.0f));
	
	ArrowComponent = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowComponent"));
	ArrowComponent->SetupAttachment(RootComponent);

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

void AGameUnitBase::PlayAnimation(EGameUnitAnimType animType)
{
	if(IsValid(CurrentMontage) == true)
	{
	}
	
	const auto animSoftPtr = AnimationGroup->Animations.Find(animType);
	CurrentMontage = MeshComponent->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(animSoftPtr->LoadSynchronous(), TEXT("DefaultSlot"),
		0.25f, 0.25f, 1.0f, 1000, -1.0f, 0.0f);
}

AGameUnitBase::~AGameUnitBase()
{
	
}

void AGameUnitBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
