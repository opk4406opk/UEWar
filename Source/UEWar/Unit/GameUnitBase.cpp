// Fill out your copyright notice in the Description page of Project Settings.


#include "GameUnitBase.h"

#include "UEWar/InGameMode.h"
#include "UEWar/UWGameInstance.h"
#include "UEWar/Data/GameDataSupervisor.h"
#include "Components/ArrowComponent.h"
#include "Components/CapsuleComponent.h"
#include "UEWar/State/UnitStateManager.h"
#include "Runtime/Engine/Classes/Animation/AnimInstance.h"
#include "Runtime/Engine/Classes/Animation/AnimMontage.h"
#include "UEWar/State/UnitStateBase.h"

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
	
	StateManager = NewObject<UUnitStateManager>();
	StateManager->Init(this);
	StateManager->Change(EGameUnitState::Idle, FStateUpdateParams());

	FOnMontageBlendingOutStarted blendOut;
	blendOut.BindUObject(this, &AGameUnitBase::OnAnimationEnd);
	MeshComponent->GetAnimInstance()->Montage_SetBlendingOutDelegate(blendOut);
}

// Called every frame
void AGameUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	StateManager->TickProcess(DeltaTime);
}

void AGameUnitBase::PlayAnimation(EGameUnitAnimType animType)
{
	const auto animSoftPtr = AnimationGroup->Animations.Find(animType);
	CurrentMontage = MeshComponent->GetAnimInstance()->PlaySlotAnimationAsDynamicMontage(animSoftPtr->LoadSynchronous(), TEXT("DefaultSlot"),
		0.25f, 0.25f, 1.0f, 99999, -1.0f, 0.0f);
	
	FOnMontageEnded blendOutDelegate;
	blendOutDelegate.BindUObject(this, &AGameUnitBase::OnAnimationEnd);
	MeshComponent->GetAnimInstance()->Montage_SetBlendingOutDelegate(blendOutDelegate, CurrentMontage);
}

AGameUnitBase::~AGameUnitBase()
{
	
}

void AGameUnitBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

void AGameUnitBase::OnAnimationEnd(UAnimMontage* animMontage, bool bInterrupted)
{
	if(animMontage == CurrentMontage)
	{
		int8 tt = 0;
	}
	else
	{
		int8 t = 0;
	}
}
