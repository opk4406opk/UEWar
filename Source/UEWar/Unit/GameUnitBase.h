// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/Pawn.h"
#include "UEWar/GameEnumClass.h"
#include "UEWar/Data/MeleeUnitDataAsset.h"
#include "GameUnitBase.generated.h"

class UArrowComponent;
class UCapsuleComponent;
class UAnimMontage;
struct FUnitAnimGroup;

UCLASS()
class UEWAR_API AGameUnitBase : public APawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	EGameUnitType GetUnitType() const {return UnitType;}
	void PlayAnimation(EGameUnitAnimType animType);
	template<typename T>
	T* GetAIController()
	{
		return Cast<T>(GetController());
	}

	virtual ~AGameUnitBase() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
protected:
	UPROPERTY(Category ="GameUnitBase_Variable", EditDefaultsOnly)
	TObjectPtr<USkeletalMeshComponent> MeshComponent;
	UPROPERTY(Category ="GameUnitBase_Variable", EditDefaultsOnly)
	TObjectPtr<UArrowComponent> ArrowComponent;
	UPROPERTY(Category ="GameUnitBase_Variable", EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(Category ="GameUnitBase_Variable",EditDefaultsOnly)
	EGameUnitType UnitType;
	TObjectPtr<FUnitAnimGroup> AnimationGroup;
	UPROPERTY(Transient)
	TObjectPtr<UAnimMontage> CurrentMontage;
};
